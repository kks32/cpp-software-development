//fichier prototypetpl.h

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>
#include <memory>

template <class T> class Prototype
{
public:
    virtual ~Prototype(){}        
    virtual std::unique_ptr<T> Clone() const =0 ;
};

class MySQLManager : public Prototype<MySQLManager>
{

    std::string m_host,m_login,m_pass;
    std::string m_base,m_table;

public:
    MySQLManager(const std::string host="",const std::string login="",const std::string pass="");        
        
    void Display() const ;        
    std::unique_ptr<MySQLManager> Clone() const ;
    //  void Set(const std::string base="",const std::string table=""); 
};

#endif
