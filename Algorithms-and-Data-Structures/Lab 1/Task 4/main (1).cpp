#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("smallsort.in","r",stdin);
    freopen("smallsort.out","w",stdout);
    int n,t;
    cin>>n;
    vector <int> a;
    a.reserve(n+1);
    cin>>a[0];
    for (int i=1; i<n; i++)
    {
        cin>>t;
        for(int z=i-1; z>=0;z--)
            if (t<a[z]) {a[z+1]=a[z];a[z]=t;}
            else { a[z+1]=t; break;}
       // if (q==0) a[i]=t;
    }



    for (int i=0; i<n; i++) cout<<a[i]<<' ';
}