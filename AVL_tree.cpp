#include <iostream>
#include <algorithm>

#define SPACE 10

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

bool isEmpty(avlnode* root)
{
    if(root == NULL)
        return true;
    return false;
}

int height(avlnode* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);

        return max(left_height, right_height)+1;
    }
}

int getbalancedfactor(avlnode* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else{
        return (height(root->left) - height(root->right));
    }
}

avlnode* left_rotation(avlnode* root)
{
    avlnode* x = root->right;
    avlnode* t2 = x->left;

    //rotate performing
    x->left = root;
    root->right = t2;
    return x;
}

avlnode* right_rotation(avlnode* root)
{
    avlnode* x = root->left;
    avlnode* t2 = x->right;

    //rotate performing

    x->right = root;
    root->left = t2;

    return x;
}


avlnode* insertnode(avlnode* &root, int val)
{
    avlnode* n = new avlnode(val);
    if(root == NULL)
    {
        root = n;
        cout << "Node inserted successfully." << endl;
        return root;
    }
    else if(val < root->data)
    {
        root->left = insertnode(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = insertnode(root->right, val);
    }
    else
    {
        cout << "No duplication allowed." << endl;
        return root;
    }

    int bf = getbalancedfactor(root);

    if(bf < -1 && val > root->right->data)
    {
        return left_rotation(root);
    }
    else if(bf < -1 && val < root->right->data)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }
    else if(bf > 1 && val < root->left->data)
    {
        return right_rotation(root);
    }
    else if(bf > 1 && val > root->left->data)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }

    return root;
}

void print_tree(avlnode* root, int space)
{
    if(root == NULL)
        return;
    
    space+=SPACE;

    print_tree(root->right, space);

    cout << endl;

    for (size_t i = SPACE; i < space; i++)
    {
        cout << " ";
    }

    cout << root->data << endl;

    print_tree(root->left, space);
    
}

void iterative_search(avlnode* root, int val)
{
    if(root == NULL)
    {
        cout << "The tree is empty." << endl;
        return;
    }
        
    avlnode* temp = root;

    while(temp != NULL)
    {
        if(temp->data == val)
        {
            cout << temp->data << " founded in the tree." << endl;
            return;
        }
        else if(val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    cout << val << " not found in the BST." << endl;
	return;
}

avlnode* recursive_search(avlnode* root, int val)
{
    if(root == NULL)
    {
        return root;
    }

    else if(root->data == val)
    {
        return root;
    }
    else if(root->data > val)
        return recursive_search(root->left,val);
    else
    return recursive_search(root->right,val);

}

void printpresentlevel(avlnode* root, int level)
{
    if(root == NULL)
        return;
    else if(level == 0)
        cout << root->data << " ";
    else
    {
        printpresentlevel(root->left,level-1);
        printpresentlevel(root->right,level-1);
    }
}


void breathfirstsearch(avlnode* root)
{
    int h = height(root);

    for(int i = 0; i <= h; i++)
    {
        printpresentlevel(root,i);
    }
}

void inorder(avlnode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(avlnode* root)
{
    if(root == NULL)
        return;


    cout << root->data << " ";
    inorder(root->left);
    
    inorder(root->right);
}

void postorder(avlnode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

avlnode* minnodeatright(avlnode* root)
{
    avlnode* current = root;

    while(current != NULL)
    {
        current = current->left;
    }

    return current;
}

avlnode* delete_node(avlnode* &root, int value)
{
    if(root == NULL)
        return root;
    
    else if(value < root->data)
        root->left = delete_node(root->left,value);
    else if(value > root->data)
        root->right = delete_node(root->right,value);
    else
    {
        if(root->left == NULL)
        {
            avlnode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            avlnode* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            avlnode* temp = minnodeatright(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }

    int bf = getbalancedfactor(root);

    if(bf > 1 && getbalancedfactor(root->left) >= 0)
    {
        return right_rotation(root);
    }
    else if(bf > 1 && getbalancedfactor(root->left) < 0)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }
    else if(bf < -1 && getbalancedfactor(root->right) < 0)
    {
        return right_rotation(root);
    }
    else if(bf < -1 && getbalancedfactor(root->right) >= 0)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }

    cout << "Node deleted." << endl;
    return root;
}

int main()
{
    avlnode* root = NULL;

    int option;
    int val;

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

        switch (option)
        {
            case 1:
            {
                
                cout << "Enter the value to insert: ";
                cin >> val;
                root = insertnode(root, val);
                break;
            }
            case 2:
            {
                cout << "Enter the value to insert: ";
                cin >> val;
                root = delete_node(root,val);
                break;
            }
            case 3:
            {
                cout << "Enter the value to insert: ";
                cin >> val;
                cout << "\n";
                cout << "Iretative search:";
                iterative_search(root,val);

                avlnode* temp = recursive_search(root,val);

                if(temp == NULL)
            		cout << val << " not found in the BST." << endl;
            	else
            	    cout << val << " found in the BST." << endl;
            		
                break;
            }
            case 4:
            {
                print_tree(root,0);
                cout << "\n";
                cout << "\n";
                cout << "In order: "; inorder(root);
                cout << "\n";
                cout << "Pre order: "; preorder(root);
                cout << "\n";
                cout << "Post order: "; postorder(root);
                cout << "\n";
                cout << "\n";
                break;
            }
            case 5:
            {
                system("cls");
                break;
            }
            case 6:
            {
                cout << height(root)+1 << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout << "Enter correct option.\n";
                break;
            }
            
        }
    } while (option != 0);
    
}