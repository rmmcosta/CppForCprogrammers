#include "tree.hpp"

int main()
{
    valtab['A'] = 3;
    valtab['B'] = 4;
    cout << "A = 3, B = 4" << endl;
    Tree t1 = Tree("*",Tree("-",5),Tree("+",'A',4));
    
}