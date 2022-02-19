#include <iostream>
#include <vector>
#include <string>

int main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    std::string s;
    std::vector<int> pi;

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

    for (int i = 1; i <= n; i++)
        std::cout << pi[i] << ' ';

    std::cout << std::endl;

}