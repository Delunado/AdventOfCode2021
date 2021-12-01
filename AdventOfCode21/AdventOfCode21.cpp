// AdventOfCode21.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Problem1.h"

int main()
{
    std::cout << "~~Starting with Advent of Code 21!~~\n\n";

    std::cout << "-Problem 1-\n";

    Problem1 problem1("problem1.txt");
    problem1.Resolve();
}