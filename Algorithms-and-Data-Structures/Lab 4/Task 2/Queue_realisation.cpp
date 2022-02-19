#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1]; char znak; int num;
    int ahead=0,atail=0;
    for (int i=0; i<n; i++)
    {
        cin>>znak;
        if (znak=='+')
        {
            cin>>num;
            if (atail==n) atail=0;
            a[atail]=num;
            atail++;
        }
        else
        {
            if (ahead==n) ahead=0;
            cout<<a[ahead]<<"\n";
            ahead++;
        }
    }
}