#include <iostream>
#include <vector>
#include <string>

int main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    std::string s1, s2, s;
    std::vector<int> pi;

    std::cin >> s1 >> s2;
    s = s1 + "#" + s2;

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
    std::vector<int> answer;
    for (int i = 0; i < pi.size(); i++) {

        if (pi[i] == s1.length())
            answer.push_back(i - 2 * s1.length());

    }

    std::cout << answer.size() << std::endl;

    for (auto i:answer)
        std::cout << i << ' ';

    std::cout << std::endl;

}