#include <iostream>
#include <vector>
#include <algorithm>

class Edges {

private:
    long long left_end;
    long long right_end;
    long long weight;

public:

    Edges(long long &l, long long &r, long long &w) : left_end(l), right_end(r), weight(w) {}

    long long getLE() const {

        return left_end;

    };

    long long getRE() const {

        return right_end;

    }

    long long getW() const {

        return weight;

    }

    friend bool operator>(Edges &lhs, Edges &rhs) {

        return lhs.weight > rhs.right_end;

    }

    friend bool operator<(Edges &lhs, Edges &rhs) {

        return rhs.weight > lhs.weight;

    }

    friend bool operator==(Edges &lhs, Edges &rhs) {

        return lhs.weight == rhs.weight;

    }

};

void input(long long &n, long long &m, std::vector<Edges> &edges) {

    std::cin >> n >> m;

    for (size_t i = 0; i < m; i++) {

        long long from, to, weight;

        std::cin >> from >> to >> weight;

        from--;
        to--;
        edges.emplace_back(from, to, weight);

    }

}

long long find_min_mst(long long &n, long long &m, std::vector<Edges> &edges) {

    long long count = 0;
    long long result = 0;
    std::vector<long long> sets(n);
    std::vector<long long> num_of_comp;
    num_of_comp.assign(n, 1);

    for (size_t i = 0; i < n; i++)
        sets[i] = i;

    std::sort(edges.begin(), edges.end());

    for (auto &edge : edges) {

        if (count == n - 1)
            break;

        long long left_ed = edge.getLE();
        long long right_ed = edge.getRE();

        if (sets[left_ed] != sets[right_ed]) {

            count++;
            result += edge.getW();
            if (num_of_comp[left_ed] == 1) {

                sets[left_ed] = sets[right_ed];
                num_of_comp[right_ed]++;
                num_of_comp[left_ed]++;
                continue;

            }

            if (num_of_comp[right_ed] == 1) {

                sets[right_ed] = sets[left_ed];
                num_of_comp[right_ed]++;
                num_of_comp[left_ed]++;
                continue;

            }

            long long set1 = sets[left_ed];
            long long set2 = sets[right_ed];
            long long f = left_ed;

            if (num_of_comp[left_ed] < num_of_comp[right_ed]) {

                set1 = sets[right_ed];
                set2 = sets[left_ed];
                f = right_ed;

            }

            for (auto &j : sets) {

                if (j == set2) {

                    num_of_comp[f]++;
                    j = set1;

                }

            }

        }

    }

    return result;

}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    freopen("spantree3.in", "r",
            stdin);
    freopen("spantree3.out", "w",
            stdout);

    long long n, m;
    std::vector<Edges> edges;

    input(n, m, edges);
    std::cout << find_min_mst(n, m, edges) << std::endl;

    return 0;

}