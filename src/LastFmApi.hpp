#pragma once
#include <string>
#include <vector>
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
        string last_artist;
        string last_album;
        vector<string> tagsSeperator(tinyxml2::XMLDocument doc);
        vector<string> topTags(string tags_xml, string tag_name);
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
        vector<string> getTopTags();
        
        string getArtistByMbid(string mbid);
        string getArtistName();
        vector<string> getArtistTopTags();

        string getAlbumByMbid(string mbid);
        string getAlbumName();
        string getAlbumReleaseDate();
        string getAlbumId();
        vector<string> getAlbumTopTags();
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
