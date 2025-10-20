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

void BS(List& l)
{
    if(!l.s)
    {
        return;
    }
    bool ok;
    do
    {
        ok=false;
        node* p=l.s;
        while(p && p->next)
        {
            if(p->val > p->next->val)
            {
                int v=p->val;
                p->val=p->next->val;
                p->next->val=v;
                ok=true;
            }
            p=p->next;
        }
    }while(ok);
}

void IS(List& l)
{
    if (!l.s || !l.s->next) return;
    node* sorted=nullptr;
    node* current=l.s;
    while(current)
    {
        node* next=current->next;
        if(!sorted || current->val<sorted->val)
        {
            current->next=sorted;
            sorted=current;
        }
        else
        {
            node* p=sorted;
            while(p->next && p->next->val<current->val)
            {
                p=p->next;
            }
            current->next=p->next;
            p->next=current;
        }
        current=next;
    }
    l.s=sorted;
}

void mergeL(List& l1, List& l2)
{
    node* p1=l1.s;
    node* p2=l2.s;
    node* lef=nullptr;
    node* rig=nullptr;
    while(p1 && p2)
    {
        node* mi;
        if(p1->val<=p2->val)
        {
            mi=p1;
            p1=p1->next;
        }
        else
        {
            mi=p2;
            p2=p2->next;
        }
        if(!lef)
        {
            lef=rig=mi;
        }
        else
        {
            rig->next=mi;
            rig=rig->next;
        }
    }
    if(p1)
    {
        rig->next=p1;
    }
    if(p2)
    {
        rig->next=p2;
    }
    l1.s=lef;
    l2.s=nullptr;
}

void deldup(List& l)
{
    node* p=l.s;
    while(p && p->next)
    {
        if(p->val==p->next->val)
        {
            node* dup=p->next;
            p->next=p->next->next;
            delete dup;
        }
        else
        {
            p=p->next;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    List list1, list2;
    int x;
    while(cin>>x)
    {
        if(x==0)
        {
            break;
        }
        add(list1,x);
    }
    while(cin>>x)
    {
        if(x==0)
        {
            break;
        }
        add(list2, x);
    }
    BS(list1);
    IS(list2);

    mergeL(list1, list2);
    deldup(list1);
    printList(list1);
    return 0;
}
