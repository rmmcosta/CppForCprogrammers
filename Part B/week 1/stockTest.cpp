#include "stock.hpp"

int main()
{
    Stock s1 ("Transportadora Santana", 10, 5.3);
    cout << s1;
    s1.purchase(5);
    cout << s1;
    s1.updatePrice(7.1);
    cout << s1;
    s1.sell(15);
    cout << s1;
    cout << "can sell more? " << (s1.sell(1)?"Yes":"No") << endl;
    Stock *s2 = new Stock("Nike", 100, 15.50);
    cout << *s2;
    s2->purchase(10);
    cout << *s2;
    delete s2; //to avoid leaks we must delete s2 since we are putting s2 in the heap
    return 0;
}