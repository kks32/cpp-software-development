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
template <class Object,class Key=std::string> class Factory
{
      static std::map<Key,Object*> m_map;
public:
      static void Register(Key key,Object* obj);
      Object* Create(const Key& key);
};


#endif // _DOCUMENT_H_
