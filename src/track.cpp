#include "LastFmApi.hpp"


using namespace lfapi;


string LastFmApi::getTrackInfo(string track_name, string artist){
    string url = "https://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key="+this->key+"&artist="+artist+"&track="+track_name;
    string str_xml = httpGet(url);
    this->last_result = str_xml;
    return str_xml;
}

string LastFmApi::getName(){
    string xml = this->last_result;
    string title = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    title = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("name")->GetText();
    /*
    streamable:
    artist:
    alblum:
    toptags:
    wiki:
    */
    return title;
}


string LastFmApi::getMbid(){
    string xml = this->last_result;
    string mbid = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    mbid = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("mbid")->GetText();
    return mbid;
}

string LastFmApi::getUrl(){
    string xml = this->last_result;
    string url = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    url = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("url")->GetText();
    return url;
}

string LastFmApi::getDuration(){
    string xml = this->last_result;
    string duration = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    duration = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("duration")->GetText();
    return duration;
}

string LastFmApi::getListeners(){
    string xml = this->last_result;
    string listeners = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    listeners = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("listeners")->GetText();
    return listeners;
}

string LastFmApi::getPlaycount(){
    string xml = this->last_result;
    string playcount = "";
    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    playcount = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("playcount")->GetText();
    return playcount;
}

vector<string> LastFmApi::getTopTags(){
    return topTags(this->last_result, "toptags");
}