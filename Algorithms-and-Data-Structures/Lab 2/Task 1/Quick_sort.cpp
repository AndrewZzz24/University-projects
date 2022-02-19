#include <iostream>
#include <ctime>
using namespace std;
void quicksort(int a[],int levo,int pravo)
{
//  srand(time(0));
    //int k=1+rand() % pravo;
    //int k=a[(levo+pravo)/2];
    int k=pravo;
    int i,j,t;
    i=levo;
    j=pravo;
    while (i<=j)
    {
        while (a[i] < a[k]) i++;
        while (a[k] < a[j]) j--;
        if (i <= j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (levo<j) quicksort(a,levo,j);
    if (pravo>i) quicksort(a,i,pravo);
}

/*int partition(int a[],int first, int last )
{
    int t,i;
    i=first;
    /*for (int j=first+1; j<last; j++)
    {
        if (a[j]<=a[last]) {i++; t=a[i]; a[i]=a[j]; a[j]=t;}
    }
    return i+1;
}
void quicksort(int a[],int first, int last)
{
    if (first!=last)
    {   int q;
        q=partition(a,first,last);
        quicksort(a,first,q-1);
        quicksort(a,q+1,last);
    }
}*/
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=0; i<n; i++) cin>>a[i];
    quicksort(a,0,n-1);
    for (int i=0; i<n; i++) cout<<a[i]<<' ';
}