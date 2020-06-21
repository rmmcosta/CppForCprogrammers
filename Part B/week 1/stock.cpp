#include "stock.hpp"

double Stock::getBalance()
{
    return qty * price;
}

void Stock::purchase(int qty)
{
    this->qty += qty;
}

bool Stock::sell(int qty)
{
    if (this->qty >= qty)
    {
        this->qty -= qty;
        return true;
    }
    else
    {
        return false;
    }
}

void Stock::updatePrice(double newPrice)
{
    this->price = newPrice;
}

ostream &operator<<(ostream &out, Stock &s)
{
    out << "--------------------" << endl;
    out << " " << s.name << endl;
    out << " qty = " << s.qty << endl;
    out << " price = " << s.price << "€" << endl;
    out << " balance = " << s.getBalance() << "€" << endl;
    out << "--------------------" << endl;
    return out;
}

Stock::~Stock()
{
    //do nothing at the moment
}