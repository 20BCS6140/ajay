#include <iostream>
#define SPACE 10

using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        
        node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};


bool isEmpty(node* root)
{
    if(root == NULL)
        return true;
    return false;
}


node* InsertRecursive(node* &root, int val)
{
    node* n = new node(val);
    
    if(val == root->data)
    {
        cout << val << " is already exists.\n";
    }
    
    if(root == NULL)
    {
        root = n;
        cout << "Value inserted successfully.\n";
    }
    else
    {
        if(val < root->data)
            root->left = InsertRecursive(root->left,val);
        else
            root->right = InsertRecursive(root->right,val);
    }

    return root;
}

void InsertIterative(node* &root, int val)
{
    node* n =  new node(val);
    
    if(root == NULL)
    {
        root = n;
        cout << "Value inserted  as a root node successfully.\n";
        return;
    }
    
    if(n->data == root->data)
    {
        cout << n->data <<  " is already exists.\n";
        return;
    }
    
    node* temp = root;
    node* parent = NULL;
    
    while(temp != NULL)
    {
        parent = temp;
        
        if(n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    
    if(n->data < parent->data)
    {
        parent->left = n;
        cout << "Value inserted  to the left successfully.\n";
    }
    else
    {
        parent->right = n;
        cout << "Value inserted to the right successfully.\n";
    }
        
        
    return;
    
    
}

void InsertNode(node* &root, int val)
{
    node* n = new node(val);
    
    if(isEmpty(root))
    {
        root = n;
        cout << "Value inserted  as a root node successfully.\n";
        return;
    }
    else
    {
        node* temp = root;
        
        while(temp!=NULL)
        {
            if(n->data == temp->data)
            {
                cout << n->data <<  " is already exists.\n";
                return; 
            }
            else if ((n->data < temp->data) && (temp->left ==NULL) )
            {
                temp->left = n;
                cout << "Value inserted  to the left successfully.\n";
                return;
            }
            else if (n->data < temp->data)
            {
                temp = temp->left;
            }
            else if ((n->data > temp->data) && (temp->right ==NULL) )
            {
                temp->right = n;
                cout << "Value inserted  to the right successfully.\n";
                return;
            }
            else if (n->data > temp->data)
            {
                temp = temp->right;
            }
        }
    }
}

void PreOrder(node* root)
{
	if(root == NULL)
		return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root)
{
	if(root == NULL)
		return;
	
	InOrder(root->left);
	
	cout << root->data << " ";
	
	InOrder(root->right);
}

void PostOrder(node* root)
{
	if(root == NULL)
		return;
	
	PostOrder(root->left);
	
	PostOrder(root->right);
	
	cout << root->data << " ";
}


void IterativeSearch(node* root, int value)
{
	if(root == NULL)
	{
		cout << "BST is empty." << endl;
		return;
	}
	else
	{
		node* temp = root;
		
		while(temp != NULL)
		{
			if( value == temp->data)
			{
				cout << temp->data << " found in the BST." << endl;
				return;
			}
			else if(value < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	cout << value << " not found in the BST." << endl;
	return;
		
}

node* RecursiveSearch(node* root, int value)
{
	if(root == NULL)
	{
		cout << "BST is empty." << endl;
		return root;
	}
	
	if(value == root->data)
	{
//		cout << root->data << " found in the BST." << endl;
		return root;
	}
	
	if(value < root->data)
		root =  RecursiveSearch(root->left, value);
	else
		root = RecursiveSearch(root->right,value);
}

int height(node* root)
{
	if(root == NULL)
		return -1;
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		
		if(lheight > rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}

void printpresentlevel(node* root, int level)
{
	if(root == NULL)
	{
		return;
	}
	else if(level == 0)
	{
		cout << root->data << " ";
	}
	else
	{
		printpresentlevel(root->left,level-1);
		printpresentlevel(root->right,level-1);
	}
}

void BearthFrstSearch(node* root)
{
	int h = height(root);
	
	for(int i = 0; i <= h; i++)
	{
		printpresentlevel(root,i);
	}
}

node* maxnodevalueatleft(node* root)
{
	node* current = root;
	
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}


node* deletenode(node* root, int val)

{
	if(root == NULL)
	{
		return root;
	}
	else if(val < root->data)
	{
		root->left = deletenode(root->left, val);
	}
	else if(val > root->data)
	{
		root->right = deletenode(root->right,val);
	}
	else
	{
		if(root->left == NULL)
		{
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			node* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			node* temp = maxnodevalueatleft(root->left);
			root->data = temp->data;
			root->left = deletenode(root->left,temp->data);
		}
	}
	return root;
}


void print2D(node* root, int space)
{
    if(root == NULL)
        return;
        
    space +=SPACE;
    
    print2D(root->right,space);
    
    cout << "\n";
    
    for(int i = SPACE; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << "\n";
    print2D(root->left, space);
}


int GetBalancedFcator(node* n)
{
    if(n == NULL)
        return -1;
    else
        return (height(n->left)-height(n->right));
}

node* RightRotation(node* n)
{
    node* x = n->left;
    node* t2 = x->right;

    //rotate
    x->right = n;
    n->left = t2;
    return x;
}

node* LeftRotation(node* n)
{
    node* x = n->right;
    node* t2 = x->left;

    //rotate
    x->left = n;
    n->right = t2;

    return x;
}

node* AVLInsertion(node* root,int val)
{
    node* n = new node(val);
    if(root == NULL)
        return root;
    else if(val < root->data)
        root->left = AVLInsertion(root->left,val);
    else if(val > root->data)
        root->right = AVLInsertion(root->right,val);
    else
    {
        cout << "The number already exists." << endl;
        return root;
    }

    int bf = GetBalancedFcator(root);

    if(bf > 1 && val < root->left->data)
        return RightRotation(root);
    else if(bf < -1 && val> root->right->data)
        return LeftRotation(root);
    else if(bf > 1 && val > root->left->data)
    {
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }
    else if(bf < -1 && val < root->right->data)
    {
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }
    return root;    
        
}

int main()
{
    node* root = NULL;
    node* AVL = NULL;
    
    int option;
    int value;
    int deleteelement;
    
    do{
        cout << "1. Insert node.\n";
        cout << "2. Search node.\n";
        cout << "3. Delete node.\n";
        cout << "4. Print BST.\n";
        cout << "5. Clear screen.\n";
        cout << "6. isEmpty.\n";
        cout << "7. Height of the BST.\n";
        cout << "0. Exit.\n\n";
        
        cout << "Enter an option: ";
        cin >> option;
        
        
        switch(option)
        {
            case 0:
                break;
            case 1:
            {
                int val;
                cout << "Enter the value to insert into BST: ";
                cin >> val;
                AVL = AVLInsertion(AVL,val);
                cout << "\n";
                break;

            }
                
            case 2:
            	{	
            	    cout << "Enter the value to search: ";
            	    cin >> value;
            	    cout << "Iterative search: ";
            	    IterativeSearch(root,value);
            	    cout << "\n";
            	    node* temp = RecursiveSearch(root,value);
            	    if(temp == NULL)
            		    cout << value << " not found in the BST." << endl;
            	    else
            		    cout << value << " found in the BST." << endl;
            		
                    break;
                }
            case 3:
            	{
            		cout << "Enter the value to delete: ";
            		cin >> deleteelement;
            		node* deletednode = deletenode(root, deleteelement);
            		if(deletednode == NULL)
            			cout << "Element not there in the BST" << endl;
            		else
            			cout << "Eelement deleted." << endl;
            		break;
				}
                
            case 4:
                print2D(AVL,0);
                // cout << "Inorder: ";InOrder(root);
                // cout << "\n";
                // cout << "Preorder: ";PreOrder(root);
                // cout << "\n";
                // cout << "Postorder: "; PostOrder(root);
                // cout<< "\n";
                // cout << "Breath First Search: "; BearthFrstSearch(root);
                // cout<< "\n";
                break;
            case 5:
                system("cls");
                break;
            case 6:
                if(isEmpty(root))
                {
                    cout << "BST is empty.\n";
                }
                else
                {
                    cout << "BST is not empty.\n";
                }
                break;
            case 7:
            	{
            		int heightofbst = height(root);
            		cout << "Height of BST: " << heightofbst << endl;
            		break;
				}
            	
            	
            default:
                cout << "Enter the proper option.\n";
                
        }
        
    }while(option != 0);
    
    
    
    return 0;
}