#include <iostream>
#include <algorithm>

using namespace std;

class avlnode
{
    public:

        int data;
        avlnode* left;
        avlnode* right;

        avlnode(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }

};

int main()
{
    avlnode* root = NULL;

    int option;

    do
    {
        cout << "1. Insert node.\n";
        cout << "2. Delete node.\n";
        cout << "3. Search node.\n";
        cout << "4. print AVL tree.\n";
        cout << "5. Clear screen.\n";
        cout << "6. Height of the tree.\n";
        cout << "0. Exit.\n";

        cout << "Enter your option: ";
        cin >> option;
        
    } while (option != 0);
    
}