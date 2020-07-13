#include "cppunit.hpp"
#include <iostream>

bool assertThat(const vector<int> &expectedVector, const vector<int> &actualVector)
{
    if (expectedVector.size() != actualVector.size())
        return false;
    for (int i = 0; i < expectedVector.size(); i++)
        if (expectedVector[i] != actualVector[i])
            return false;
    return true;
}