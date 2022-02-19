#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int atop=-1,q;
    char a[10000];
    string s;
    while(cin>>s)
    {
        atop=-1;
        q=0;
        for (int i=0; i<s.length(); i++)
        {
            if ((s[i]=='(')||(s[i]=='[')) {
                atop++;
                a[atop] = s[i];
            }
            else {
                if (((s[i] == ')') && (a[atop] == '[')) || ((s[i] == ']') && (a[atop] == '('))||((atop==-1))) {
                    q = 1;
                    cout << "NO"<<endl;
                    break;
                }
                atop--;
            }
        }
        if ((atop==-1)&&(q!=1)) cout<<"YES"<<endl;
        else if (q!=1) cout<<"NO"<<endl;
    }

    return 0;
}
