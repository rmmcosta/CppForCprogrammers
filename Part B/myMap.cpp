#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

string removeNonAlpha(const string &s)
{
    string result;
    for (char c:s)
    {
        if(isalpha(c))
        {
            result+=c;
        }
    }
    return result;
}

int main()
{
    cout << "what's the file name? ";
    string fileName;
    cin >> fileName;
    cout << endl;
    ifstream fin(fileName);
    istream_iterator<string> start(fin), end;
    vector<string> words(start, end);
    fin.close();
    map<string, int> wordsCount;
    for (string s : words)
    {
        // cout << s << endl;
        //exist word in map?
        if (wordsCount.find(removeNonAlpha(s)) != wordsCount.end())
        {
            ++wordsCount.find(removeNonAlpha(s))->second;
        }
        else
        {
            wordsCount.insert(pair<string, int>(removeNonAlpha(s), 1));
        }
    }
    for(auto pair: wordsCount)
    {
        cout << "word: " << pair.first << ", occurrences: " << pair.second << endl;
    }
    // words.clear();
    // wordsCount.clear();
    return 0;
}