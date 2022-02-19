#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#define int long long
const int inf = 2e18;

void input(int &n, int &m, std::vector<std::vector<std::pair<int, int>>> &vert_matrix) {

    std::ifstream fin("pathbgep.in");
    fin >> n >> m;

    vert_matrix.resize(n);

    for (size_t j = 0; j < m; j++) {

        int from, to, weight;
        fin >> from >> to >> weight;
        vert_matrix[from - 1].push_back(std::make_pair(weight, to - 1));
        vert_matrix[to - 1].push_back(std::make_pair(weight, from - 1));

    }

    fin.close();

}

void dijkstra(int &n, int &s, std::vector<std::vector<std::pair<int, int>>> &vertexes) {

    std::set<std::pair<int, int>> set;
    std::vector<int> distances;

    distances.assign(n, inf);
    set.insert(std::make_pair(0, s));
    distances[s] = 0;

    while (!set.empty()) {

        int vert = set.begin()->second;
        set.erase(set.begin());

        for (size_t i = 0; i < vertexes[vert].size(); i++) {
            auto &[w8, num_of_vert]=vertexes[vert][i];

            if (distances[vert] + w8 < distances[num_of_vert]) {

                set.erase(std::make_pair(distances[num_of_vert], num_of_vert));
                distances[num_of_vert] = distances[vert] + w8;
                set.insert(std::make_pair(distances[num_of_vert], num_of_vert));

            }

        }

    }

    std::ofstream fout("pathbgep.out");
    for (auto &i :distances)
        fout << i << ' ';

    fout << std::endl;
    fout.close();
}

signed main() {

    int n, m;
    std::vector<std::vector<std::pair<int, int>>> vect_matrix;

    input(n, m, vect_matrix);
    int num = 0;
    dijkstra(n, num, vect_matrix);

    return 0;

}