#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    long a[1000];
    int atop = -1, c = -1;
    string s, s1;
    getline(cin, s);
    for (int i=0; i<s.length();i++)
    {
        if (s[i]!=' ') {
            if ((i + 1 < s.length()) && (s[i + 1] != ' ')) {
                atop++;
                s1 = s[i + 1];
                a[atop] = -1 * stol(s1);
                i++;
            } else if ((s[i] != '+') && (s[i] != '*') && (s[i] != '-')) {
                atop++;
                s1 = s[i];
                a[atop] = stol(s1);
            } else {
                if (s[i] == '+') {
                    a[atop - 1] = a[atop - 1] + a[atop];
                    atop -= 1;
                }
                if (s[i] == '-') {
                    a[atop - 1] = a[atop - 1] - a[atop];
                    atop -= 1;
                }
                if (s[i] == '*') {
                    a[atop - 1] = a[atop - 1] * a[atop];
                    atop -= 1;
                }
            }
        }
    }
    cout<<a[atop];
}












    /*while(true)
    {
        int k=s.find(' ',c+1);
        s1=s.substr(c+1,k-c-1);
        c=k;
        if ((s1!="+")&&(s1!="*")&&(s1!="-"))
        {
            atop++;
            a[atop]=stol(s1);
        }
        else
        {
            if (s1=="+") {a[atop-1]=a[atop-1]+a[atop];atop-=1;}
            if (s1=="-") {a[atop-1]=a[atop-1]-a[atop];atop-=1;}
            if (s1=="*") {a[atop-1]=a[atop-1]*a[atop];atop-=1;}
        }
        if (k==-1) break;

    }
    cout<<a[atop];
}*/