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

    while(temp != NULL)
    {

        count_node++;
        temp = temp->next;
    }
    return count_node;
}

void display(node* head)
{
    node *temp = head;
    cout << "NULL <=> ";

    while (temp != NULL)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}

void displayreverse(node* head)
{
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "NULL <=> ";

    while(temp != head)
    {
        cout << temp->data << " <=> ";
        temp = temp->prev;
    }
    cout << temp->data << " <=> ";

    cout << "NULL" << endl;

}





void insert(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    
    while(temp->next !=NULL)
    {
        temp = temp ->next;
    }

    temp->next = n;
    n->prev = temp;
    return;

}

void insertathead(node* &head, int val)
{
    node* n = new node(val);

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
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }
    else if(pos == count(head))
    {
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
        n->prev = temp;
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

    while(temp != NULL)
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
    }

    cout << "Element not found." << endl;

}



int main()
{
    node *head = NULL;

    insert(head, 10);
    insert(head,20); 
    insert(head,30);
    // display(head);
    insertathead(head,40);
    display(head);
    // displayreverse(head); 
    cout << count(head) << endl;
    insertatrandom(head,50,1);
    display(head);

    deletenode(head,20);
    display(head);

    return 0;
}