#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> board;

void recursion(int x, int y) {

    board[x][y]++;
    if (x == n - 1 && y == m - 1)
        return;
    else {
        if (x - 1 > -1 && y + 2 < m)
            recursion(x - 1, y + 2);

        if (x + 1 < n && y + 2 < m)
            recursion(x + 1, y + 2);

        if (x + 2 < n && y - 1 > -1)
            recursion(x + 2, y - 1);

        if (x + 2 < n && y + 1 < m)
            recursion(x + 2, y + 1);
    }
}

int main() {

    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        board.push_back({0});
        for (int j = 0; j < m; j++)
            board[i].push_back(0);
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++)
//            std::cout << board[i][j] << ' ';
//        std::cout << std::endl;
//    }
    recursion(0, 0);

    std::cout << board[n - 1][m - 1] << std::endl;

}