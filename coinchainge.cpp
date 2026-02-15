#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn=20;
 
int n,sum;
int a[maxn];
 
 
///Rekurzija-Brute force (+DP)
 
//int DP[maxn][maxn];
 
int f(int s,int idx)
{
    if(s<0)return 0;
    if(s==0)return 1;
    if(idx>=n)return 0;
    //if(dp[s][idx]!=-1)return dp[s][idx];
    int rez=0;
    for(int j=0;j<sum/a[idx]+1;j++)
    {
        int kol=j*a[idx];
        rez+=f(s-kol,idx+1);
    }
    return rez; //(dp[s][idx]=rez
}
 
signed main()
{
 
    cin>>n>>sum;
 
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    cout<<f(sum,0)<<endl;
 
    ///DP
 
    int dp[sum];
    memset(dp,0,sizeof dp);
    dp[0]=1;
 
 
    for(int s=sum;s>0;s--)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<sum/a[i]+1;j++)
            {
                int add=a[i]*j;
                if(s-add>=0)
                {
                    dp[s]+=dp[s-add];
 
                }
            }
        }
    }
    cout<<dp[sum]<<endl;
    /*
    Gresno
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(sum/a[i])+1;j++)
        {
            for(int s=sum;s>0;s--)
            {
                int add=a[i]*j;
                if(s-add>=0)
                {
                    dp[s]+=dp[s-add];
                    cout<<s<<" "<<add<<" "<<dp[s-add]<<endl;
                }
            }
        }
    }
    cout<<dp[sum]<<endl;*/
    return 0;
}