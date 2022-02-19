#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Point {
private:

    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const {

        return x;

    }

    double getY() const {

        return y;

    }
};

void input(int &n, std::vector<Point> &vert) {

    std::cin >> n;

    for (size_t i = 0; i < n; i++) {

        double x, y;
        std::cin >> x >> y;
        vert.emplace_back(x, y);

    }

}

double get_distance(Point &p1, Point &p2) {

    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));

}

double find_min_mst(int n, std::vector<Point> &vert) {

    double result = 0;
    std::vector<double> key;
    key.assign(vert.size(), -1);
    key[0] = 0;

    while (true) {

        int index;
        double value = -1;

        for (size_t i = 0, j = 1; i < key.size(); i++) {

            if (j == 1 && key[i] > -1) {
                j = 0;
                index = i;
                value = key[i];
            } else if (key[i] > -1 && key[i] < value) {
                index = i;
                value = key[i];
            }

        }

        if (value == -1) break;

        if (key[index] > 0)
            result += key[index];

        for (size_t i = 0; i < vert.size(); i++) {

            if (i != index && key[i] > -2) {
                double tmp = get_distance(vert[i], vert[index]);
                if (key[i] > tmp || key[i] == -1)
                    key[i] = tmp;
            }

        }

        key[index] = -2;

    }

    return result;

}

int main() {

    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);

    int n;
    std::vector<Point> vertexes;

    input(n, vertexes);

    std::cout << std::fixed;
    std::cout << std::setprecision(3) << find_min_mst(n, vertexes) << std::endl;

    return 0;

}