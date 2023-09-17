#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int size;

    int *arr;

public:
    Queue(int n) : size{n}
    {
        rear = front = -1;

        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(rear == -1 && front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if(((rear+1)%size) == front)
            return true;
        return false; 
    }

    int count()
    {
        return rear-front+1;
    }

    void enqeue(int val)
    {
        if(isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
            cout << "Element inserted successfully." << endl;
            return;
        }
        else
        {
            rear = (rear+1)%size;
            arr[rear] = val;
            cout << "Element inserted successfully." << endl;
            return;
        }
    }

    int dequeue()
    {
        int x = 0;
        if(isEmpty())
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        else if(rear == front)
        {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
            cout << "Element removed successfully." << endl;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front+1)%size;
            cout << "Element removed successfully." << endl;
            return x;
        }
    }

    void display()
    {
        for(int i = rear; i >= front; i--)
        {
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }



};

int main()
{
    int size = 0;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);
    int option, value;

    do
    {
        cout << "1. Enqueue." << endl;
        cout << "2. Dequeue." << endl;
        cout << "3. isEmpty." << endl;
        cout << "4. isFull." << endl;
        cout << "5. Count." << endl;
        cout << "6. Display." << endl;
        cout << "7. Clear Screen." << endl;
        cout << "8. Exit." << endl;

        cout << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "Enter the value you want to insert: ";
            cin >> value;
            q.enqeue(value);
            break;
        }
        case 2:
        {
            int x = q.dequeue();
            cout << "Element removed: " << x << endl;
            break;
        }
        case 3:
        {
            if(q.isEmpty())
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
            if(q.isFull())
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
            cout << "Number of elements in the stack: " << q.count() << endl;
            cout << "Elements in the stack: ";
            q.display();
            break;
        }
        case 6:
        {
            cout << "Elements in the stack: ";
            q.display();
            break;
        }
        case 7:
        {
            system("cls");
            break;
        }
        }
    } while (option != 0);

    return 0;
}