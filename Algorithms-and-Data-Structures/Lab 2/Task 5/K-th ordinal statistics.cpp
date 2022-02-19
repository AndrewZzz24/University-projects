#include <iostream>
#include <vector>

using namespace std;

void sort1(vector<int> &a, int l, int r, int k)
{
    while (r - l >= 1)
    {
        int x = a[l];
        int i = l, j = r;
        while (i <= j)
        {
            while (a[i] < x) i++;
            while (a[j] > x) j--;
            if (i <= j)
                swap(a[i++], a[j--]);
        }
        if (k > j) l = i;
        if (k < i) r = j;
    }
}

int main()
{
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int A, B, C;
    vector<int> a(n);
    cin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++) a[i] = A * a[i - 2] + B * a[i - 1] + C;
    k--;
    sort1(a, 0, n - 1, k);
    cout << a[k];
    return 0;
}