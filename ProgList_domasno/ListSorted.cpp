#include <bits/stdc++.h>

using namespace std;

#define int long long

struct node
{
    int val;
    node *next=nullptr;
};

struct List
{
    node *s=nullptr;
};

void add(List &l,int x)
{
    node *a=new node();
    a->val=x;
    if(l.s==nullptr || x<(l.s)->val)
    {
        a->next=l.s;
        l.s=a;
        return ;
    }
    node *p=l.s;
    while(p->next && p->next->val<x)
    {
        p=p->next;
    }
    a->next=p->next;
    p->next=a;
}

void printList(const List& l)
{
    node* p=l.s;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    List l;
    int x;
    while(cin>>x)
    {
        if(x==0)break;
        add(l,x);
    }
    printList(l);
    return 0;
}
