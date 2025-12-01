#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k)
    {
        key=k;
        left=right=nullptr;
        height=1;
    }
};

int height(Node* n)
{
    return n ? n->height : 0;
}

int balance(Node* n)
{
    return n ? height(n->left)-height(n->right) : 0;
}

Node* rotateRight(Node* y)
{
    Node* x=y->left;
    Node* T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left), height(y->right)) + 1;
    x->height=max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x)
{
    Node* y=x->right;
    Node* T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left), height(x->right)) + 1;
    y->height=max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int key)
{
    if(!root)
    {
        return new Node(key);
    }
    if(key<root->key)
    {
        root->left=insert(root->left, key);
    }
    else if(key>root->key)
    {
        root->right=insert(root->right, key);
    }
    else
    {
        return root;
    }
    root->height=1+max(height(root->left), height(root->right));
    int bf=balance(root);

    // LL
    if(bf > 1 && key < root->left->key)
        return rotateRight(root);

    // RR
    if(bf < -1 && key > root->right->key)
        return rotateLeft(root);

    // LR
    if(bf > 1 && key > root->left->key)
    {
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL
    if(bf < -1 && key < root->right->key)
    {
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

signed main()
{
    ///pr of ChatGPT za proverka
    Node* root=nullptr;

    int values[]={30, 20, 40, 10, 25, 50, 5};

    cout << "Inserting values: ";
    for (int x : values) {
        cout << x << " ";
        root=insert(root, x);
    }
    cout << endl;

    cout << "Inorder (sorted) traversal: ";
    inorder(root);
    cout << endl;

    // Add more:
    root=insert(root, 35);
    root=insert(root, 45);

    cout << "After inserting 35 and 45: ";
    inorder(root);
    cout << endl;

    return 0;
}
