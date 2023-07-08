#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "utils.hpp"
#include <tinyxml2.h>

namespace lfapi
{
    using namespace std;
    class LastFmApi
    {
    private:
        //API key
        string key;

        //Some values for less api calls
        string last_result;
        string last_artist;
        string last_album;

        //Tag related functon
        vector<string> tagsSeperator(tinyxml2::XMLDocument doc);
        vector<string> topTags(string tags_xml, string tag_name);

        //Xml related functon
        string getXmlText(string xml, vector<string> tags);
        string getXmlAttribute(string xml, vector<string> tags);
    public:
        LastFmApi(string key);
        ~LastFmApi();

        //Get the track info and set it to get the other info
        string getTrackInfo(string TrackName, string artist);

        string getName();
        string getMbid();
        string getUrl();
        string getDuration();
        string getListeners();
        string getPlaycount();
        string getTrackArtist();
        string getTrackAlbum();
        string getTrackAlbumPosition();
        vector<string> getTopTags();
        
        //Get the artist info and set it to get the other info
        string getArtistByMbid(string mbid);

        string getArtistName();
        vector<string> getArtistTopTags();

        //Get the almum info and set it to get the other info
        string getAlbumByMbid(string mbid);

        string getAlbumName();
        string getAlbumReleaseDate();
        string getAlbumId();
        vector<string> getAlbumTopTags();
    };
    
    LastFmApi::LastFmApi(string key){}
    
    LastFmApi::~LastFmApi(){}
    
}
