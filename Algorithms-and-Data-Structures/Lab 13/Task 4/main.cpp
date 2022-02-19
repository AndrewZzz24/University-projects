#include <iostream>
#include <vector>
#include <string>

int main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::vector<int> pi;
    int n1;
    
    std::cin >> n1;
    std::cin >> s;

    pi.assign(s.length() + 1, 0);

    int n = (int) s.length();
    int i = 1, j = 0;

    while (i < n) {

        if (s[i] == s[j]) {

            pi[i + 1] = j + 1;
            i++;
            j++;

        } else {

            if (j > 0)
                j = pi[j];

            else {

                pi[i + 1] = 0;
                i++;

            }

        }
    }

    std::vector<std::vector<std::pair<char, int>>> answers(pi.size() + 1,
                                                           std::vector<std::pair<char, int>>(n1, {0, 0}));
    for (int q = 0; q < (int) pi.size(); q++) {

        char current_char = 'a';

        for (int iterration = 0; iterration < n1; iterration++) {

            if (s[q] == current_char + iterration) {

                std::cout << q + 1 << ' ';
                answers[q][iterration] = {current_char + iterration, q + 1};

            } else {

                int res = answers[pi[q]][iterration].second;
                std::cout << res << ' ';
                answers[q][iterration] = {current_char + iterration, res};

            }
        }

        std::cout << std::endl;
    }

}