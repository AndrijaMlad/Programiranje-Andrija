#include <bits/stdc++.h>
 
using namespace std;
 
const long long maxn=2e5+10;
 
long long n,q;
long long x[maxn];
long long st[4*maxn];
 
void u(long long L,long long R,long long idx,long long nval,long long pos)
{
    if(L==R)
    {
        st[pos]=nval;
        return ;
    }
    long long mid=(L+R)/2;
    if(idx<=mid)
    {
        u(L,mid,idx,nval,2*pos);
    }
    else
    {
        u(mid+1,R,idx,nval,2*pos+1);
    }
    st[pos]=st[2*pos]+st[2*pos+1];
}
 
long long query(long long L,long long R,long long i,long long j,long long pos)
{
    if(i<=L && R<=j)
    {
        return st[pos];
    }
    if(L>j || i>R)
    {
        return 0;
    }
    long long mid=(L+R)/2;
    return query(L,mid,i,j,2*pos)+query(mid+1,R,i,j,2*pos+1);
}
 
int main()
{
    cin>>n>>q;
    for(long long i=0;i<n;i++)
    {
        cin>>x[i];
        u(0,n-1,i,x[i],1);
    }
    while(q--)
    {
        long long t;
        cin>>t;
        if(t==1)
        {
            long long k,v;
            cin>>k>>v;
            k--;
            u(0,n-1,k,v,1);
        }
        else
        {
            long long l;
            long long r;
            cin>>l>>r;
            l--;r--;
            cout<<query(0,n-1,l,r,1)<<endl;
        }
    }
    return 0;
}
