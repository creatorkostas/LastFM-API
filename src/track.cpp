#include "LastFmApi.hpp"


using namespace lfapi;

string LastFmApi::getTrackInfo(string TrackName, string artist){
    string url = "https://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key="+this->key+"&artist="+artist+"&track="+TrackName;
    string str_xml = httpGet(url);
    this->last_result = str_xml;
    return str_xml;
}

// string LastFmApi::getTrackInfo(vector<tinyxml2::XMLDocument> xml, int pos){
//     if (searchResultsNumber(xml) == 0) return "No results";

//     vector<string> info = getSearchInfo(xml, pos);
//     return getTrackInfo(info.at(0), info.at(1));
// }

// string LastFmApi::getTrackInfo(string TrackName, int pos){
//     string search = TrackSearch(TrackName);
//     vector<tinyxml2::XMLDocument> list = getXmlList(search, vector<string>{"results", "trackmatches", "track"});
    
//     if (searchResultsNumber(list) == 0) return "No results";

//     vector<string> info = getSearchInfo(list, pos);
//     return getTrackInfo(info.at(0), info.at(1));

// }

// string LastFmApi::getTrackInfo(string TrackName){
//     return getTrackInfo(TrackName, 0);
// }

int LastFmApi::searchResultsNumber(vector<tinyxml2::XMLDocument> xml){
    return (int)xml.size();
}

vector<string> LastFmApi::getSearchInfo(vector<tinyxml2::XMLDocument> xml, int pos){
    string str_xml = xml.at(pos).ToText()->Value(); 
    string name = "";
    string artist = "";
    name = getXmlText(str_xml, vector<string>{"track","name"});
    artist = getXmlText(str_xml, vector<string>{"track","artist"});
    return vector<string>{name, artist};
}

string LastFmApi::TrackSearch(string TrackName){
    string url = "https://ws.audioscrobbler.com/2.0/?method=track.search&track="+TrackName+"&api_key="+this->key;
    string xml_results = httpGet(url);
    return xml_results;
}

string LastFmApi::getTrackInfoByMbid(string TrackMbid){
    string url = "https://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key="+this->key+"&mbid="+TrackMbid;
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