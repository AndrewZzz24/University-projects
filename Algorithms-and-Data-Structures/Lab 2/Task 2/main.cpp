#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct racer
{
    string country;
    string name;
};


void merge(vector<racer> &a, long long levo, long long sred, long long pravo)
{
    long long d1,d2,x=0,y=0,q=-1;
    d1=sred-levo+1;
    d2=pravo-sred;
    vector<racer> lv(d1+1);
    vector<racer> pr(d2+1);
    for (long long i=0; i<d1; i++) lv[i]=a[levo+i];
    for (long long i=0; i<d2; i++) pr[i]=a[sred+i+1];
    for(long long i=levo; q!=i ;i++)
    {   if ((x==d1)||(y==d2)) {q=i; break;}
        if (lv[x].country<=pr[y].country) {a[i]=lv[x]; x++;}
        else {a[i]=pr[y];y++;}
    }
    while (x<d1) {a[q]=lv[x]; x++;q++;}
    while (y<d2) {a[q]=pr[y]; y++;q++;}
}
void mergesort(vector<racer> &a, long long levo , long long pravo)
{
    if (levo!=pravo)
    {   long long sred;
        sred=(levo+(pravo))/2;
        mergesort(a,levo,sred);
        mergesort(a,sred+1,pravo);
        merge(a,levo,sred,pravo);
    }

}

int main(){
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    long long n;
    string k;
    cin>>n;
    vector<racer> a(n);
    for (long long i=0; i<n; i++) cin>>a[i].country>>a[i].name;
    mergesort(a,0,n-1);
    cout<<"=== "<<a[0].country<<" ===\n";
    cout<<a[0].name<<"\n";
    for (long long i=1; i<n; i++)
    {
        if (a[i].country==a[i-1].country) cout<<a[i].name<<"\n";
        else
        {
            cout<<"=== "<<a[i].country<<" ===\n";
            cout<<a[i].name<<"\n";
        }
    }
    return 0;
}