#include <stdio.h>
#include <iostream>
#include <string>
#include "includes.hpp"

bool test_basic_info(string key){
    bool status1 = false;
    bool status2 = false;
    lfapi::LastFmApi fm(key);
    fm.getTrackInfo("believe","cher");
    string name = fm.getName();
    string mbid = fm.getMbid();
    string duration = fm.getDuration();
    string listeners = fm.getListeners();
    string playcount = fm.getPlaycount();
    string url = fm.getUrl();

    string true_name = "Believe";
    string true_mbid = "32ca187e-ee25-4f18-b7d0-3b6713f24635";
    string true_duration = "236000";
    string true_url = "https://www.last.fm/music/Cher/_/Believe";

    // string test_playcount = "4085213";

    if(atoi(listeners.c_str()) >= 0 && atoi(playcount.c_str()) >= 4085213/*test_playcount*/) status1 = true;
    if(
        name == true_name &&
        mbid == true_mbid &&
        duration == true_duration &&
        url == true_url
    ) status2 = true;

    // fm.~LastFmApi();

    if (status1 && status2) return true;
    else return false; 
}

int main(void)
{ 
    string key;
    cout << "Api key : ";
    cin >> key;
    bool Basic_Info_Test = test_basic_info(key);
    if (Basic_Info_Test)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }
    

    // lfapi::LastFmApi fm(key);

    // string searched_result = fm.TrackSearch("believe");
    // vector<tinyxml2::XMLElement*> l = fm.getXmlList(searched_result, vector<string>{"lfm", "results", "trackmatches", "track"});


    //     // cout << searched_result << endl ;
    //     cout << "----------------" << endl ;
    //     cout << l.size() << endl ;
    //     cout << l[0]->FirstChildElement("name")->GetText() << endl;
    //     cout << "----------------" << endl ;
    // for(int i=0;i<l.size();i++){
    //     cout << i << ":" ;
        
    //     cout << l[i]->FirstChildElement("name")->GetText() << " : " << l[i]->FirstChildElement("artist")->GetText() << endl;
    // } 
    //     cout << "----------------" << endl ;
    
    return 0;
}
