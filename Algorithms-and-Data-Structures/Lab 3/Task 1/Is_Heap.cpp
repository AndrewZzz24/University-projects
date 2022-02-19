#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("isheap.in","r",stdin);
    freopen("isheap.out","w",stdout);
    vector<long long> a;
    int n,q=0;
    cin>>n;
    a.reserve(n+1);
    for(int i=1; i<=n;i++)cin>>a[i];
    for(int i=1; 2*i<=n; i++)
    {
        if ((2*i<=n)&&(a[i]>a[2*i])) {q=1; break;}
        if ((2*i+1<=n)&&(a[i]>a[2*i+1])) {q=1; break;}
    }
    if (q==0) cout<<"YES";
    else cout<<"NO";
}