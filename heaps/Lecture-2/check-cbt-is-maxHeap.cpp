#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

pair<bool, int> solve(Node *root)
{
    // base case

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // leaf Node
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    if (leftAns.first == true && rightAns.first == true && root->data > leftAns.second && root->data > rightAns.second)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    else
    {
        pair<bool, int> q = make_pair(false, root->data);
        return q;
    }
}

int main()
{
    cout << "Hello World";

    return 0;
}