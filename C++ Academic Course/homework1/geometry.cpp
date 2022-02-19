#include "geometry.h"

Point::Point(int valueX, int valueY)
        : x(valueX),
          y(valueY) {}

Point &Point::operator=(const Point &other) {
    if (&other == this) {
        return *this;
    }
    x = other.x;
    y = other.y;
    return *this;
}

[[nodiscard]] int Point::getX() const {
    return x;
}


[[nodiscard]] int Point::getY() const {
    return y;
}

PolygonalChain::PolygonalChain(int total_points, Point *array) {
    //array_of_points.reserve(total_points);
    for (int i = 0; i < total_points; i++)
        array_of_points.push_back(array[i]);
}

[[nodiscard]] int PolygonalChain::getN() const {
    return this->array_of_points.size();
}

[[nodiscard]] Point PolygonalChain::getPoint(int num_of_exact_point) const {
    Point tmp = array_of_points[num_of_exact_point];
    return tmp;
}

[[nodiscard]] double PolygonalChain::perimeter() const {
    double result = 0;
    for (int i = 0; i < this->getN() - 1; i++)
        result += sqrt(pow(this->getPoint(i).getX() - this->getPoint(i + 1).getX(), 2) +
                       pow(this->getPoint(i).getY() - this->getPoint(i + 1).getY(), 2));
    return result;
}

[[nodiscard]] double ClosedPolygonalChain::perimeter() const {
    double result;
    result = PolygonalChain::perimeter();
    result += sqrt(pow(this->getPoint(0).getX() - this->getPoint(this->getN() - 1).getX(), 2) +
                   pow(this->getPoint(0).getY() - this->getPoint(this->getN() - 1).getY(), 2));
    return result;
}

[[nodiscard]] double Polygon::area() const {
    int result = 0;
    for (int i = 0; i < this->getN() - 1; i++) {
        result += this->getPoint(i).getX() * this->getPoint(i + 1).getY();
        result -= this->getPoint(i).getY() * this->getPoint(i + 1).getX();
    }
    result += this->getPoint(this->getN() - 1).getX() * this->getPoint(0).getY();
    result -= this->getPoint(this->getN() - 1).getY() * this->getPoint(0).getX();
    return (double) abs(result) / 2;
}

[[nodiscard]] bool Triangle::hasRightAngle() const {
    double side1 = pow(this->getPoint(0).getX() - this->getPoint(1).getX(), 2) +
                   pow(this->getPoint(0).getY() - this->getPoint(1).getY(), 2);
    double side2 = pow(this->getPoint(1).getX() - this->getPoint(2).getX(), 2) +
                   pow(this->getPoint(1).getY() - this->getPoint(2).getY(), 2);
    double side3 = pow(this->getPoint(0).getX() - this->getPoint(2).getX(), 2) +
                   pow(this->getPoint(0).getY() - this->getPoint(2).getY(), 2);
    if ((side1 + side2 == side3) || (side1 + side3 == side2) || (side2 + side3 == side1))
        return true;
    return false;
}

[[nodiscard]] double Trapezoid::height() const {
    double base1 = sqrt(pow(this->getPoint(0).getX() - this->getPoint(3).getX(), 2) +
                        pow(this->getPoint(0).getY() - this->getPoint(3).getY(), 2));
    double base2 = sqrt(pow(this->getPoint(1).getX() - this->getPoint(2).getX(), 2) +
                        pow(this->getPoint(1).getY() - this->getPoint(2).getY(), 2));
    double mid_line = (base1 + base2) / 2;
    double square = this->area();
    double result = square / mid_line;
    return result;
}

double RegularPolygon::perimeter() const {
    double result;
    double side = sqrt(pow(this->getPoint(0).getX() - this->getPoint(1).getX(), 2) +
                       pow(this->getPoint(0).getY() - this->getPoint(1).getY(), 2));
    int num_of_sides = this->getN();
    result = side * num_of_sides;
    return result;
}

double RegularPolygon::area() const {
    int result;
    double side = sqrt(pow(this->getPoint(0).getX() - this->getPoint(1).getX(), 2) +
                       pow(this->getPoint(0).getY() - this->getPoint(1).getY(), 2));
    int num_sides = this->getN();
    double radius = side / (2 * sin(acos(-1) / num_sides));
    result = (int) (num_sides * pow(radius, 2) * sin((2 * acos(-1)) / num_sides) / 2);
    return result;
}

