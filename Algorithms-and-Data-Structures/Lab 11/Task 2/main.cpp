#include <iostream>
#include <vector>

#define int long long
const int inf = 2e18;

void input(int &n, int &m, std::vector<std::vector<std::pair<int, int>>> &vert_matrix) {

    std::cin >> n >> m;

    vert_matrix.resize(n);

    for (size_t j = 0; j < m; j++) {

        int from, to, weight;
        std::cin >> from >> to >> weight;
        vert_matrix[from - 1].push_back(std::make_pair(to - 1, weight));

    }


}

void dijkstra(int &n, int &m, int &s, std::vector<std::vector<std::pair<int, int>>> &vertexes) {

    std::vector<int> distances;
    distances.assign(n, inf);
    std::vector<bool> used;
    used.assign(n, false);

    distances[s] = 0;

    for (size_t i = 0; i < n; i++) {

        int minvert = -1;

        for (size_t j = 0; j < n; j++)

            if (!used[j] && (minvert == -1 || distances[minvert] > distances[j]))
                minvert = j;

        if (distances[minvert] == inf)
            break;

        used[minvert] = true;

        for (size_t k = 0; k < vertexes[minvert].size(); k++)

            if (((distances[minvert] + vertexes[minvert][k].second) < distances[vertexes[minvert][k].first]))

                distances[vertexes[minvert][k].first] = distances[minvert] + vertexes[minvert][k].second;

    }

    for (auto &i :distances)
        std::cout << i << ' ';

    std::cout << std::endl;

}

signed main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m;

    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    std::vector<std::vector<std::pair<int, int>>> vect_matrix;

    input(n, m, vect_matrix);

    for (int i = 0; i < n; i++)
        dijkstra(n, m, i, vect_matrix);

    return 0;
}