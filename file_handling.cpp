#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    // one way to write into a file.
    // string str;
    // cout << "Enter the str: ";
    // getline(cin, str);
    // ofstream out("sample.txt");
    // out<<str;
    // out.close();

    // Anoher way to write into a file.
    // string str;
    // cout << "Enter the str: ";
    // getline(cin, str);
    // ofstream out;
    // out.open("sample,txt");
    // out << "My name is "+str;
    // out.close();


    // string str1;
    // ifstream in("sample.txt");
    // getline(in, str1);
    // in.close();
    // cout << str1 << endl;


    string str1;
    ifstream in;
    in.open("sample.txt");
    getline(in,str1);
    in.close()

    while(in.eof())
    {
        getline(in,str1);
        cout << str1 << endl;
    }





    return 0;
}
