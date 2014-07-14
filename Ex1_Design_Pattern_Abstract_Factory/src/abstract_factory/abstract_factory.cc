#include <iostream>
// Using macros is bad! really bad. 
#define _SINGAPORE_

// Abstract Product: ShippingFee
class ShippingFee
{
public:
    virtual void compute() = 0;
};
 
// Concrete Product: Europe Shipping Fee
class EuropeShippingFee : public ShippingFee 
{
public:
    void compute (){
        std::cout << "Europe ShippingFee: $4.99" << std::endl;
    }
};

// Concrete Product: Singapore Shipping Fee
class SingaporeShippingFee : public ShippingFee 
{
public:
    void compute (){
        std::cout << "Singapore ShippingFee $39.99" << std::endl;
    }
};

// Abstract Product: Tax
class Tax 
{
public:
    virtual void compute() = 0;
};

// Concrete Product: Europe Tax Fee
class EuropeTax : public Tax 
{
public:
    void compute (){
        std::cout << "Europe Tax: $49.99" << std::endl;
    }
};
 
// Concrete Product: Singapore Tax Fee
class SingaporeTax : public Tax {
public:
    void compute (){
        std::cout << "Singapore Tax $19.99" << std::endl;
    }
};

// Abstract Factory
class FinanceToolFactory 
{
public:
    virtual ShippingFee* calculateShippingFee () = 0;
    virtual Tax* calculateTax () = 0;
};

// Concrete factory: country - Europe
class EuropeFinanceFactory : public FinanceToolFactory 
{
public:
    ShippingFee* calculateShippingFee (){
        return new EuropeShippingFee;
    }
    Tax* calculateTax (){
        return new EuropeTax;
    }
};
 

// Concrete factory: country - Singapore
class SingaporeFinanceFactory : public FinanceToolFactory 
{
public:
    ShippingFee* calculateShippingFee (){
        return new SingaporeShippingFee;
    }
    Tax* calculateTax (){
        return new SingaporeTax;
    }
};


// Client side implementation 
int main() {
    FinanceToolFactory* finance_factory;
    ShippingFee *ship_fee;
    Tax *tax;

#ifdef _SINGAPORE_    
    finance_factory = new SingaporeFinanceFactory;
    ship_fee = finance_factory->calculateShippingFee();
    ship_fee -> compute();
    tax = finance_factory->calculateTax();
    tax -> compute();
#else    
    finance_factory = new EuropeFinanceFactory;
    ship_fee = finance_factory->calculateShippingFee();
    ship_fee -> compute();
    tax = finance_factory->calculateTax();
    tax -> compute();
#endif    
    return 0;
}
