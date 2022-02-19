#include <iostream>
struct list1{
    long long data=0;
    long long left=0,right=0;
};
int q=0;
void listcheck(struct list1 a[],long long p,long long min, long long max){
    if ((a[p].data<max)&&(a[p].data>min))
    {
        if (a[p].left!=0) listcheck(a,a[p].left,min,a[p].data);
        if (a[p].right!=0)listcheck(a,a[p].right,a[p].data,max);
    }
    else {q=1; return;}

}
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("check.in","r",stdin);
    freopen("check.out","w",stdout);
    long long n;
    cin>>n;
    struct list1 a[n+1];
    for (long long i=1; i<n+1;i++)
        cin>>a[i].data>>a[i].left>>a[i].right;
    if (n==0) cout<<"YES";
    else {
        listcheck(a,1,-10000000001,10000000001);
        if (q==1) cout<<"NO";
        else cout<<"YES";
        q=0;
    }
    return 0;
}
