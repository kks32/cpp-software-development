#include <iostream>
#define _SINGAPORE_

// finance
class Finance
{
public:
    virtual void compute() = 0;
};
 
// Europe Shipping Fee
class EuropeShippingFee : public Finance
{
public:
    void compute(){
        std::cout << "Europe ShippingFee: $4.99" << std::endl;
    }
};

// Singapore Shipping Fee
class SingaporeShippingFee : public Finance
{
public:
    void compute(){
        std::cout << "Singapore ShippingFee $39.99" << std::endl;
    }
};


// Europe Tax Fee
class EuropeTax : public Finance
{
public:
    void compute(){
        std::cout << "Europe Tax: $49.99" << std::endl;
    }
};
 
// Singapore Tax Fee
class SingaporeTax : public Finance
{
public:
    void compute (){
        std::cout << "Singapore Tax $19.99" << std::endl;
    }
};


void display_finance() {
#ifdef _SINGAPORE_
   Finance* fcountry[] = { new SingaporeShippingFee,
                           new SingaporeTax };
#else //Europe
   Finance* fcountry[] = { new EuropeShippingFee,
                           new EuropeTax};
#endif
   fcountry[0]->compute();  //Shipping fee
   fcountry[1]->compute();  //Tax
}


// Client side implementation 
int main() {
    display_finance();
    return 0;
}
