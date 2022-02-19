#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#define int long long
const long long inf = 9e18;

struct Edge {
    int from_;
    int to_;
    int weight_;
};

void input(int &n, int &m, int &s, std::vector<Edge> &edges, std::vector<std::vector<int>> &vert_matrix) {

    std::cin >> n >> m >> s;
    s--;
    vert_matrix.resize(n);
    for (size_t i = 0; i < m; i++) {

        int from, to, weight;

        std::cin >> from >> to >> weight;

        Edge tmp_edge{};
        tmp_edge.to_ = to - 1;
        tmp_edge.from_ = from - 1;
        tmp_edge.weight_ = weight;

        edges.push_back(tmp_edge);
        vert_matrix[from - 1].push_back(to - 1);

    }

}

void DFS(std::vector<bool> &usd_vert, int vert, std::vector<std::vector<int>> &vert_matrix) {
    usd_vert[vert] = true;
    for (auto &v : vert_matrix[vert]) {
        if (!usd_vert[v])
            DFS(usd_vert, v, vert_matrix);
    }
}

void Ford_Bellman_algorithm(int &n, int &s, std::vector<Edge> &edges, std::vector<std::vector<int>> &vert_matrix) {

    std::vector<long long> distances;
    std::vector<bool> used;
    std::vector<bool> negcycle;
    negcycle.assign(n, false);
    used.assign(n, false);
    distances.assign(n, inf);
    distances[s] = 0;

    for (int i = 0; i < n; i++) {

        for (auto &edge : edges) {

            long long from = edge.from_;
            long long to = edge.to_;
            long long weight = edge.weight_;

            if (distances[from] < inf && (distances[from] + weight < distances[to])) {
                distances[to] = std::max(-1 * inf, distances[from] + weight);
            }

        }
    }

    for (auto &edge : edges) {

        if (distances[edge.from_] < inf && distances[edge.to_] > edge.weight_ + distances[edge.from_])
            DFS(used, edge.to_, vert_matrix);

    }

    for (size_t index = 0; index < used.size(); index++)

        if (used[index])
            distances[index] = -1 * inf;

    for (auto &dist : distances) {

        if (dist == -1 * inf)
            std::cout << '-' << std::endl;
        else if (dist == inf)
            std::cout << '*' <<
                      std::endl;
        else
            std::cout << dist <<
                      std::endl;
    }

}


signed main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m, s;

    freopen("path.in", "r", stdin);
    freopen("path.out", "w",
            stdout);

    std::vector<Edge> edges;
    std::vector<std::vector<int>> vert_matrix;
    input(n, m, s, edges, vert_matrix);
    Ford_Bellman_algorithm(n, s, edges, vert_matrix);

    return 0;

}