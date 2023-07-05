#include <iostream>

using namespace std;

template <class T1, class T2> // Multi Parameterized template
//template <class T1> Single parameterized template
// template <class T1 = int,  class T2 = float> Default parameterized template

class example
{
    T1 data1;
    T2 data2;

    public:

    example(T1 a, T2 b):data1(a),data2(b){}

    void display()
    {
        cout << data1 << " " << data2 << endl;
    }
};

int main()
{

    example <int,char> obj(5,101);

    obj.display();



}