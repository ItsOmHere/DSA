#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int sal;
    int id;
    Node *left, *right;
    
    Node(string Name, int Sal, int Id)
    {
        name = Name;
        sal = Sal;
        id = Id;
        left = right = NULL;
    }
};

Node* root = NULL;
Node* temp = NULL;
Node* getnode()
{
    int sal, id;
    string Name;

    cout << "Enter Name: ";
    cin >> Name;
    cout << "Enter Id: ";
    cin >> id;
    cout << "Enter Salary: ";
    cin >> sal;

    return new Node(Name, sal, id);  
}

void InsertNode()
{
    
    Node* temp = getnode();

    if (root == NULL)
    {
        root = temp;
        return;
    }

    Node* ptr = root;

    while (true)
    {
        if (temp->sal < ptr->sal)
        {
            if (ptr->left == NULL)
            {
                ptr->left = temp;
                break;
            }
            ptr = ptr->left;
        }
        else
        {
            if (ptr->right == NULL)
            {
                ptr->right = temp;
                break;
            }
            ptr = ptr->right;
        }
    }
    
}

void display(Node* root)
{
    cout << "----------------------"<<endl;
    cout << "\nName: " << root->name;
    cout << "\nID: " << root->id;
    cout << "\nSalary: " << root->sal << "\n";
    cout << "----------------------"<<endl;
}

void Preorder(Node* root)
{
    if (root == NULL) return;

    display(root);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root)
{
    if (root == NULL) return;

    Inorder(root->left);
    display(root);
    Inorder(root->right);
}

void Postorder(Node* root)
{
    if (root == NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    display(root);
}
void leastSal(Node* root){
    if(root == NULL) return;

    while(root->left != NULL){
        root = root->left;
    }
    display(root);
}

void highestSal(Node* root){
    if(root == NULL) return;

    while(root->right != NULL){
        root = root->right;
    }
    display(root);
}

Node* deletechild(Node* root, int key, Node* pr = NULL) {
    if (root == NULL)
        return NULL;

    if (key < root->sal) {
        root->left = deletechild(root->left, key, root);
    }
    else if (key > root->sal) {
        root->right = deletechild(root->right, key, root);
    }
    else {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            cout << "Leaf node deleted successfully.\n";
            return NULL;
        }
        else if(root->left != NULL && root->right != NULL)
        {
            temp = root->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            temp->left = root->left;
            temp = root->right;
            delete root;
            return temp;
            

        }
        else  {
            Node* child = (root->left != NULL) ? root->left : root->right;
            delete root;
            cout << "Node with one child deleted successfully.\n";
            return child;
        }

    }
    
    return root;
}
Node* SecondHigh(Node* root , Node* pr = NULL,Node* child = NULL )
{
    if(root == NULL)
    {
        return NULL;
    }
    
    while(root->right != NULL)
    {
        temp = root;
        root = root->right;
    }
    if (root->left != NULL)
    {
        child = root->left;
        while(child->right !=NULL)
        {
            child = child->right;
        }
        return child;

    }
    return temp;
    
}
Node* SecondLowest(Node* root , Node* pr = NULL,Node* child = NULL )
{
    if(root == NULL)
    {
        return NULL;
    }
    
    while(root->left != NULL)
    {
        temp = root;
        root = root->left;
    }
    if (root->right != NULL)
    {
        child = root->right;
        while(child->left !=NULL)
        {
            child = child->left;
        }
        return child;

    }
    return temp;
    
}

int main()
{
    int ch = -1;

    while (ch != 0)
    {
        cout << "\n1.Add Node\n2.Inorder\n3.Preorder\n4.PostOrder\n5.Lowest Salary\n6.Highest Salary\n7.Delete node\n8.Second Highest\n9.Second Lowest\n0.Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1: InsertNode(); break;
            case 2: Inorder(root); break;
            case 3: Preorder(root); break;
            case 4: Postorder(root); break;
            case 5: leastSal(root); break;
            case 6: highestSal(root); break;
            case 7:  
                {
                 int key;
                 cout<<"Enter key to delete:";
                 cin>>key;
                 root = deletechild(root , key);

                }break;
            case 8: {
                cout<<"\n\nSecond Highest Salary Details:\n";
                temp=SecondHigh(root);
                display(temp);
                break;
            }
            case 9: {
                cout<<"\n\nSecond Lowest Salary Details:\n";
                temp=SecondLowest(root);
                display(temp);
                break;
            }
            case 0: cout << "Exiting...!"; break;
            default: cout << "Invalid choice!";
        }
    }


    return 0;
}
