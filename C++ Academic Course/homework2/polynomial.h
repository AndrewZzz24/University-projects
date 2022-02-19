#include <vector>
#include <string>
#include <sstream>

#ifndef IS_2020_PROG_2_SEM_POLYNOMIAL_H
#define IS_2020_PROG_2_SEM_POLYNOMIAL_H


class Polynomial {

private:
    int min_power;
    int max_power;
    int *polynom;

public:
    explicit Polynomial(int min_power = 0, int max_power = 0, const int *array_of_coeff = new int[1]{0});

    Polynomial(const Polynomial &other);

    ~Polynomial();

    Polynomial &operator=(const Polynomial &other);

    bool operator==(const Polynomial &other) const;

    bool operator!=(const Polynomial &other) const;

    Polynomial operator-();
    //fixed += return this
    //fixed += as method
    Polynomial& operator+=(const Polynomial &other);

    friend Polynomial operator+(const Polynomial &these, const Polynomial &other);

    Polynomial& operator-=(Polynomial &other);

    friend Polynomial operator-(const Polynomial &these, Polynomial &other);

    friend Polynomial operator*(const Polynomial &these, const Polynomial &other);

    Polynomial& operator*=(const Polynomial &other);

    friend Polynomial operator*(const Polynomial &these, const int &value);

    Polynomial& operator*=(int);

    friend Polynomial operator*(const int &value, const Polynomial &other);

    friend Polynomial operator/(const Polynomial &other, const int &value);

    Polynomial& operator/=(int);

    int operator[](const int &value) const;

    int &operator[](const int &value);

    //fixed int
    [[nodiscard]] double get(int) const;

    friend std::stringstream &operator<<(std::stringstream &ss, const Polynomial &other);

    friend Polynomial &operator>>(std::istream &os, Polynomial &other);


};

#endif //IS_2020_PROG_2_SEM_POLYNOMIAL_H
