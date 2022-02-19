#include <iostream>
#include <string>
#include <vector>
using namespace std;
void bublesort(vector<string> &a,long long s)
{
    for (int i=0; i<a.size(); i++)
    {
        for (int j=0; j<a.size()-1;j++)
            if (a[j][s]>a[j+1][s]) swap(a[j],a[j+1]);
    }
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> a(n),b(n);
    vector<long long> c(n);
    long long k1=m-1;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0;i<k;i++)
        bublesort(a,k1-i);
    for (int i=0; i<n; i++)
        cout <<a[i]<<"\n";

}
