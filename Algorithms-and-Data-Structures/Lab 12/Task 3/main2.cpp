#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<char> answer;

void LCS(std::string s2, std::vector<int> &lcs_last_line_matrix, const std::string &s1) {

    std::vector<std::vector<int>> lcs_maxtrix(2, std::vector<int>(s2.length() + 1));

    for (int j = 0; j <= s2.length(); j++)
        lcs_maxtrix[1][j] = 0;

    for (char i : s1) {

        for (int j = 0; j <= s2.length(); j++)
            lcs_maxtrix[0][j] = lcs_maxtrix[1][j];

        for (int j = 1; j <= s2.length(); j++) {

            if (i == s2[j - 1])
                lcs_maxtrix[1][j] = lcs_maxtrix[0][j - 1] + 1;
            else
                lcs_maxtrix[1][j] = std::max(lcs_maxtrix[1][j - 1], lcs_maxtrix[0][j]);

        }
    }

    for (int j = 0; j <= s2.length(); j++)
        lcs_last_line_matrix[j] = lcs_maxtrix[1][j];

}

void Hirschberg_algorithm(std::string s1, std::string s2) {

    if (s2.empty())
        return;

    if (s1.length() == 1) {

        if (find(s2.begin(), s2.end(), s1[0]) != s2.end())
            std::cout << s1[0];

        return;
    }


    int mid = s1.length() / 2;

    std::vector<int> f(s2.length() + 1), s(s2.length() + 1);

    LCS(s2, f, s1.substr(0, mid));

    std::string s1_ = s1, s2_ = s2;

    reverse(s1_.begin(), s1_.end());
    reverse(s2_.begin(), s2_.end());

    LCS(s2_, s, s1_.substr(0, s1.length() - mid));

    int max1 = s[0], it_max = 0;


    for (int j = 0; j <= s2.length(); j++) {

        if (f[j] + s[s2.length() - j] > max1) {

            max1 = f[j] + s[s2.length() - j];
            it_max = j;

        }

    }

    if (f[s2.length()] > max1)
        it_max = s2.length();

    if (mid == 0)
        mid++;

    Hirschberg_algorithm(s1.substr(0, mid), s2.substr(0, it_max));
    Hirschberg_algorithm(s1.substr(mid, s1.length()), s2.substr(it_max, s2.length()));

}

int main() {

    std::string s1, s2;

    std::cin >> s1 >> s2;

    Hirschberg_algorithm(s1, s2);

//    for (int i = answer.size() - 1; i > -1; i--)
//        std::cout << answer[i];

    std::cout << std::endl;

    return 0;

}

