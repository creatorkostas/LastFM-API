#include "LastFmApi.hpp"


using namespace lfapi;

vector<string> LastFmApi::topTags(string tags_xml, string tag_name){
    string xml = tags_xml;

    tinyxml2::XMLDocument doc;
    doc.Parse(xml.c_str());
    return LastFmApi::tagsSeperator(doc.FirstChildElement("lfm")->FirstChildElement(tag_name.c_str())->ToDocument());
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

vector<tinyxml2::XMLElement*> LastFmApi::getXmlList(string xml, vector<string> tags ) {
    vector<tinyxml2::XMLElement*> list;

    // doc must be a pointer else when the function ends it is deleted and the element in the list because there are pointers
    // there point into nothing
    tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();

    tinyxml2::XMLElement* elem;
    tinyxml2::XMLElement* last_elem;

    doc->Parse(xml.c_str());

    int depth = tags.size();
    int current_depth = 0;

    string final_tag = tags.at(depth-1);
    tags.erase(tags.cend());
    
    //go to the tag which the list is
    if (tags.size() != 0){
        for(string tag: tags){

            current_depth++;
            if(current_depth == 1) {elem = doc->FirstChildElement(tag.c_str());}
            else elem = elem->FirstChildElement(tag.c_str());
            
        }

        // cout << "went to position" << endl;
        // get all the list elements
        last_elem = elem->LastChildElement();
        elem = elem->FirstChildElement(final_tag.c_str());
        while (!elem->NoChildren())
        {
            
            list.push_back(elem);
            // cout << elem->FirstChildElement("name")->GetText() << endl;
            if (elem == last_elem) break;
            else elem = elem->NextSiblingElement();
        }
        
    }else{
        //TODO error 
    }
    // cout << "Done" << endl;
    return list;
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
        if(current_depth == 1) elem = doc.FirstChildElement(tag.c_str())->ToElement();
        if(current_depth == depth) text = elem->FirstChildElement(tag.c_str())->GetText();
        else if (current_depth != 1) elem = elem->FirstChildElement(tag.c_str());
        
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
        if(current_depth == 1) elem = doc.FirstChildElement(tag.c_str())->ToElement();
        if(current_depth == depth) text = elem->Attribute(tag.c_str());
        else if (current_depth != 1) elem = elem->FirstChildElement(tag.c_str());
        
    }
    
    return text;
}