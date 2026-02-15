#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int maxn=1e5+10;
 
int st[4*maxn];
int Lmx[4*maxn];
int Rmx[4*maxn];
int mx[4*maxn];
 
vector<int>p;
 
void u(int L,int R,int idx,int nval,int pos)
{
    if(L==R)
    {
        st[pos]=mx[pos]=Lmx[pos]=Rmx[pos]=nval;
        return ;
    }
    int mid=(L+R)/2;
    if(idx<=mid)
    {
        u(L,mid,idx,nval,2*pos);
    }
    else
    {
        u(mid+1,R,idx,nval,2*pos+1);
    }
    st[pos]=st[2*pos]+st[2*pos+1];
    Lmx[pos]=max(Lmx[2*pos],st[2*pos]+Lmx[2*pos+1]);
    Rmx[pos]=max(Rmx[2*pos+1],st[2*pos+1]+Rmx[2*pos]);
    mx[pos]=max({mx[2*pos],mx[2*pos+1],Lmx[2*pos+1]+Rmx[2*pos]});
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a[n];
    p.assign(n,-1);
    map<int,int>prev;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        prev[a[i]]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(prev[a[i]]!=-1)
        {
            p[i]=prev[a[i]];
        }
        prev[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        int prev=p[i];
        if(prev==-1)continue;
        u(0,n-1,prev,1,1);
        int p_prev=p[prev];
        if(p_prev!=-1)
        {
            u(0,n-1,p_prev,-1,1);
            int pp_prev=p[p_prev];
            if(pp_prev!=-1)
            {
                u(0,n-1,pp_prev,0,1);
            }
        }
        ans=max(ans,mx[1]);
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i]<< " ";
    }
    cout<<endl;*/
    cout<<ans<<endl;
    return 0;
}