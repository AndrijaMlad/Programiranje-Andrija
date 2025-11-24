#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node()
    {
        val=0;
        left=nullptr;
        right=nullptr;
    };
    Node(int v)
    {
        val=v;
        left=nullptr;
        right=nullptr;
    };
};

Node* buildBT(Node** nodes, int n)
{
    for(int i=0;i<n;i++)
    {
        int l=2*i+1;
        int r=2*i+2;
        if(l<n)nodes[i]->left=nodes[l];
        if(r<n)nodes[i]->right=nodes[r];
    }
    return nodes[0];
}

Node* insertBST(Node* root, int val)
{
    if(!root)
    {
        return new Node(val);
    }
    if(val<root->val)
    {
        root->left=insertBST(root->left, val);
    }
    else
    {
        root->right=insertBST(root->right, val);
    }
    return root;
}

bool find(Node* root, int x)
{
    if(!root)return false;
    if(root->val==x)return true;
    return (find(root->left, x)||find(root->right, x));
}

void preorder(Node* root)
{
    if(!root)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void bfs(Node* root)
{
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
}

int sumBT(Node* root)
{
    if(!root)return 0;
    return root->val+sumBT(root->left)+sumBT(root->right);
}

signed main()
{
    int n=7;
    Node* nodes[7];
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        nodes[i]=new Node(val);
    }
    Node* btRoot = buildBT(nodes, n);

    Node* bstRoot=nullptr;
    int values[]={5, 2, 8, 1, 3, 7, 9};
    for(int v:values)
    {
        bstRoot=insertBST(bstRoot, v);
    }
    return 0;
}
