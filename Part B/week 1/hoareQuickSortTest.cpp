#include "hoareQuickSort.cpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "how many numbers do you want to input? ";
    int count;
    cin >> count;
    vector<int> nums;
    for (int i = 0; i < count; i++)
    {
        cout << endl
             << "please input number " << i << ": ";
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    printVector(nums);
    hoareSort(nums.begin(), nums.end()-1);
    printVector(nums);
    nums.clear();
    cout << "how many characters? ";
    cin >> count;
    vector<char> phrase(count);
    for (int i = 0; i < count; i++)
    {
        cout << "char " << i << ": ";
        cin >> phrase[i];
        cout << endl;
    }
    printVector(phrase);
    cout << "sorting..." << endl;
    hoareSort(phrase.begin(), phrase.end()-1);
    printVector(phrase);
    return 0;
}