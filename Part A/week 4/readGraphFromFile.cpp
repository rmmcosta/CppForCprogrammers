#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    cout << "what's the file name:";
    string fileName;
    cin >> fileName;
    ifstream fin(fileName);
    istream_iterator<int> start(fin), end;
    //the first integer will give us the size
    vector<int> data(start, end);
    cout << "size:" << data[0] << endl;
    for (int i = 1; i < data.size(); i += 3)
    {
        int nodeOrigin = data[i], nodeDestin = data[i + 1], cost = data[i + 2];
        cout << "(" << nodeOrigin << ", " << nodeDestin << ", " << cost << ")" << endl;
    }
    return 0;
}