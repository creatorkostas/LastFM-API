#include "LastFmApi.hpp"


using namespace lfapi;


string LastFmApi::getArtistByMbid(string mbid){
    string xml = httpGet("https://ws.audioscrobbler.com/2.0/?method=artist.getinfo&mbid="+mbid+"&api_key="+this->key);
    this->last_artist = xml;
    return xml;
}

string LastFmApi::getArtistName(){
    return getXmlText(this->last_result, vector<string>{"lfm","artist","name"});
}

vector<string> LastFmApi::getArtistTopTags(){
    return topTags(this->last_artist, "tags");
}