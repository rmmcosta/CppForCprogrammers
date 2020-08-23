#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string filenames[] = {"coiso.txt", "cen3s.txt", "etal.pdf", "Myfile.txt", "Z.pdf", "ARdx.pdf", "Alt.pdf", "cenas.txt1"};
    regex mr("[a-z]+\\.txt");
    for (string s : filenames)
        if (regex_match(s, mr))
            cout << s << endl;
    regex mr2("^[A-Z]{1}[a-z]*\\.pdf$");
    for (string s : filenames)
        if (regex_match(s, mr2))
            cout << s << endl;
}