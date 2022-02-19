#include <iostream>
using namespace std;
int main() {
        int n,t;
        cin>>n;
        int a[n+1];
        for (int i=0;i<n;i++) a[i]=i+1;
        for (int i=0;i<n;i++)
        {
            t=a[i];
            a[i]=a[i/2];
            a[i/2]=t;
        }
        for (int i=0;i<n;i++)cout<<a[i]<<' ';

}
