#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int count_nodes(node *head)
{
    int count = 0;

    node *temp = head;

    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }

    return count;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}


void insertathead(node* &head, int val)
{
    node* n = new node(val);

    n->next = head;
    head = n;
}

void insert(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    return;
}

void insertatrandom(node *&head, int val, int pos)
{
    node *n = new node(val);

    if (pos > count_nodes(head))
        return;

    if (head == NULL)
    {
        head = n;
        return;
    }
    else if (pos == count_nodes(head))
    {
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
        return;
    }
    else
    {
        int i = 1;
        node *temp = head;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        n->next = temp->next;
        temp->next = n;
        return;
    }
}

void deletenode(node* & head, int val)
{
    if(head == NULL)
    {
        return;
    }
    else if(head->data == val)
    {
        head = head->next;
        return;
    }
    else
    {
        node* temp = head;
        
        while(temp != NULL)
        {
            if(temp->next->data == val)
            {
                temp->next = temp->next->next;
                return;
            }
            temp =  temp->next;
        }
        cout << "Element not found." << endl;
        return;
    }
    
}

int main()
{

    node *head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head,40);
    insert(head, 50);
    // cout << "Count: " << count_nodes(head) << endl;

    // insertatrandom(head, 40, 3);

    display(head);

    deletenode(head,10);
    display(head);

    // insertathead(head,60);
    // insertathead(head,70); 
    // display(head);

    return 0;
}