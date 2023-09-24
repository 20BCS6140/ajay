#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node* next;
    node* prev;

    node(int val):data{val},next {NULL},prev{NULL}
    {

    }
};


int count(node* head)
{
    node* temp = head;

    int count_node = 0;

    if(head == NULL)
        return count_node;
    
    do
    {
        count_node++;
        temp = temp->next;

    } while (temp != head);
    

    return count_node;
}

void display(node* head)
{
    node *temp = head;

    if(head == NULL)
    {
        cout << "<=> NULL <=>" << endl;
        return;
    }

    cout << "NULL <=> ";

    do
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    } while (temp != head);
    
    cout << "NULL" << endl;
    return;
}

// void displayreverse(node* head)
// {
//     node* temp = head;

//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     cout << "NULL <=> ";

//     while(temp != head)
//     {
//         cout << temp->data << " <=> ";
//         temp = temp->prev;
//     }
//     cout << temp->data << " <=> ";

//     cout << "NULL" << endl;

// }





void insert(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }

    node* temp = head;

    do
    {
        temp = temp->next;
    } while (temp->next != head);
    
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    return;

}

void insertathead(node* &head, int val)
{
    node* n = new node(val);

    node* temp = head;

    if(head == NULL)
    {
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }

    do
    {
        temp = temp->next;
    } while (temp->next != head);

    temp->next = n;
    n->prev = temp;
    n->next = head;
    head->prev = n;
    head = n;
    

    return;

}

void insertatrandom(node* &head, int val,int pos)
{
    node* n = new node(val);

    if(pos > count(head))
    {
        cout << "Invalid position." << endl;
    }
        
    
    if(head == NULL)
    {
        

        head = n;
        head->next = head;
        head->prev = head;
        return;
    }

    else if(pos == count(head))
    {
        insert(head,val);

        return;
    }
    else
    {
        int i = 1;
        node* temp = head;

        while(i < pos)
        {
            temp = temp->next;
            i++;
        }

        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
        n->prev = temp;

        return;
    }
}


void deletenode(node* &head, int val)
{
    if(head == NULL)
        return;
    else if(head->data == val)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }

    node* temp = head;

    do
    {
        if(temp->next->data == val)
        {
            temp->next = temp->next->next;
            if(temp->next != NULL)
            {
                temp->next->prev = temp;
            }
            
            return;
        }
        temp = temp->next;
    }while(temp != head);

    cout << "Element not found." << endl;

}



int main()
{
    node *head = NULL;

    insert(head,10);
    insert(head, 20);
    display(head);
    insertathead(head,30);
    insert(head,50);
    display(head);
    insertatrandom(head,100,1);
    cout << count(head) << endl;
    display(head);

    

    return 0;
}