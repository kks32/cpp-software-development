#include <iostream>
#include <iterator>
#include <string>

#include "document.h"

Document* XmlDoc::Clone() const {
 return new XmlDoc(*this);
}

void XmlDoc::view_document() {
    std::cout<<"A new XML document"<<std::endl;
}
        
Document* PlainDoc::Clone() const { 
    return new PlainDoc(*this);
}

void PlainDoc::view_document() {
    std::cout<<"A new blank document"<<std::endl;
}
   
Document* SpreadSheet::Clone() const { 
    return new SpreadSheet(*this);
}

void SpreadSheet::view_document() {
    std::cout<<"A new spreadsheet"<<std::endl;
}

std::map<std::string,Document*> DocumentFactory::m_map= std::map<std::string,Document*>();

void DocumentFactory::Register(const std::string& key,Document* obj) {
    // if the key is not already present
    if(m_map.find(key)==m_map.end()) {
        // is added in the object map
        m_map[key]=obj;
    }
}

Document* DocumentFactory::Create(const std::string& key) const {
    Document* tmp=0;
    std::map<std::string, Document*>::const_iterator it=m_map.find(key);
    
    // If the iterator is not map.end (), it means that the key has been found
    if(it!=m_map.end()) {
        tmp=((*it).second)->Clone();
    }

    // could launch an exeption if the key was not found
    
    return tmp;
}

int main(int argc, char** argv) {
    // Documet factory
    DocumentFactory fac;
    
    // Register the types
    DocumentFactory::Register("XmlDoc",new XmlDoc);
    DocumentFactory::Register("PlainDoc",new PlainDoc);
    DocumentFactory::Register("SpreadSheet",new SpreadSheet);
    
    // Objects are created via the factory
    Document* doc = fac.Create("PlainDoc");
    Document* xml = fac.Create("XmlDoc");
    Document* xls =fac.Create("SpreadSheet");

    doc->view_document();
    xml->view_document();
    xls->view_document();    

    delete doc;
    delete xml;
    delete xls;

    return 0;
}
