#include <iostream>
long long sum=0;
using namespace std;
void merge(long long a[], long long levo, long long sred, long long pravo)
{
    long long d1,d2,x=0,y=0,q=-1;
    d1=sred-levo+1;
    d2=pravo-sred;
    long long lv[d1];
    long long pr[d2];
    for (long long i=0; i<d1; i++) lv[i]=a[levo+i];
    for (long long i=0; i<d2; i++) pr[i]=a[sred+i+1];
    for(long long i=levo; q!=i ;i++)
    {   if ((x==d1)||(y==d2)) {q=i; break;}
        if (lv[x]<=pr[y])
            {
            a[i]=lv[x];
            sum+=i-levo-x;
            x++;
            }
        else
            {
            a[i]=pr[y];
            y++;
            }
    }
    while (x<d1)
    {
        a[q]=lv[x];
        sum+=q-levo-x;
        x++;
        q++;
    }
    while (y<d2)
    {
        a[q]=pr[y];
        y++;
        q++;
    }
}
void mergesort(long long a[], long long levo , long long pravo)
{
    if (levo!=pravo)
    {   long long sred;
        sred=(levo+(pravo))/2;
        mergesort(a,levo,sred);
        mergesort(a,sred+1,pravo);
        merge(a,levo,sred,pravo);
    }

}
int main() {
    freopen("inversions.in","r",stdin);
    freopen("inversions.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+1];
    for (long long i=0;i<n;i++) cin>>a[i];
    mergesort(a,0,n-1);
    cout<<sum;
}