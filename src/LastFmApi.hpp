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
        string getXmlAttribute(string xml, vector<string> tags);
    public:
        string getXmlText(string xml, vector<string> tags);
        vector<tinyxml2::XMLElement*> getXmlList(string xml, vector<string> tags );
        LastFmApi(string key);
        ~LastFmApi();


        string TrackSearch(string TrackName);
        int searchResultsNumber(vector<tinyxml2::XMLDocument> xml);
        vector<string> getSearchInfo(vector<tinyxml2::XMLDocument> xml, int pos);

        string getFirstTrack(string TrackName);

        //Get the track info and set it to get the other info
        string getTrackInfo(string TrackName, string artist);
        string getTrackInfo(string TrackName, int pos);
        string getTrackInfo(vector<tinyxml2::XMLDocument> xml, int pos);
        string getTrackInfo(string TrackName);

        string getTrackInfoByMbid(string TrackMbid);

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
    
    LastFmApi::LastFmApi(string key){this->key = key;}
    
    LastFmApi::~LastFmApi(){}
    
}
