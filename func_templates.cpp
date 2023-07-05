#include <iostream>

using namespace std;

template <class T1, class T2>

float avg(T1 a, T2 b)
{
    return (a+b)/2.0;
}

int main()
{
    cout << avg(5,10.5);
}
