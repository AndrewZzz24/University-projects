#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;
std::vector<std::vector<int>> d;
std::vector<bool> used;
std::vector<int> used2;
int n, start;

void DFS(int v) {

    for (int i : matrix[v])
        DFS(i);

    if (!matrix[v].empty()) {

        d[v][1] = 0;
        d[v][0] = 0;

        for (int i : matrix[v]) {

            if (!used2[i]) {

                used2[i] = true;
                d[v][1] += d[i][0];
                d[v][0] += std::max(d[i][0], d[i][1]);

            }
        }

        d[v][1]++;

    } else {

        d[v][1] = 1;
        d[v][0] = 0;

    }

}

int main() {

    std::cin >> n;

    matrix.resize(n);
    used.assign(n, false);
    used2.assign(n, false);

    for (int i = 0; i < n; i++) {

        d.push_back({0, 0});
        int tmp;

        std::cin >> tmp;


        if (tmp == 0)
            start = i;

        else {
            tmp--;
            matrix[tmp].push_back(i);
        }

    }

    DFS(start);

    std::cout << std::max(d[start][1], d[start][0]) << std::endl;

}