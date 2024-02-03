#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter Value";
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    Node *root = new Node(value);
    cout << "Enter data in left of " << value << " : ";
    root->left = createTree();
    cout << "Enter data in right of " << value << " : ";
    root->right = createTree();
    return root;
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << endl;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void printLeftView(Node *root, int level, vector<int> &LeftView)
{
    if (root == NULL)
    {
        return;
    }
    if (level == LeftView.size())
    {
        LeftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, LeftView);
    printLeftView(root->right, level + 1, LeftView);
}

void printRightView(Node *root, int level, vector<int> &RightView)
{
    if (root == NULL)
    {
        return;
    }
    if (level == RightView.size())
    {
        RightView.push_back(root->data);
    }
    printRightView(root->left, level + 1, RightView);
    printRightView(root->right, level + 1, RightView);
}

void printTopView(Node *root)
{
    map<int, int> hdToNodemap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;
        // if there is no entry for hd in map, then create a new entry
        if (hdToNodemap.find(hd) == hdToNodemap.end())
        {
            hdToNodemap[hd] = frontNode->data;
        }
        // child ko dekhna h
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout << "printing top view: " << endl;
    for (auto i : hdToNodemap)
    {
        cout << i.second << " ";
    }
}

void printBottomView(Node *root)
{
    map<int, int> hdToNodemap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        hdToNodemap[hd] = frontNode->data;

        // child ko dekhna h
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout << "printing top view: " << endl;
    for (auto i : hdToNodemap)
    {
        cout << i.second << " ";
    }
}

void printLeftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    cout << root->data << "  ";
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;
    printLeftBoundary(root);
    printLeafBoundary(root);
    if (root->right != NULL)
    {

        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
}

int main()
{
    Node *root = createTree();
    // int level=0;
    vector<int> LeftView;
    vector<int> RightView;

    levelOrder(root);
    cout << endl;
    printLeftView(root, 0, LeftView);
    printRightView(root, 0, RightView);
    for (int i = 0; i < RightView.size(); i++)
    {
        cout << RightView[i] << endl;
    }
    printTopView(root);
    printBottomView(root);
    boundaryTraversal(root);
    return 0;

    // 10 20 30 -1 -1 5 -1 -1 6 -1 -1
}