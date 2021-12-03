// AdventOfCode21.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"

int main()
{
    std::cout << "~~Starting with Advent of Code 21!~~\n\n";

    std::cout << "\n-Problem 1-\n";

    Problem1 problem1("problem1.txt");
    problem1.Resolve();

    std::cout << "\n-Problem 2-\n";

    Problem2 problem2("problem2.txt");
    problem2.Resolve();

    std::cout << "\n-Problem 3-\n";

    Problem3 problem3("problem3.txt");
    problem3.Resolve();
}