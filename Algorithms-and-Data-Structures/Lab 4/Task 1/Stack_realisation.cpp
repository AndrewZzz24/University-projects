#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n];
    long long atop=-1;
    long long num; char znak;
    for (int i=0; i<n; i++)
    {
        cin>>znak;
        if (znak=='+')
        {
            atop++;
            cin>>num;
            a[atop]=num;
        }
        else
        {
            cout<<a[atop]<<"\n";
            atop--;
        }
    }
}
