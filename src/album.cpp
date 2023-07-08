#include "LastFmApi.hpp"


using namespace lfapi;


string LastFmApi::getAlbumName(){
    return getXmlText(this->last_result, vector<string>{"lfm","album","name"});
}

string LastFmApi::getAlbumReleaseDate(){
    return getXmlText(this->last_result, vector<string>{"lfm","album","releasedate"});
}

string LastFmApi::getAlbumId(){
    return getXmlText(this->last_result, vector<string>{"lfm","album","id"});
}


vector<string> LastFmApi::getAlbumTopTags(){
    return topTags(this->last_album, "toptags");
}