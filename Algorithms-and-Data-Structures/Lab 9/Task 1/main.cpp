#include <iostream>
#include <vector>

void
input(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result, int &num_of_vertexes,
      int &num_of_edges) {
    std::cin >> num_of_vertexes >> num_of_edges;
    int edge_start, edge_end;
    vertexes.resize(num_of_vertexes + 1);
    used.resize(num_of_vertexes + 1);
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> edge_start >> edge_end;
        vertexes[edge_start - 1].push_back(edge_end - 1);
    }
}

void DFS(int vertex, std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    used[vertex] = -1;
    for (int i = 0; i < vertexes[vertex].size(); i++) {
        int tmp = vertexes[vertex][i];
        if (!used[tmp]) {
            DFS(vertexes[vertex][i], vertexes, used, result);
        }
        if (used[tmp] == -1) {
            std::cout << -1 << std::endl;
            exit(0);
        }
    }
    used[vertex] = 1;
    result.push_back(vertex);
}

void topological_sort(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    for (int i = 0; i < vertexes.size(); i++) {
        if (!used[i]) {
            DFS(i, vertexes, used, result);
        }
    }
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    std::vector<std::vector<int>> vertexes;
    std::vector<int> used{0};
    std::vector<int> result;
    int n, m;
    input(vertexes, used, result, n, m);
    topological_sort(vertexes, used, result);
    for (int i = n - 1; i > -1; i--) {
        std::cout << result[i] + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}