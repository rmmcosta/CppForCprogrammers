#include <iostream>
void print();
int main()
{
    print();

    return 0;
}

void print()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j==1)
            {
                std::cout << i << "," << j << std::endl;
                return;
            }
        }

    }
}