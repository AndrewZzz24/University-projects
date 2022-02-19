#include <iostream>

int main() {

    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);

    int a[1001][1001];
    int w, h, m;

    std::cin >> h >> w;
    m = h - 1;

    for (int i = 0; i < h; i++) {

        for (int z = 0; z < w; z++)
            std::cin >> a[i][z];

    }

    for (int i = 0; i < w; i++)
        a[m][i + 1] += a[m][i];

    for (int i = h - 1; i > 0; i--)
        a[i - 1][0] += a[i][0];

    for (int i = h - 2; i > -1; i--) {

        for (int z = 1; z < w; z++) {
            a[i][z] += std::max(a[i + 1][z], a[i][z - 1]);
        }

    }

    std::cout << a[0][w - 1];

    return 0;
}




