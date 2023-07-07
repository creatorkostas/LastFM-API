#pragma once
#include <string>
#include "utils.hpp"
#include <tinyxml2.h>

namespace lfapi
{
    using namespace std;
    class LastFmApi
    {
    private:
        string key;
        string last_result;
    public:
        LastFmApi(string key);
        ~LastFmApi();
        string getTrackInfo(string TrackName, string artist);

        string getName();
        string getMbid();
        string getUrl();
        string getDuration();
        string getListeners();
        string getPlaycount();
    };
    
    LastFmApi::LastFmApi(string key)
    {
        this->key = key;
    }
    
    LastFmApi::~LastFmApi()
    {
        // delete *this->*key;
    }
    
} // namespace lfapi
