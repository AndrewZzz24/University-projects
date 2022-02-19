#include <cmath>
#include <vector>

#pragma once

//fixed cpp
class Point {
private:
    int x;
    int y;
public:
    explicit Point(int valueX = 0, int valueY = 0);

    Point(const Point &other) = default;

    Point &operator=(const Point &other);

    virtual ~Point() = default;

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;
};

class PolygonalChain {
private:
    //fixed remove num_of_points
    std::vector<Point> array_of_points;
public:
    PolygonalChain(int total_points, Point *array);

    PolygonalChain(const PolygonalChain &other) = default;
    //fixed vector has copy-constructor

    PolygonalChain &operator=(const PolygonalChain &other) = default;
    //fixed vector has =

    virtual ~PolygonalChain() = default;
    //fixed remove it


    [[nodiscard]] int getN() const;

    [[nodiscard]] Point getPoint(int num_of_exact_point) const;

    [[nodiscard]] virtual double perimeter() const;
};

class ClosedPolygonalChain : public PolygonalChain {
public:
    ClosedPolygonalChain(int num, Point *a) : PolygonalChain(num, a) {};

    ClosedPolygonalChain &operator=(const ClosedPolygonalChain &other) = default;

    ClosedPolygonalChain(const ClosedPolygonalChain &other) = default;

    ~ClosedPolygonalChain() override = default;

    [[nodiscard]] double perimeter() const override;
    //fixed copy-paste from base class
};

class Polygon : public ClosedPolygonalChain {
public:

    Polygon(int num1, Point *a1) : ClosedPolygonalChain(num1, a1) {};

    Polygon &operator=(const Polygon &other) = default;

    Polygon(const Polygon &other) = default;

    ~Polygon() override = default;

    [[nodiscard]] virtual double area() const;
    //fixed result double is bad
};

class Triangle : public Polygon {
public:
    Triangle(int num, Point *tmp) : Polygon(num, tmp) {};

    Triangle &operator=(const Triangle &other) = default;

    Triangle(const Triangle &other) = default;

    ~Triangle() override = default;

    [[nodiscard]] bool hasRightAngle() const;
};

class Trapezoid : public Polygon {
public:
    Trapezoid(int num, Point *tmp) : Polygon(num, tmp) {};

    Trapezoid &operator=(const Trapezoid &other) = default;

    Trapezoid(const Trapezoid &other) = default;

    ~Trapezoid() override = default;

    [[nodiscard]] double height() const;
};

class RegularPolygon : public Polygon {
public:
    RegularPolygon(int num, Point *tmp) : Polygon(num, tmp) {};

    RegularPolygon &operator=(const RegularPolygon &other) = default;

    RegularPolygon(const RegularPolygon &other) = default;

    ~RegularPolygon() override = default;

    [[nodiscard]] double perimeter() const override;

    [[nodiscard]] double area() const override;

    //fixed weird stuff

};


