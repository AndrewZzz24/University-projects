#include <iostream>
#include <queue>
using namespace std;
struct node {
    long long data = 0, left = 0, right = 0;
    long long left_height = 0, right_height = 0, balance = 0;
};
void make_balance(node a[],long long n){
    for (long long i = n; i > 0; i--) {
        if (a[i].left != 0) {
            a[i].left_height =max(a[a[i].left].left_height,a[a[i].left].right_height)+ 1;
        }
        if (a[i].right != 0) {
            a[i].right_height =max(a[a[i].right].right_height,a[a[i].right].left_height) + 1;
        }
        a[i].balance = a[i].right_height - a[i].left_height;
    }

}
long long small_left_rotation(node a[],long long p){
    long long n1=a[a[p].right].left;
    long long root=a[p].right;
    a[a[p].right].left=p;
    a[p].right=n1;
    return root;
}
long long big_left_rotation(node a[],long long p){
    long long root=a[a[p].right].left;
    long long tmp1=a[root].left;
    long long tmp2=a[root].right;
    a[root].left=p;
    a[root].right=a[p].right;
    a[a[root].right].left=tmp2;
    a[p].right=tmp1;
    return root;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
    long long n;
    cin >> n;
    long long root=1;
    node a[n + 1];
    if (n == 0) cout << 0;
    else {
        cout<<n<<endl;
        for (long long i = 1; i <= n; i++) {
            cin >> a[i].data >> a[i].left >> a[i].right;
        }
        make_balance(a,n);
        if (a[a[root].right].balance==-1)root=big_left_rotation(a,root);
        else root=small_left_rotation(a,root);
        queue<long long>a1;
        queue<node>value;
        a1.push(root);
        while (!a1.empty()){
            node k=a[a1.front()];
            a1.pop();
            if (k.left!=0){
                a1.push(k.left);
            }
            if (k.right!=0){
                a1.push(k.right);
            }
            value.push(k);
        }
        long long k=2;
        for (long long i = 1; i <= n; i++) {
            cout << value.front().data << ' ';
            if ((value.front().left != 0)/*&&(k<=n+1)*/) {
                cout << k << ' ';
                k++;
            } else cout << "0 ";
            if ((value.front().right != 0)/*&&(k<=n)*/) {
                cout << k;
                k++;
            } else cout << "0";
            cout << endl;
            value.pop();
        }
    }
}