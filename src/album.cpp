#include "LastFmApi.hpp"


using namespace lfapi;

string LastFmApi::getAlbumName(){
    string xml = this->last_album;
    string name = "";

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    name = doc.FirstChildElement("lfm")->FirstChildElement("album")->FirstChildElement("name")->GetText();

    return name;
}

string LastFmApi::getAlbumReleaseDate(){
    string xml = this->last_album;
    string releasedate = "";

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    releasedate = doc.FirstChildElement("lfm")->FirstChildElement("album")->FirstChildElement("releasedate")->GetText();

    return releasedate;
}

string LastFmApi::getAlbumId(){
    string xml = this->last_album;
    string id = "";

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    id = doc.FirstChildElement("lfm")->FirstChildElement("album")->FirstChildElement("id")->GetText();

    return id;
}

vector<string> LastFmApi::getAlbumTopTags(){
    return topTags(this->last_album, "toptags");
}