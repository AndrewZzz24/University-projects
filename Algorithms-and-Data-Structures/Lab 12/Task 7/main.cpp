#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);

    std::vector<std::vector<int>> maxtrix;
    std::vector<int> a;

    int s, n;

    std::cin >> s >> n;

    a.resize(n + 1);

    for (int i = 1; i <= n; i++)
        std::cin >> a[i];


    for (int i = 0; i <= n; i++) {

        maxtrix.push_back({0});

        for (int j = 0; j <= s; j++)

            maxtrix[i].push_back(0);

    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= s; j++) {

            if (j >= a[i])
                maxtrix[i][j] = std::max(maxtrix[i - 1][j], maxtrix[i - 1][j - a[i]] + a[i]);

            else
                maxtrix[i][j] = maxtrix[i - 1][j];

        }

    }

//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < s; j++)
//            std::cout << maxtrix[i][j] << ' ';
//        std::cout << std::endl;
//    }

    std::cout << maxtrix[n][s] << std::endl;

    return 0;

}