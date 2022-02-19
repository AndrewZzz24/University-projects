#include <iostream>
#include <vector>

void
input(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result, int &num_of_vertexes,
      int &num_of_edges) {
    std::cin >> num_of_vertexes >> num_of_edges;
    int edge_start, edge_end;
    vertexes.resize(num_of_vertexes);
    used.resize(num_of_vertexes);
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> edge_start >> edge_end;
        vertexes[edge_start - 1].push_back(edge_end - 1);
    }
}

void DFS(int vertex, std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    used[vertex] = 1;
    for (int i = 0; i < vertexes[vertex].size(); i++) {
        int tmp = vertexes[vertex][i];
        if (!used[tmp]) {
            DFS(tmp, vertexes, used, result);
        }
    }
    result.push_back(vertex);
}

void
preparations(std::vector<std::vector<int>> &vertexes, std::vector<int> &used,
             std::vector<int> &result) {
    for (int i = 0; i < vertexes.size(); i++) {
        if (!used[i]) {
            DFS(i, vertexes, used, result);
        }
    }
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 5\\hamiltonian.in", "r",
//            stdin);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 5\\hamiltonian.out", "w",
//            stdout);
    std::vector<std::vector<int>> vertexes;
    std::vector<int> used;
    std::vector<int> result;
    int n, m;
    input(vertexes, used, result, n, m);
    preparations(vertexes, used, result);
    for (unsigned int i = result.size() - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < vertexes[result[i]].size(); j++) {
            if (vertexes[result[i]][j] == result[i - 1])
                flag = true;
        }
        if (!flag) {
            std::cout << "NO" << std::endl;
            exit(0);
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}