#include <iostream>
#include <vector>

#define int long long
const int inf = 2e18;

void input(int &n, int &s, int &f, std::vector<std::vector<int>> &vert_matrix) {

    std::cin >> n >> s >> f;
    s--;
    f--;
    vert_matrix.resize(n);
    for (size_t i = 0; i < n; i++) {

        for (size_t j = 0; j < n; j++) {

            int tmp;
            std::cin >> tmp;
            if (tmp == -1) tmp = 0;
            vert_matrix[i].push_back(tmp);

        }

    }

}

void dijkstra(int &n, int &s, int &f, std::vector<std::vector<int>> &vertexes) {

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

            if (((distances[minvert] + vertexes[minvert][k]) < distances[k]) && vertexes[minvert][k] != 0)

                distances[k] = distances[minvert] + vertexes[minvert][k];

    }

    if (distances[f] == inf)
        std::cout << -1 << std::endl;
    else
        std::cout << distances[f] << std::endl;

}

signed main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n = 0, s, f;

    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);

    std::vector<std::vector<int>> vect_matrix;

    input(n, s, f, vect_matrix);
    dijkstra(n, s, f, vect_matrix);

    return 0;
}