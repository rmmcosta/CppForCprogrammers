#include <vector>
using namespace std;

#ifndef HOARE_QUICKSORT_HPP
#define HOARE_QUICKSORT_HPP

template <typename T>
inline void printVector(const vector<T> &);

template <typename T>
inline void mySwap(T &, T &);

template <typename RandomAccess>
inline RandomAccess partition(RandomAccess, RandomAccess);

template <typename RandomAccess>
inline void hoareSort(RandomAccess, RandomAccess);

#endif