#include <stdio.h>
#include <iostream>

using namespace std;

void test1(int* x)
{
    // cout << "test1 " << x << "\n"; -> prints out the memory address rather than the value
    cout << "test1 " << *x << "\n"; // fixed
}

void test2(int *x)
{
    cout << "test2 " << *x << "\n";
}

void test3(int x)
{
    cout << "test3 " << x << "\n";
}

int main()
{
    int n = 10;
    
    test1(&n);

    //test2(n); -> passing int while finction expects int*
    test2(&n); //fixed

    //test3(&n); invalid conversion from int* to int
    test3(n); //fix

    return 0;
}