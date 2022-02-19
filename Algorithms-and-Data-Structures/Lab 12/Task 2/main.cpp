#include <iostream>
#include <vector>

const int INF = 2e9;

int main() {

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> d(n + 1, INF);
    std::vector<int> parent(n + 1, -1);
    std::vector<int> pos(n + 1, -1);

    int lenght = 0;
    int index_start;

    d[0] = -INF;

    for (int i = 0; i < n; i++) {

        int index = i;
        int left = 0, right = n, middle;

        while (right - left != 1) {

            middle = (right + left) / 2;

            if (a[index] > d[middle])
                left = middle;
            else
                right = middle;
        }

        if (d[right - 1] < a[index] && a[index] < d[right]) {

            d[right] = a[index];
            pos[right] = index;
            parent[index] = pos[right - 1];
            lenght = std::max(lenght, right);

        }
    }

    std::vector<int> result;

    index_start = pos[lenght];

    while (index_start != -1) {

        result.push_back(a[index_start]);
        index_start = parent[index_start];

    }

    std::cout << result.size() << std::endl;

    for (int i = result.size() - 1; i >= 0; i--)
        std::cout << result[i] << ' ';

    std::cout << std::endl;

}