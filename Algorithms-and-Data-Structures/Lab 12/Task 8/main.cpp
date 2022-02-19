#include <bits\stdc++.h>

using namespace std;


void solve(string x, string y);
void getLCS(const string& x, string y, vector<int>& lastLine);

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
    return 0;
}

void solve(string x, string y) {
    if(y.empty()) {
        return;
    }
    if (x.length() == 1) {
        if (find(y.begin(), y.end(), x[0]) != y.end()) {
            cout << x[0];
        }
        return;
    }


    int middle = x.length() / 2;
    vector<int> first(y.length() + 1), second(y.length() + 1);
    getLCS(x.substr(0, middle), y, first);
    string xSecond = x, ySecond = y;
    reverse(xSecond.begin(), xSecond.end());
    reverse(ySecond.begin(), ySecond.end());
    getLCS(xSecond.substr(0, x.length() - middle), ySecond, second);

    int maxVal = second[0], maxValPos = 0;

    for (int j = 0; j <= y.length(); j++) {
        if (first[j] + second[y.length() - j] > maxVal) {
            maxVal = first[j] + second[y.length() - j];
            maxValPos = j;
        }
    }
    if (first[y.length()] > maxVal) {
        maxValPos = y.length();
    }
    if (middle == 0) {
        middle++;
    }
    solve(x.substr(0, middle), y.substr(0, maxValPos));
    solve(x.substr(middle, x.length()), y.substr(maxValPos, y.length()));
}

void getLCS(const string& x, string y, vector<int>& lastLine) {
    vector<vector<int>> twoMatrixLines(2, vector<int>(y.length() + 1));
    for (int j = 0; j <= y.length(); j++) {
        twoMatrixLines[1][j] = 0;
    }
    for(char i : x) {
        for (int j = 0; j <= y.length(); j++) {
            twoMatrixLines[0][j] = twoMatrixLines[1][j];
        }
        for (int j = 1; j <= y.length(); j++) {
            if (i == y[j - 1]) {
                twoMatrixLines[1][j] = twoMatrixLines[0][j - 1] + 1;
            }
            else {
                twoMatrixLines[1][j] = max(twoMatrixLines[1][j - 1], twoMatrixLines[0][j]);
            }
        }
    }
    for (int j = 0; j <= y.length(); j++) {
        lastLine[j] = twoMatrixLines[1][j];
    }
}