#include <iostream>
using namespace std;

#define MAX 50

class Node
{
public:
    int data;
    int flag;
    Node *lchild, *rchild;

    Node(int val)
    {
        data = val;
        flag = 0;
        lchild = rchild = NULL;
    }
};

Node *root = NULL, *temp, *ptr;
Node* stack[MAX];
int top = -1;

void push(Node* x)
{
    stack[++top] = x;
}

Node* pop()
{
    return stack[top--];
}

int isEmpty()
{
    return (top == -1);
}

Node* getnode()
{
    int val;
    cout << "Enter data: ";
    cin >> val;
    return new Node(val);
}

void CreateTree()
{
    temp = getnode();

    if (root == NULL)
    {
        root = temp;
        return;
    }

    ptr = root;
    char dir;

    while (1)
    {
        cout << "Enter direction (l/r): ";
        cin >> dir;

        if (dir == 'l')
        {
            if (ptr->lchild == NULL)
            {
                ptr->lchild = temp;
                break;
            }
            ptr = ptr->lchild;
        }
        else if (dir == 'r')
        {
            if (ptr->rchild == NULL)
            {
                ptr->rchild = temp;
                break;
            }
            ptr = ptr->rchild;
        }
    }
}

void Preorder()
{
    top = -1;
    temp = root;

    while (temp != NULL || !isEmpty())
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->rchild != NULL)
                push(temp->rchild);
            temp = temp->lchild;
        }
        if (!isEmpty())
            temp = pop();
    }
}

void Inorder()
{
    top = -1;
    temp = root;

    while (temp != NULL || !isEmpty())
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->lchild;
        }
        temp = pop();
        cout << temp->data << " ";
        temp = temp->rchild;
    }
}

void Postorder()
{
    top = -1;
    temp = root;

    while (temp != NULL || !isEmpty())
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->lchild;
        }

        temp = pop();

        if (temp->flag == 1)
        {
            cout << temp->data << " ";
            temp = NULL;
        }
        else
        {
            temp->flag = 1;
            push(temp);
            temp = temp->rchild;
        }
    }
}


int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        CreateTree();

    cout << "\nPreorder Traversal: ";
    Preorder();

    cout << "\nInorder Traversal: ";
    Inorder();

    cout << "\nPostorder Traversal: ";
    Postorder();

    return 0;
}
