#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

//#define int long long
const long long inf = 2e18;

struct Edge {
    long long from_;
    long long to_;
    long long weight_;
};

void input(int &n, std::vector<Edge> &edges) {

    std::cin >> n;

    for (int j = 0; j < n; j++) {

        for (int i = 0; i < n; i++) {

            int tmp_num;
            std::cin >> tmp_num;
            if (tmp_num != std::pow(10, 9)) {
                Edge tmp{};
                tmp.to_ = i;
                tmp.from_ = j;
                tmp.weight_ = tmp_num;
                edges.push_back(tmp);
            }
        }
    }

}

void Ford_Bellman_algorithm(int &n, int &s, std::vector<Edge> &edges) {

    std::vector<long long> distances;
    std::vector<long long> p;
    distances.assign(n, inf);
    p.assign(n, -1);
    distances[s] = 0;

    for (int i = 0; i < n; i++) {

        for (auto &edge : edges) {

            long long from = edge.from_;
            long long to = edge.to_;
            long long weight = edge.weight_;

            if (distances[from] + weight < distances[to]) {
                distances[to] = distances[from] + weight;
                p[to] = from;
            }

        }
    }
    std::vector<long long> answer;
    for (auto &edge : edges) {

        if (distances[edge.to_] > edge.weight_ + distances[edge.from_]) {

            for (int i = 0; i < n; i++)
                edge.to_ = p[edge.to_];

            edge.from_ = edge.to_;

            for (edge.from_ = edge.to_;; edge.from_ = p[edge.from_]) {

                answer.push_back(edge.from_);

                if (edge.from_ == edge.to_ && answer.size() > 1)
                    break;

            }

            std::reverse(answer.begin(), answer.end());

            std::cout << "YES" << std::endl << answer.size() << std::endl;

            for (auto &i: answer)
                std::cout << i + 1 << ' ';

            std::cout << std::endl;
            exit(0);
        }
    }
    std::cout << "NO" << std::endl;

}


signed main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, num = 0;

    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w",
            stdout);

    std::vector<Edge> edges;

    input(n, edges);
    Ford_Bellman_algorithm(n, num, edges);

    return 0;

}