#include <iostream>
#include <vector>

int main() {

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> d(n);
    std::vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {

        d[i] = 1;

        for (int j = 0; j < i; j++)

            if (a[j] < a[i]) {

                d[i] = std::max(d[i], d[j] + 1);

                if (d[i] == d[j] + 1)
                    parent[i] = j;

            }

    }

    int maximum = -1, index = -1;

    for (int i = 0; i < n; i++)

        if (d[i] > maximum) {

            maximum = d[i];
            index = i;

        }

    std::cout << maximum << std::endl;
    std::vector<int> result;
    while (true) {

        result.push_back(a[index]);
        index = parent[index];

        if (index == -1)
            break;

    }

    for (int i = result.size() - 1; i > -1; --i)
        std::cout << result[i] << ' ';

    std::cout << std::endl;

}