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

void
find_circule(int vertex, std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    used[vertex] = -1;
    result.push_back(vertex);
    for (int i = 0; i < vertexes[vertex].size(); i++) {
        if (!used[vertexes[vertex][i]]) {
            find_circule(vertexes[vertex][i], vertexes, used, result);
        }
        if (used[vertexes[vertex][i]] == -1) {
            std::cout << "YES" << std::endl;
            int flag = 0;
            for (int j = 0; j < result.size(); j++) {
                if (result[j] == vertexes[vertex][i])
                    flag = 1;
                if (flag)
                    std::cout << result[j] + 1 << ' ';
            }
            exit(0);
        }
    }
    result.pop_back();
    used[vertex] = 1;
}

void preparations(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    for (int i = 0; i < vertexes.size(); i++) {
        if (!used[i])
            find_circule(i, vertexes, used, result);
    }
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 2\\cycle.in", "r", stdin);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 2\\cycle.out", "w", stdout);
    std::vector<std::vector<int>> vertexes;
    std::vector<int> used{0};
    std::vector<int> result;
    int n, m;
    input(vertexes, used, result, n, m);
    preparations(vertexes, used, result);
    std::cout << "NO" << std::endl;
    return 0;
}