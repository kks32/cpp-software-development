
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>

class Prototype
{
        public:
        virtual ~Prototype();        
        virtual Prototype* Clone() const  = 0;
};

class MySQLManager: public Prototype
{
std::string m_host,m_login,m_pass;
std::string m_base,m_table;
public:
         MySQLManager(const std::string& host="",const std::string& login="",const std::string& pass="");
         MySQLManager* Clone() const;

         void Display() const;
         void Set(const std::string& base="",const std::string& table=""); 
};

#endif
