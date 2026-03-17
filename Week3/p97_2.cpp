#include <iostream>

int main()
{
    for(int i = 1; i <=5; ++i)
    {

        for(int j = 5; j >= i; --j)
        {
            std::cout << j;
        }
        std::cout << "\n";
    }   
}