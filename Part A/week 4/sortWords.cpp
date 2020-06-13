#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

void mySort(vector<string> &words)
{
    bool hasSwap;
    do
    {
        hasSwap = false;
        for (int i = 1; i < words.size(); i++)
        {
            // cout << "curr first letter:" << words[i].at(0)
            //      << "prev first letter:" << words[i - 1].at(0) << endl;
            int minSize = words[i].size() < words[i - 1].size() ? words[i].size() : words[i - 1].size();
            for (int j = 0; j < minSize; j++)
            {
                cout << words[i].at(j) << ":" << words[i - 1].at(j) << endl;
                if (words[i].at(j) == words[i - 1].at(j))
                {
                    cout << "continue" << endl;
                    continue;
                }
                if (words[i].at(j) < words[i - 1].at(j))
                {
                    hasSwap = true;
                    string temp = words[i];
                    words[i] = words[i - 1];
                    words[i - 1] = temp;
                    cout << "is less" << endl;
                    break;
                }
                break;
            }
        }
    } while (hasSwap);
}

int main()
{
    string fileName;
    cout << "What is the file:";
    cin >> fileName;
    fstream fin(fileName);
    istream_iterator<string> start(fin), end;
    vector<string> words(start, end);
    for (auto it = words.begin(); it != words.end(); it++)
    {
        cout << *it << endl;
    }
    mySort(words);
    for (string word : words)
    {
        cout << word << endl;
    }
    return 0;
}