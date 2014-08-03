#include <iostream>
#include <memory>
#include "prototype.h"

 MySQLManager::MySQLManager(const std::string& host,const std::string& login,const std::string& pass): m_host(host),m_login(login),m_pass(pass) {
// // we connect to the MySQL database.
// // this takes time because you need to connect and identify.
// // Heavy.
 }

std::unique_ptr<MySQLManager> MySQLManager::Clone() const 
{
    return std::unique_ptr<MySQLManager>(new MySQLManager(*this));
} 

// void MySQLManager::Set(const std::string& base,const std::string& table) {
//     m_base=base;
//     m_table=table;
// // we connect to the m_base basis for studying m_table
// }

void MySQLManager::Display() const {
    std::cout<<m_host<<"|"<<m_login<<"|"<<m_host<<"|"<<m_pass<<"|"<<m_base<<"|"<<m_table<<std::endl;
}

int main(void)
{
        MySQLManager manager1("localhost","Krishna","password");

//        manager1.Set("fakedb","table1");
// here manager1 is connected to localhost with id Krishna on table1 table faussebasse        
        manager1.Display();

        // Now we have to work in parallel on table2 always fakedb2 on localhost.
        // so we create another manager retrieves it with a std::unique_ptr to avoid memory management in case of problems.
        std::unique_ptr<MySQLManager> manager2(manager1.Clone());
        // and here manager2 is already connected to localhost with id Krishna.Pas need to reauthenticate.
        manager2->Display();        
        //      manager2->Set("fakedb2","table2");
        manager2->Display();

        // so on

        return 0;
}
