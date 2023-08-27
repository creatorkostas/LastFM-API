#pragma once
// #include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

static size_t writeToString(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    std::string *str = static_cast<std::string*>(userp);
    str->append(static_cast<char*>(data), realsize);
    return realsize;
}

string httpGet(string url, string user_agent = "", vector<string> string_headers = {}, bool set_host = false){
    CURL *curl;
    CURLcode res;
    string respStr;

    curl_global_init(CURL_GLOBAL_DEFAULT);
 
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    
        /* cache the CA cert bundle in memory for a week */
        curl_easy_setopt(curl, CURLOPT_CA_CACHE_TIMEOUT, 604800L);
    
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeToString);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &respStr);
        /* Perform the request, res will get the return code */

        if(set_host){
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }

        if(user_agent != ""){
            curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent);
        }

        if(string_headers.size() != 0){
            struct curl_slist *headers = NULL;
            for(string header: string_headers){
                headers = curl_slist_append(headers, header.c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }


        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK)
          fprintf(stderr, "An error occurred: %s\n",
                  curl_easy_strerror(res));
    
        /* always cleanup */
        // cout << respStr ;
        curl_easy_cleanup(curl);
    }
 
    curl_global_cleanup();

    return respStr;
}