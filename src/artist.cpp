#include "LastFmApi.hpp"


using namespace lfapi;


string LastFmApi::getArtistByMbid(string mbid){
    string xml = httpGet("https://ws.audioscrobbler.com/2.0/?method=artist.getinfo&mbid="+mbid+"&api_key="+this->key);
    this->last_artist = xml;
    return xml;
}

string LastFmApi::getArtistName(){
    string xml = this->last_artist;
    string name = "";

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    name = doc.FirstChildElement("lfm")->FirstChildElement("artist")->FirstChildElement("name")->GetText();

    return name;
}

vector<string> LastFmApi::getArtistTopTags(){
    return topTags(this->last_artist, "tags");
}