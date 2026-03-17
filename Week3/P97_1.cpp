//(1)
#include <iostream>
int main()
{
    for(int i = 1; i <=5; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            std::cout << j;
        }
        std::cout << "\n";
    }
}

//(2)
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

//(3)
#include <iostream>
int main()
{
    for(int i = 1; i <= 5; i++)
    {
        // std::cout << i << "\n";
        for(int j = 4; j >= i; j--)
        {
            std::cout << " ";
        }
        for (int l = 0; l <= i -1; l++)
        {
            std::cout << i - l;
        }
        std::cout << "\n";
    }
    return 0;
}

//(4)
#include <iostream>
int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for (int k = 4; k >= i; k--)
        {
            std::cout << " ";
        }
        for (int s=0; s<i; s++)
        {
            std::cout << i - s;
        }
        for (int j=2; j<=i; j++)
            std::cout <<j;
        std::cout << "\n";
    }
    return 0;
}
