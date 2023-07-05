#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    // cout << "Enter the str: ";
    // string str;
    

    // getline(cin, str);

    // ofstream out("sample.txt");

    // out<<str;

    string str1;

    ifstream in("sample.txt");
    getline(in, str1);

    cout << str1 << endl;





    return 0;
}
