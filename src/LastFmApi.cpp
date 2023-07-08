#include "LastFmApi.hpp"


using namespace lfapi;

vector<string> LastFmApi::topTags(string tags_xml, string tag_name){
    string xml = tags_xml;

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    
    return tagsSeperator(doc.FirstChildElement("lfm")->FirstChildElement(tag_name.c_str()));
}


vector<string> tagsSeperator(tinyxml2::XMLDocument tags){
    vector<string> top_tags;
    // tinyxml2::XMLElement *tags = doc.FirstChildElement("toptags");
    for (tinyxml2::XMLElement* child = tags.FirstChildElement(); child != NULL; child = child->NextSiblingElement())
    {
        top_tags.push_back( child->FirstChildElement("name")->GetText() );
    }

    return top_tags;
}
