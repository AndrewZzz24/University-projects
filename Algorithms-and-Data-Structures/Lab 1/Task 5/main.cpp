#include <iostream>
#include <vector>

void bubble_sort(std::vector<std::pair<int, double>> &arr) {

    for (size_t i = 0; i < arr.size(); i++) {

        for (size_t j = 0; j < arr.size() - 1; j++)

            if (arr[j].second > arr[j + 1].second)

                std::swap(arr[j], arr[j + 1]);

    }

}

int main() {

    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);

    std::vector<std::pair<int, double>> arr;
    int n;

    std::cin >> n;
    arr.resize(n);

    for (auto i = 0; i < n; i++) {

        std::cin >> arr[i].second;
        arr[i].first = i + 1;

    }

    bubble_sort(arr);

    std::cout << arr[0].first << ' ' << arr[n / 2].first << ' ' << arr[n - 1].first << std::endl;

    return 0;

}