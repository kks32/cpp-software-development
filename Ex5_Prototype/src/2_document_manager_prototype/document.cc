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
    //si la clé n'est pas déjà présente
    if(m_map.find(key)==m_map.end()) {
        //on ajoute l'objet dans la map
        m_map[key]=obj;
    }
    
    //on pourrait détruire obj mais cette tâche ne revient pas à Register
}

Document* DocumentFactory::Create(const std::string& key) const {
    Document* tmp=0;
    std::map<std::string, Document*>::const_iterator it=m_map.find(key);
    
    //si l'itérateur ne vaut pas map.end(), cela signifie que que la clé à été trouvée
    if(it!=m_map.end()) {
        tmp=((*it).second)->Clone();
    }

    //on pourrait lancer une exeption si la clé n'a pas été trouvée
    
    return tmp;
}

int main(int argc, char** argv) {
    //notre fabrique
    DocumentFactory fac;
    
    //on enregistre des types
    DocumentFactory::Register("XmlDoc",new XmlDoc);
    DocumentFactory::Register("PlainDoc",new PlainDoc);
    DocumentFactory::Register("SpreadSheet",new SpreadSheet);
    
    //on crée des objets via la fabrique
    Document *c=fac.Create("PlainDoc");
    Document *ca=fac.Create("XmlDoc");
    Document *c1=fac.Create("SpreadSheet");

    c->view_document();
    ca->view_document();
    c1->view_document();    

    delete c;
    delete ca;
    delete c1;

    return 0;
}
