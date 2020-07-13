#include "cppunit.hpp"
#include <iostream>

int main()
{
    vector<int> ints = {2, 3, 4};
    bool result = assertThat(ints, {2, 3, 4});
    cout << result << endl;
    return 0;
}