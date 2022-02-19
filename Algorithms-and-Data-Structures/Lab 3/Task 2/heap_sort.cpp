#include <iostream>
#include <vector>
using namespace std;
void heapsort1(vector<long long> &a, long long n, long long i)
{
    long long largest=i,l=2*i+1,r=2*i+2;
    if ((l < n) && (a[l] > a[largest])) largest = l;
    if ((r < n) && (a[r] > a[largest])) largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapsort1(a, n, largest);
    }
}
void heapsort(vector<long long > &a, long long n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapsort1(a, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        heapsort1(a, i, 0);
    }
}


int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    long long n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    heapsort(a,n);
    for (int i=0; i<n; i++)cout<<a[i]<<' ';
}