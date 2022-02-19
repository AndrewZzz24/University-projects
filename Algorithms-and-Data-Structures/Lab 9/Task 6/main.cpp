#include <iostream>
#include <vector>

void
input(std::vector<std::vector<unsigned short>> &vertexes, int &num_of_vertexes, int &num_of_edges, int &start) {
    std::cin >> num_of_vertexes >> num_of_edges >> start;
    int edge_start, edge_end;
    vertexes.resize(num_of_vertexes);
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> edge_start >> edge_end;
        vertexes[edge_start - 1].push_back(edge_end - 1);
    }
}

void
DFS(int vertex, int way, std::vector<std::vector<unsigned short>> &vertexes, int &final_vertexes) {
    if (vertexes[vertex].empty()) {
        if (way < final_vertexes)
            final_vertexes = way;
    }
    if (way + 1 <= final_vertexes) {
        for (int i = 0; i < vertexes[vertex].size(); i++) {
            DFS(vertexes[vertex][i], way + 1, vertexes, final_vertexes);
        }
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 6\\game.in", "r",
//            stdin);
//    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 6\\game.out", "w",
//            stdout);
    std::vector<std::vector<unsigned short>> vertexes;
    int n, m, s, final_vertexes = 1000000;
    input(vertexes, n, m, s);
    DFS(s - 1, 0, vertexes, final_vertexes);
    if (final_vertexes % 2 != 0)
        std::cout << "First player wins" << std::endl;
    else
        std::cout << "Second player wins" << std::endl;
    return 0;
}