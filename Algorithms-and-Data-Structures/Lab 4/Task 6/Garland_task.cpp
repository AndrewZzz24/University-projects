#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("garland.in", "r", stdin);
    //freopen("garland.out", "w", stdout);
    int n;
    cin>>n;
    double a[n];
    cin>>a[0]; int q;
    double r=a[0], l=0;
    while (r>l+0.000000001)
    {
        q=0;
        a[1]=(double)(r+l)/2;
        for (int i=2; i<n; i++)
        {
            a[i]=2*a[i-1]-a[i-2]+2;
            if (a[i]<0) {q=1; break;}
        }
        if (q==0) r=a[1];
        else l=a[1];
    }
    printf("%.2lf",a[n-1]);
}
