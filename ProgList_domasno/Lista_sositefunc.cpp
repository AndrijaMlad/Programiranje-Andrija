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

node* createnode(int val)
{
    node* newnode=new node;
    newnode->val=val;
    newnode->next=nullptr;
    return newnode;
}

void add(List& l,int val,int pos=-1)
{
    node* newnode=createnode(val);
    if(l.s==nullptr)
    {
        l.s=newnode;
        return;
    }
    if(pos==-1)
    {
        node* p=l.s;
        while(p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=newnode;
        return;
    }
    if(pos==0)
    {
        newnode->next=l.s;
        l.s=newnode;
        return;
    }
    node* p=l.s;
    int index=0;
    while(p!=nullptr && index<pos-1)
    {
        p=p->next;
        index++;
    }
    if(p==nullptr)
    {
        add(l,val); // ova e ako brojot go nadmine list.size()
        delete newnode;
        return;
    }
    newnode->next=p->next;
    p->next=newnode;
}

void del(List& l,int val)
{
    if(l.s==nullptr)
    {
        cout<<"listata e prazna"<<endl;
        return;
    }
    if(l.s->val==val)
    {
        node* tmp=l.s;
        l.s=l.s->next;
        delete tmp;
        return;
    }
    node* current=l.s;
    node* prev=nullptr;
    while(current!=nullptr && current->val!=val)
    {
        prev=current;
        current=current->next;
    }
    if(current==nullptr)
    {
        cout <<"vrednosta ja nema"<<endl;
        return;
    }
    prev->next=current->next;
    delete current;
}

node* search(List& l,int val)
{
    node* p=l.s;
    while(p)
    {
        if(p->val==val)
        {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    List l;
    int t;
    while(cin>>t)
    {
        if(t==0)break;
        if(t==1)
        {
            int x;
            int p;
            cin>>x>>p;
            add(l,x,p);
        }
        if(t==2)
        {
            int x;
            cin>>x;
            del(l,x);
        }
        if(t==3)
        {
            int x;
            cin>>x;
            if(search(l,x)==nullptr)
            {
                cout<<"nullptr"<<endl;
                continue;
            }
            node* p=search(l,x);
            cout<<p<<endl;
        }
    }
    return 0;
}
