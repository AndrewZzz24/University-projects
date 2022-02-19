#include <iostream>
#include <vector>

std::vector<std::vector<int>> reversed_vertexes;
std::vector<int> type;

void
input(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result, int &num_of_vertexes,
      int &num_of_edges) {
    std::cin >> num_of_vertexes >> num_of_edges;
    int edge_start, edge_end;
    vertexes.resize(num_of_vertexes);
    reversed_vertexes.resize(num_of_vertexes);
    used.resize(num_of_vertexes);
    type.resize(num_of_vertexes);
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> edge_start >> edge_end;
        vertexes[edge_start - 1].push_back(edge_end - 1);
        reversed_vertexes[edge_end - 1].push_back(edge_start - 1);
    }
}

void DFS(int vertex, std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    used[vertex] = 1;
    for (int i = 0; i < vertexes[vertex].size(); i++) {
        int tmp = vertexes[vertex][i];
        if (!used[tmp])
            DFS(tmp, vertexes, used, result);
    }
    result.push_back(vertex);
}

void topological_sort(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    for (int i = 0; i < vertexes.size(); i++) {
        if (!used[i])
            DFS(i, vertexes, used, result);
    }
}

void DFS_cond(int num_of_comp, int vertex, std::vector<int> &used,
              std::vector<int> &result) {
    used[vertex] = 1;
    result[vertex] = num_of_comp;
    for (int i = 0; i < reversed_vertexes[vertex].size(); i++) {
        int tmp = reversed_vertexes[vertex][i];
        if (!used[tmp]) {
            DFS_cond(num_of_comp, tmp, used, result);
        }
    }

}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 4\\cond.in", "r",
//            stdin);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 4\\cond.out", "w",
//            stdout);
    std::vector<std::vector<int>> vertexes;
    std::vector<int> used;
    std::vector<int> result;
    int n, m, num_of_component = 1;
    input(vertexes, used, result, n, m);
    used.assign(n, 0);
    topological_sort(vertexes, used, result);
    used.assign(n, 0);
    std::vector<int> new_result;
    for (int i = n - 1; i > -1; i--) {
        new_result.push_back(result[i]);
    }
//    for (int i = 0; i < result.size(); i++) std::cout << result[i] << ' ';
//    std::cout << std::endl;
//    for (int i = 0; i < new_result.size(); i++) std::cout << new_result[i] << ' ';
//    std::cout << std::endl;
    result.clear();
    result.resize(n);
    result.assign(n, 0);
    for (int i = 0; i < new_result.size(); i++) {
        int tmp = new_result[i];
        if (!used[tmp]) {
            DFS_cond(num_of_component, tmp, used, result);
            num_of_component++;
        }
    }
    std::cout << num_of_component - 1 << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << ' ';
    std::cout << std::endl;

    return 0;
}