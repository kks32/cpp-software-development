#include <iostream>
#include <iterator>
#include <string>

#include "document.h"

using namespace std;

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

template <class Object,class Key> std::map<Key,Object*> Factory<Object,Key>::m_map=std::map<Key,Object*>();

template <class Object,class Key> void Factory<Object,Key>::Register(Key key,Object* obj) {
    if(m_map.find(key)==m_map.end()) {
        m_map[key]=obj;
    }
}

template <class Object,class Key> Object* Factory<Object,Key>::Create (const Key& key) {
    Object* tmp=0;
    typename std::map<Key, Object*>::iterator it=m_map.find(key);
    
    if(it!=m_map.end()) {
        tmp=((*it).second)->Clone();
    }
    
    return tmp;
}

int main(int argc, char** argv) {
    // Document factory
    Factory<Document> documentfactory;
    
    // Register the types
    Factory<Document>::Register("XML",new XmlDoc);
    Factory<Document>::Register("DOC",new PlainDoc);
    Factory<Document>::Register("XLS",new SpreadSheet);

   // User input
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        std::cerr << "Usage: ./document-generator  (XML/DOC/XLS)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string documenttype = argv[1];

    
    // Objects are created via the factory

    Document* doc = documentfactory.Create(documenttype);

    doc->view_document();

    delete doc;

    return 0;
}
