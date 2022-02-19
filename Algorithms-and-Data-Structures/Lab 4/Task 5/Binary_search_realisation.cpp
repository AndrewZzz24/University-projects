#include <iostream>
#include <string>
using namespace std;
void binsearchleft(long long a[],long long l, long long r,long long k)
{
    while (r>l+1)
    {
        long long mid=(r+l)/2;
        if (a[mid]>=k) r=mid;
        else  l=mid;
    }
    if (a[l+1]!=k) cout<<-1<<' ';
    else cout<<l+2<<' ';
}
void binsearchright(long long a[],long long l, long long r,long long k)
{
    while (r>l+1)
    {
        long long mid=(r+l)/2;
        if (a[mid]>k) r=mid;
        else l=mid;
    }
    if (a[r-1]!=k) cout<<-1<<endl;
    else cout<<r<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    long long n;
    cin>>n;
    long long a[n+1];
    for (long long i=0; i<n; i++) cin>>a[i];
    long long m,k;
    cin>>m;
    long long l=-1,r=n;
    for (long long i=0; i<m; i++)
    {
        cin>>k;
        binsearchleft(a,l,r,k);
        binsearchright(a,l,r,k);
    }
}
