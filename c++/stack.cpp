#include <iostream>

using namespace std;

class Stack
{

    int size = 0;
    int *arr;
    int top = -1;

public:
    Stack(int n)
    {
        size = n;
        arr = new int[size];
        top = -1;

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(top== -1)
            return true;
        return false;
    }


    bool isFull()
    {
        if(top == size-1)
            return true;
        return false;
    }

    void push(int val)
    {
        if(!isFull())
        {
            arr[++top] = val;
            cout << "Inserted Successfully!" << endl;
            return;
        }
        cout << "Stack is Full!" << endl;
        return;
    }


    int pop()
    {
        if(!isEmpty())
        {
            int value = 0;

            value = arr[top];
            arr[top--] = 0;

            cout << "Element poped successfully! " << endl;
            return value;
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return 0;
        }

    }

    int count()
    {
        return top+1;
    }

    void display()
    {
        if(!isEmpty())
        {
            for(int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            cout << "Stack is empty." << endl;
            return;
        }
    }


};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s1(size);

    int option, value ;

    do
    {
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. isEmpty." << endl;
        cout << "4. isFull." << endl;
        cout << "5. Count." << endl;
        cout << "6. Display." << endl;
        cout << "7. Clear Screen." << endl;
        cout << "0. Exit." << endl << endl;

        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
            case 1:
            {
                cout << "Enter the value to puch into stack: ";
                cin >> value;

                s1.push(value);
                break;
            }

            case 2:
            {
                value = s1.pop();
                cout << "Element poped: " << value << endl;
                break;
            }

            case 3:
            {
                if(s1.isEmpty())
                {
                    cout << "Stack is empty." << endl;
                }
                else
                {
                    cout << "Stack is not empty." << endl;
                }
                break;
            }
            case 4:
            {
                if(s1.isFull())
                {
                    cout << "Stack is full." << endl;
                }
                else
                {
                    cout << "Stack is not full." << endl;
                }
                break;
            }
            case 5:
            {
                cout << "Number of elements in the stack: " << s1.count() << endl;
                cout << "Elements in the stack: ";
                s1.display();
                break;
            }
            case 6:
            {
                cout << "Elements in the stack: ";
                s1.display();
                break;
            }
            case 7:
            {
                system("cls");
                break;
            }
            default:
            {
                cout << "Enter proper number." << endl;
            }
        }
    } while (option != 0);
    

    return 0;
}