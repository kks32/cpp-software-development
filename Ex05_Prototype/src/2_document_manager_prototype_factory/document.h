#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <map>
#include <string>

// Prototype class
template <class T> class Prototype 
{
public:
    virtual ~Prototype(){}        
    virtual T* Clone() const =0 ;
};

// Interface to document
class Document : public  Prototype<Document>
{
public: 
    virtual void view_document()=0;
};

class XmlDoc : public Document 
{
public:
    Document* Clone() const;
    void view_document();
    
};


class PlainDoc : public Document 
{
public:
    Document* Clone() const ;
    void view_document();
};

class SpreadSheet : public Document 
{
public:
    Document* Clone() const ;
    void view_document();
};

// Document Factory
class DocumentFactory 
{
public:
    static std::map<std::string,Document*> m_map;
    
public:
    // Function that combines 'key' <=> prototype
    static void Register(const std::string& key,Document* obj);
    
    // This creates the objects
    Document* Create(const std::string& key) const;
};
#endif // _DOCUMENT_H_
