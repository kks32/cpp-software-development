#include <cstdlib>
#include <iostream>


// Abstract Product: ShippingFee
class ShippingFee
{
public:
    virtual void compute() = 0;
    virtual ~ShippingFee(){}
};
 
// Concrete Product: Europe Shipping Fee
class EuropeShippingFee : public ShippingFee 
{
public:
    virtual ~EuropeShippingFee(){}
    void compute(){
        std::cout << "Europe ShippingFee: $4.99" << std::endl;
    }
};

// Concrete Product: Singapore Shipping Fee
class SingaporeShippingFee : public ShippingFee 
{
public:
    virtual ~SingaporeShippingFee(){}
    void compute(){
        std::cout << "Singapore ShippingFee $39.99" << std::endl;
    }
};

// Abstract Product: Tax
class Tax 
{
public:
    virtual void compute() = 0;
    virtual ~Tax(){}
};

// Concrete Product: Europe Tax Fee
class EuropeTax : public Tax 
{
public:
    virtual ~EuropeTax(){}
    void compute(){
        std::cout << "Europe Tax: $49.99" << std::endl;
    }
};
 
// Concrete Product: Singapore Tax Fee
class SingaporeTax : public Tax {
public:
    virtual ~SingaporeTax(){}
    void compute(){
        std::cout << "Singapore Tax $19.99" << std::endl;
    }
};

// Abstract Factory
class FinanceToolFactory 
{
public:
    virtual ~FinanceToolFactory(){}
    enum FinanceFactories {
        Europe,
        Singapore
    };
    virtual ShippingFee* calculateShippingFee() = 0;
    virtual Tax* calculateTax() = 0;
    
    static FinanceToolFactory* createFactory(std::string& country);
};

// Concrete factory: country - Europe
class EuropeFinanceFactory : public FinanceToolFactory 
{
public:
    virtual ~EuropeFinanceFactory(){}
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
    virtual ~SingaporeFinanceFactory(){}
    ShippingFee* calculateShippingFee(){
        return new SingaporeShippingFee;
    }
    Tax* calculateTax(){
        return new SingaporeTax;
    }
};


// This section is usally a c++ file for abstract factory
FinanceToolFactory* FinanceToolFactory::createFactory(std::string& country) {
    if (country == "Europe") {
        return new EuropeFinanceFactory;
    }
    else if (country == "Singapore") {
        return new SingaporeFinanceFactory;
    }
    else {
        std::cerr << "Invalid country name. Program terminating" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// Client side implementation 
int main(int argc, char* argv[]) {

    // User input
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        std::cerr << "Usage: ./factory countryname  (Europe/Singapore)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string countryname = argv[1];


    FinanceToolFactory* finance_factory = FinanceToolFactory::createFactory(countryname);
    ShippingFee* ship_fee = finance_factory->calculateShippingFee();
    ship_fee -> compute();
    delete ship_fee;
    Tax* tax = finance_factory->calculateTax();
    tax -> compute();
    delete tax;
    delete finance_factory;
    return 0;
}
