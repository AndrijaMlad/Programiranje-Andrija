#include <bits/stdc++.h>
 
using namespace std;
 
struct point
{
    double x;
    double y;
    double z;
};
 
double dist(point a,point b)
{
    return (double)sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y)+abs(a.z-b.z)*abs(a.z-b.z));
}
 
bool comp(point a,point b)
{
    if(a.x<b.x)
    {
        return true;
    }
    if(a.x==b.x)
    {
        if(a.y<b.y)
        {
            return true;
        }
        if(a.y==b.y)
        {
            if(a.z<b.z)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}
 
signed main()
{
    int n;
    cin>>n;
    vector<point>a;
    for(int i=0;i<n;i++)
    {
        point val;
        cin>>val.x>>val.y>>val.z;
        a.push_back(val);
    }
    sort(a.begin(),a.end(),comp);
    /*for(int i=0;i<a.size();i++)
    {
        cout<<a[i].x<< " "<<a[i].y<< " "<<a[i].z<<endl;
    }*/
    double l=0;
    double r=1000000;
    double e=1e-7;
    while(r-l>e)
    {
        double mid=l+(r-l)/2;
        bool ok=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[i].x-a[j].x>mid)
                {
                    break;
                }
                double D=dist(a[i],a[j]);
                if(D<=mid)
                {
                    ok=true;
                    break;
                }
            }
            if(ok)break;
        }
        if(ok)
        {
            r=mid;
        }
        else
        {
            l=mid+e;
        }
    }
    cout<<l<<endl;
    return 0;
}