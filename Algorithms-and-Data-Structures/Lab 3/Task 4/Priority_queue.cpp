#include <iostream>
#include <string>
#include <string.h>
#include <io.h>
#include <vector>
using namespace std;
long long n1=-1;
struct Array1{
    long long index;
    long long num;
};
void insert1(vector<Array1> &a,long long k,long long count)
{
    a[n1+1].num=k;
    a[n1+1].index=count;
    long long i=n1+1;
    n1++;
    while ((i>0)&&(a[i].num<a[(i-1)/2].num))
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void recheck(vector<Array1> &a,long long k)
{
    long long i=k;
    while ((i>0)&&(a[i].num<a[(i-1)/2].num))
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
long long getmin1(vector<Array1> &a)
{
    long long min;
    min=a[0].num;
    a[0]=a[n1];
    n1--;
    long long i=0;
    while (true) {
        long long j=i;
        if ((a[2*i+1].num < a[j].num) && (2*i+1 <= n1)) j = 2*i+1;
        if ((a[2*i+2].num < a[j].num) && (2*i+2 <= n1)) j = 2*i+2;
        if (j != i) swap(a[i], a[j]);
        else break;
        i=j;
    }
    return min;
}


int main() {
    freopen("priorityqueue.in","r",stdin);
    freopen("priorityqueue.out","w",stdout);
    string s,s1,s2,s3;
    int count=0;
    vector<Array1> a(1000000);
    while (getline(cin,s))
    {
        count++;
        long long i=s.find(" ");
        s1.append(s,0,i);
        long long i1=s.find("\0");
        s2.append(s,i+1,i1-1);
        if (s1=="push")
        {
            long long k=stoll(s2);
            insert1(a,k,count);
        }
        if (s1=="extract-min")
        {
            if (n1==-1) cout<<"*"<<"\n";
            else cout<<getmin1(a)<<"\n";
        }
        if (s1=="decrease-key")
        {
            i=s2.find(" ");
            i1=s2.find("\0");
            s3.append(s2,i+1,i1-1);
            s2.erase(i);
            long long k=stoll(s2),k1=stoll(s3);
            for (int q=0; q<=n1;q++)

                if (a[q].index == k) {
                    a[q].num = k1;
                    recheck(a, q);
                    break;
                }


        }
        s1.erase(0);
        s2.erase(0);
        s3.erase(0);
    }

    return 0;
}