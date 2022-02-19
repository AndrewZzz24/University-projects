#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void merge(int a[], int levo, int sred, int pravo)
{
    int d1,d2,x=0,y=0,q=-1;
    d1=sred-levo+1;
    d2=pravo-sred;
    int lv[d1+1];
    int pr[d2+1];
    for (int i=0; i<d1; i++) lv[i]=a[levo+i];
    for (int i=0; i<d2; i++) pr[i]=a[sred+i+1];
    for(int i=levo; q!=i ;i++)
    {   if ((x==d1)||(y==d2)) {q=i; break;}
        if (lv[x]<pr[y]) {a[i]=lv[x]; x++;}
        else {a[i]=pr[y];y++;}
    }
    while (x<d1) {a[q]=lv[x]; x++;q++;}
    while (y<d2) {a[q]=pr[y]; y++;q++;}
}
void mergesort(int a[], int levo , int pravo)
{
    if (levo!=pravo)
    {   int sred;
        sred=(levo+(pravo))/2;
        mergesort(a,levo,sred);
        mergesort(a,sred+1,pravo);
        merge(a,levo,sred,pravo);
    }

}

int main()
{
    int n,levo,pravo;
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    int a[n+1];
    //a.reserve(n+1);
    for(int i=0; i<n; i++) cin>>a[i];
    levo=0; pravo=n-1;
    mergesort(a,levo,pravo);
    for (int i=0; i<n; i++) cout<<a[i]<<' ';
}