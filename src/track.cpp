#include "LastFmApi.hpp"


using namespace lfapi;


string LastFmApi::getTrackInfo(string track_name, string artist){
    string url = "https://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key="+this->key+"&artist="+artist+"&track="+track_name;
    string str_xml = httpGet(url);
    this->last_result = str_xml;
    return str_xml;
}

/*
    streamable:
    artist:
    alblum:
    toptags:
    wiki:
    */
vector<string> LastFmApi::getTopTags(){
    return topTags(this->last_result, "toptags");
}

// string LastFmApi::getName(){
//     string xml = this->last_result;
//     string title = "";
//     tinyxml2::XMLDocument doc;
//     doc.Parse(xml.c_str());
//     title = doc.FirstChildElement("lfm")->FirstChildElement("track")->FirstChildElement("name")->GetText();
    
//     return title;
// }

string LastFmApi::getName(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","name"});
}

string LastFmApi::getMbid(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","mbid"});
}

string LastFmApi::getUrl(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","url"});
}

string LastFmApi::getDuration(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","duration"});
}

string LastFmApi::getListeners(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","listeners"});
}

string LastFmApi::getPlaycount(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","playcount"});
}

string LastFmApi::getTrackArtist(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","artist","name"});
}

string LastFmApi::getTrackAlbum(){
    return getXmlText(this->last_result, vector<string>{"lfm","track","album","title"});
}

string LastFmApi::getTrackAlbumPosition(){
    return getXmlAttribute(this->last_result, vector<string>{"lfm","track","album","position"});
}