#include <stdio.h>
#include <chrono>
#include <iostream>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    char i = 81;
    while (i--)
    {
        if (i / 9 % 3 == i % 9 % 3)
        {
            continue;
        }
        printf("A = %d, B = %d\n", i / 9 + 1, i % 9 + 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}