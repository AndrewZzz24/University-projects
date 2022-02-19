#include <iostream>

using namespace std;
struct list1 {
    int data = 0, left = 0, right = 0;
    int left_height = 0, right_height = 0, balance = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    int n;
    cin >> n;
    struct list1 a[n + 1];
    if (n == 0) cout << 0;
    else {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].data >> a[i].left >> a[i].right;
        }
        for (int i = n; i > 0; i--) {
            if (a[i].left != 0) {
                a[i].left_height =max(a[a[i].left].left_height,a[a[i].left].right_height)+ 1;
            }
            if (a[i].right != 0) {
                a[i].right_height =max(a[a[i].right].right_height,a[a[i].right].left_height) + 1;
            }
            a[i].balance = a[i].right_height - a[i].left_height;
        }
        for (int i = 1; i <= n; i++) cout << a[i].balance << endl;
    }
}