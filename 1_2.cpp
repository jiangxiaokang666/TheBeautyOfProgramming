#include <stdio.h>
#include <chrono>
#include <iostream>
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    struct
    {
        unsigned char a : 4;
        unsigned char b : 4;
    } i;
    for (i.a = 1; i.a <= 9; ++i.a)
    {
        for (i.b = 1; i.b <= 9; ++i.b)
        {
            if (i.a % 3 != i.b % 3)
            {
                printf("A = %d, B = %d\n", i.a, i.b);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}