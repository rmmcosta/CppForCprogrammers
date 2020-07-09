#include "dog.hpp"
#include <vector>

void move(Animal &);
void move(Dog &);

int main()
{
    Dog d1("Pastor Alemão", "Jack", 4);
    d1.bark();
    cout << d1;
    cout << d1.count << endl;
    Dog d2("Shi poo", "Freddy", 3);
    cout << d2;
    d2.bark();
    cout << d2.count << endl;
    cout << "move your dog ass d2" << endl;
    move(d2);
    Animal aDog(d2);
    cout << "a dog like an animal" << endl;
    move(aDog);
    vector<Animal *> animals;
    animals.push_back(new Dog("Pug", "Shinoka", 1));
    animals.push_back(new Animal("Animal", "Unknown", 5));
    cout << "now a iterate over animals" << endl;
    for (auto iter = animals.begin(); iter != animals.end(); iter++)
    {
        (*iter)->walk();
        Position aPos = (*iter)->getPosition();
        cout << "animal position " << aPos << endl;
    }
    //virtual function when used with pointer allows to call the correct method
    //even if an upcast occurred
    return 0;
}

void move(Animal &a)
{
    cout << "move called for " << a << endl;
    a.walk();
    Position aPos = a.getPosition();
    cout << "animal position " << aPos << endl;
}

void move(Dog &a)
{
    cout << "move called for " << a << endl;
    a.walk();
    Position aPos = a.getPosition();
    cout << "animal position " << aPos << endl;
}