#include <iostream>
using namespace std;
struct list1{
    int data=0,left=0,right=0;
};
int maxlength=0;
void listlenght(struct list1 a[],int pointer,int length)
{
    if (pointer!=0)
    {
        length++;
        if (length>maxlength) maxlength=length;
        listlenght(a,a[pointer].left,length);
        listlenght(a,a[pointer].right,length);
    }
    //return length;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("height.in","r",stdin);
    freopen("height.out","w",stdout);
    int sum=0,n,k,l,r;
    cin >> n;
    struct list1 a[n+1];
    if (n==0) cout<<0;
    else {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].data >> a[i].left >> a[i].right;
        }
        listlenght(a, 1, 0);
        cout << maxlength;
    }
}

