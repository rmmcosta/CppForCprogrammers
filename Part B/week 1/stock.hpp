#include <iostream>
#include <string>
using namespace std;

//include guards
#ifndef STOCK_HPP
#define STOCK_HPP

class Stock
{
public:
    Stock(string name, int qty, double price) : name(name), qty(qty), price(price) {}
    double  getBalance();
    void updatePrice(double);
    void purchase(int);
    bool sell(int);
    friend ostream &operator<<(ostream &out, Stock &s);
    ~Stock();
private:
    string name;
    int qty;
    double price;
};

#endif