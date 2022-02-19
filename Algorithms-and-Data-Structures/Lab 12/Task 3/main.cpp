#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> d;
std::vector<std::vector<std::pair<int, int>>> prev;
std::string s1, s2;
std::vector<char> answer;

void printLCS(int i, int j) {

    if (i == 0 || j == 0)
        return;

    if (prev[i][j] == std::make_pair(i - 1, j - 1)) {

        printLCS(i - 1, j - 1);
        //std::cout << s1[i];
        answer.push_back(s1[i]);

    } else {

        if (prev[i][j] == std::make_pair(i - 1, j))
            printLCS(i - 1, j);

        else
            printLCS(i, j - 1);
    }
}

void LCS() {

    int m = s1.length(), n = s2.length();
    d.assign(m + 1, std::vector<int>(n + 1, 0));
    prev.assign(m + 1, std::vector<std::pair<int, int>>(n + 1, {0, 0}));

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (s1[i] == s2[j]) {

                d[i][j] = d[i - 1][j - 1] + 1;
                prev[i][j] = std::make_pair(i - 1, j - 1);

            } else {
                if (d[i - 1][j] >= d[i][j - 1]) {
                    d[i][j] = d[i - 1][j];
                    prev[i][j] = std::make_pair(i - 1, j);
                } else {
                    d[i][j] = d[i][j - 1];
                    prev[i][j] = std::make_pair(i, j - 1);
                }
            }
        }
    }
    printLCS(m, n);
}

int main() {

    std::cin >> s1 >> s2;
    s1.insert(0, ".");
    s2.insert(0, ".");
    LCS();
    for (int i = 0; i < answer.size() - 1; i++)
        std::cout << answer[i];
    std::cout << std::endl;

}