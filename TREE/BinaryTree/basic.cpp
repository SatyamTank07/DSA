#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << "  ";
    InorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << "  ";
}

Node *createNode()
{
    int data;
    cout << "  Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *newnode = new Node(data);
    cout << "Left Node of " << newnode->data;
    newnode->left = createNode();
    cout << "Right Node of " << newnode->data;
    newnode->right = createNode();

    return newnode;
}
// 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
void levelorderTravarsal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << "  ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{

    Node *root = createNode();
    // cout << "Root Node -> " << root->data << endl;

    // cout << "Preorder Travarsal : ";
    // preorderTraversal(root);
    // cout <<endl << "Inorder Travarsal : ";
    // InorderTraversal(root);
    // cout <<endl<< "postorder Travarsal : ";
    // postorderTraversal(root);

    cout << endl
         << "Level order Travarsal : ";
    levelorderTravarsal(root);

    return 0;
}

// OUTPUT
// Enter the data : 10
// Left Node of 10  Enter the data : 20
// Left Node of 20  Enter the data : 40
// Left Node of 40  Enter the data : -1
// Right Node of 40  Enter the data : -1
// Right Node of 20  Enter the data : -1
// Right Node of 10  Enter the data : 30
// Left Node of 30  Enter the data : 50
// Left Node of 50  Enter the data : -1
// Right Node of 50  Enter the data : -1
// Right Node of 30  Enter the data : 70
// Left Node of 70  Enter the data : -1
// Right Node of 70  Enter the data : -1
// Root Node -> 10