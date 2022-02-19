#include <iostream>
#include <string>
#include <vector>

int main() {

    //freopen("search1.in", "r", stdin);
    //freopen("search1.out", "w", stdout);

    std::vector<int> answer;
    std::string s1, s2;
    int count = 0;

    std::cin >> s1 >> s2;

    int n = s2.length(), m = s1.length();

    for (int i = 0; i < n - m + 1; i++) {

        if (s1 == s2.substr(i, m)) {

            count++;
            answer.push_back(i + 1);

        }

    }

    std::cout << count << std::endl;

    for (auto i:answer)
        std::cout << i << ' ';

    std::cout << std::endl;

    return 0;

}