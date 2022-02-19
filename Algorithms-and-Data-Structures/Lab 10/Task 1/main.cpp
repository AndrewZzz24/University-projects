#include <iostream>
#include <vector>

void input(int &n, int &m, std::vector<int> &vert) {
    std::cin >> n >> m;
    vert.resize(n);
    for (size_t i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        vert[from - 1]++;
        vert[to - 1]++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    std::vector<int> vertexes;
    input(n, m, vertexes);
    for (size_t i = 0; i < vertexes.size(); i++) std::cout << vertexes[i] << ' ';
    std::cout << std::endl;
}