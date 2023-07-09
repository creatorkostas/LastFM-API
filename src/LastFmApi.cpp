#include "LastFmApi.hpp"


using namespace lfapi;

vector<string> LastFmApi::topTags(string tags_xml, string tag_name){
    string xml = tags_xml;

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    
    return tagsSeperator(doc.FirstChildElement("lfm")->FirstChildElement(tag_name.c_str()));
}


vector<string> LastFmApi::tagsSeperator(tinyxml2::XMLDocument tags){
    vector<string> top_tags;
    // tinyxml2::XMLElement *tags = doc.FirstChildElement("toptags");
    for (tinyxml2::XMLElement* child = tags.FirstChildElement(); child != NULL; child = child->NextSiblingElement())
    {
        top_tags.push_back( child->FirstChildElement("name")->GetText() );
    }

    return top_tags;
}


string LastFmApi::getXmlText(string xml, vector<string> tags){
    string text = "";

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* elem;

    doc.Parse(xml.c_str());
    int depth = tags.size();
    int current_depth = 0;
    for(string tag: tags){

        current_depth++;
        // cout << "1" << endl;
        // cout << tag << " " << current_depth << " " << depth << endl;
        if(current_depth == 1) {elem = doc.FirstChildElement(tag.c_str())->ToElement(); continue;}
        if(current_depth == depth) text = elem->FirstChildElement(tag.c_str())->GetText();
        else elem = elem->FirstChildElement(tag.c_str());
        
// cout << elem->FirstChildElement(tag.c_str())->GetText() << endl;
    }
        
    
    return text;
}

string LastFmApi::getXmlAttribute(string xml, vector<string> tags){
    string text = "";

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* elem;

    doc.Parse(xml.c_str());

    int depth = tags.size();
    int current_depth = 0;


    for(string tag: tags){

        current_depth++;
        if(current_depth == 1) {elem = doc.FirstChildElement(tag.c_str())->ToElement(); continue;}
        if(current_depth == depth) text = elem->Attribute(tag.c_str());
        else elem = elem->FirstChildElement(tag.c_str());
        
    }
    
    return text;
}