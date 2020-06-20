#include <iostream>
#include <vector>
using namespace std;

template <typename T>
inline void printVector(const vector<T> &values)
{
    for (T v : values)
    {
        cout << v << " ";
    }
    cout << endl;
}

template <typename T>
inline void mySwap(T &a, T &b)
{
    cout << "swap -> a=" << *a << ", b=" << *b << endl;
    auto temp = *a;
    *a = *b;
    *b = temp;
}

template <typename RandomAccess>
inline RandomAccess partition(RandomAccess start, RandomAccess end)
{
    auto pivot = *(start + (end - start) / 2);
    int i = 0;
    while (true)
    {
        cout << "iter " << i << " start=" << *start << " end=" << *end << endl;
        while (*start < pivot)
        {
            cout << "while start" << endl;
            start++;
            i++;
        }
        while (*end > pivot)
        {
            cout << "while end" << endl;
            end--;
            i++;
        }
        if (start >= end)
        {
            cout << "return end" << endl;
            return end;
        }
        mySwap(start, end);
        start++;
        end--;
        i++;
    }
}

template <typename RandomAccess>
inline void hoareSort(RandomAccess start, RandomAccess end)
{
    //cout << "start: " << start << ", end: " << end << endl;
    //basecase
    if (end <= start)
        return;
    RandomAccess partitionBorder = partition(start, end);
    hoareSort(start, partitionBorder);
    hoareSort(partitionBorder + 1, end);
}

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