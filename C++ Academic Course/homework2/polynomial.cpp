#include "polynomial.h"
#include <cmath>
#include <iostream>

//fixed ???


Polynomial::Polynomial(int min_power, int max_power, const int *array_of_coeff) {

    this->min_power = min_power;
    this->max_power = max_power;

    if (array_of_coeff == nullptr)
        return;

    polynom = new int[max_power - min_power + 1];

    for (int i = 0; i < max_power - min_power + 1; i++)
        polynom[i] = array_of_coeff[i];

}

Polynomial::Polynomial(const Polynomial &other) {

    this->min_power = other.min_power;
    this->max_power = other.max_power;
    polynom = new int[other.max_power - other.min_power + 1];

    for (int i = 0; i < max_power - min_power + 1; i++)
        polynom[i] = other.polynom[i];
}

Polynomial::~Polynomial() {

    delete[] this->polynom;

}

Polynomial &Polynomial::operator=(const Polynomial &other) {

    if (this == &other)
        return *this;

    delete[] polynom;
    this->min_power = other.min_power;
    this->max_power = other.max_power;

    polynom = new int[other.max_power - other.min_power + 1];
    for (int i = 0; i < max_power - min_power + 1; i++)
        polynom[i] = other.polynom[i];

    return *this;
}

bool Polynomial::operator!=(const Polynomial &other) const {
    return !(*this == other);
}

//fixed something more intellectual
bool Polynomial::operator==(const Polynomial &other) const {

    int start1 = 0, finish1 = 0, start2 = 0, finish2 = 0;


    for (int i = 0; i < max_power - min_power + 1; i++)
        if (polynom[i] != 0 || (max_power == 0 && min_power == 0)) {
            start1 = i;
            break;
        }

    for (int i = max_power - min_power; i > -1; i--)
        if (polynom[i] != 0 || (max_power == 0 || min_power == 0)) {
            finish1 = i;
            break;
        }


    for (int i = 0; i < other.max_power - other.min_power + 1; i++)
        if (other.polynom[i] != 0 || (other.max_power == 0 && other.min_power == 0)) {
            start2 = i;
            break;
        }

    for (int i = other.max_power - other.min_power; i > -1; i--)
        if (other.polynom[i] != 0 || (other.max_power == 0 && other.min_power == 0)) {
            finish2 = i;
            break;
        }


    if (start1 - finish1 != start2 - finish2)
        return false;

    for (int i = start1, j = start2; i <= finish1; i++, j++) {
        if (polynom[i] != other.polynom[j])
            return false;
    }

    return true;

}

Polynomial Polynomial::operator-() {
    Polynomial tmp = *this;
    for (int i = 0; i < this->max_power - this->min_power + 1; i++)
        tmp.polynom[i] *= -1;
    return tmp;
}

//fixed + from +=
Polynomial &Polynomial::operator+=(const Polynomial &other) {

    if (this->max_power == 0 and this->min_power == 0 and this->polynom[0] == 0) {
        *this = other;
        return *this;
    }

    if (other.max_power == 0 and other.min_power == 0 and other.polynom[0] == 0)
        return *this;

    if (this->max_power == other.max_power && this->min_power == other.min_power) {
        for (int i = 0; i < this->max_power - this->min_power + 1; i++)
            this->polynom[i] += other.polynom[i];
        return *this;
    }

    Polynomial result;
    result.min_power = std::min(this->min_power, other.min_power);
    result.max_power = std::max(this->max_power, other.max_power);
    result.polynom = new int[result.max_power - result.min_power + 1]{0};

    int diff = 0;

    if (result.min_power == other.min_power)
        diff = this->min_power - other.min_power;

    for (int i = 0; i < this->max_power - this->min_power + 1; i++)
        result.polynom[i + diff] += this->polynom[i];

    diff = 0;

    if (result.min_power == this->min_power)
        diff = other.min_power - this->min_power;

    for (int i = 0; i < other.max_power - other.min_power + 1; i++)
        result.polynom[i + diff] += other.polynom[i];

    *this = result;
    return *this;
}


Polynomial operator+(const Polynomial &these, const Polynomial &other) {

    Polynomial tmp;
    tmp = these;
    tmp += other;
    return tmp;

}

//fixed memory prolbems
Polynomial &Polynomial::operator-=(Polynomial &other) {
    if (this->max_power == 0 and this->min_power == 0 and this->polynom[0] == 0) {
        *this = -other;
        return *this;
    }

    if (other.max_power == 0 and other.min_power == 0 and other.polynom[0] == 0)
        return *this;

    if (this->max_power == other.max_power && this->min_power == other.min_power) {
        for (int i = 0; i < this->max_power - this->min_power + 1; i++)
            this->polynom[i] -= other.polynom[i];
        return *this;
    }

    Polynomial result;
    result.min_power = std::min(this->min_power, other.min_power);
    result.max_power = std::max(this->max_power, other.max_power);
    result.polynom = new int[result.max_power - result.min_power + 1]{0};

    int diff = 0;

    if (result.min_power == other.min_power)
        diff = this->min_power - other.min_power;

    for (int i = 0; i < this->max_power - this->min_power + 1; i++)
        result.polynom[i + diff] -= this->polynom[i];

    diff = 0;

    if (result.min_power == this->min_power)
        diff = other.min_power - this->min_power;

    for (int i = 0; i < other.max_power - other.min_power + 1; i++)
        result.polynom[i + diff] -= other.polynom[i];

    *this = result;

    return *this;
}

Polynomial operator-(const Polynomial &these, Polynomial &other) {

    Polynomial tmp;
    tmp = these;
    tmp -= other;
    return tmp;

}

Polynomial &Polynomial::operator*=(const Polynomial &other) {

    if (this->max_power == 0 && this->min_power == 0 && this->polynom[0] == 0)
        return *this;

    if (other.max_power == 0 && other.min_power == 0 && other.polynom[0] == 0) {
        *this = other;
        return *this;
    }

    Polynomial result;

    result.min_power = this->min_power + other.min_power;
    result.max_power = this->max_power + other.max_power;
    result.polynom = new int[result.max_power - result.min_power + 1]{0};
    int curr_first_power = this->min_power;

    for (int i = 0; i < this->max_power - this->min_power + 1; i++) {
        int curr_second_power = other.min_power;
        for (int j = 0; j < other.max_power - other.min_power + 1; j++) {
            result.polynom[curr_first_power + curr_second_power - result.min_power] +=
                    this->polynom[i] * other.polynom[j];
            curr_second_power++;
        }
        curr_first_power++;
    }

    *this = result;
    return *this;
}

Polynomial operator*(const Polynomial &these, const Polynomial &other) {
    Polynomial tmp = these;
    tmp *= other;
    return tmp;
}

Polynomial &Polynomial::operator*=(int value) {

    //Polynomial result = *this;

    for (int i = 0; i < this->max_power - this->min_power + 1; i++)
        this->polynom[i] = this->polynom[i] * value;

    return *this;

}

Polynomial operator*(const Polynomial &these, const int &value) {

    Polynomial tmp = these;
    tmp *= value;

    return tmp;

}

Polynomial operator*(const int &value, const Polynomial &other) {

    return other * value;

}

Polynomial &Polynomial::operator/=(int value) {

    Polynomial result = *this;
    for (int i = 0; i < result.max_power - result.min_power + 1; i++)
        result.polynom[i] = this->polynom[i] / value;

    Polynomial tmp_obj = result;
    int cur_pow = result.min_power;
    int start = 0, finish = 0;

    for (int i = 0; i < result.max_power - result.min_power + 1; i++) {
        if (result.polynom[i] != 0) {
            tmp_obj.min_power = cur_pow;
            start = i;
            break;
        }
        cur_pow++;
    }

    cur_pow = result.max_power;

    for (int i = result.max_power - result.min_power; i >= 0; i--) {
        if (result.polynom[i] != 0) {
            tmp_obj.max_power = cur_pow;
            finish = i;
            break;
        }
        cur_pow--;
    }

    tmp_obj.polynom = new int[tmp_obj.max_power - tmp_obj.min_power + 1];
    for (int i = start, j = 0; i < finish + 1; i++, j++)
        tmp_obj[j] = result.polynom[i];

    *this = tmp_obj;
    return *this;
}

Polynomial operator/(const Polynomial &other, const int &value) {

    Polynomial tmp = other;
    tmp /= value;
    return tmp;

}

int Polynomial::operator[](const int &value) const {

    if (value > max_power or value < min_power)
        return 0;

    for (int i = 0; i < max_power - min_power + 1; i++)
        if (i == value)
            return polynom[i];

    return 0;
}

int &Polynomial::operator[](const int &value) {

    Polynomial temp(*this);

    if ((this->max_power < value || this->min_power > value)) {

        if (temp.max_power < value) {

            delete[] temp.polynom;
            temp.max_power = value;
            temp.polynom = new int[temp.max_power - temp.min_power + 1]{0};

        }


        if (temp.min_power > value) {

            delete[] temp.polynom;
            temp.min_power = value;
            temp.polynom = new int[temp.max_power - temp.min_power + 1]{0};

        }


        int index = 0;

        for (int i = 0, j = temp.min_power; i < temp.max_power - temp.min_power + 1; i++, j++) {

            if (j >= this->min_power && j <= this->max_power) {

                temp.polynom[i] = this->polynom[index];
                index++;

            }

        }


        *this = temp;
        for (int i = 0, j = this->min_power; i < this->max_power - this->min_power + 1; i++, j++) {

            if (j == value)
                return this->polynom[i];

        }

    }

    for (int i = 0, j = this->min_power; i < this->max_power - this->min_power + 1; i++, j++) {

        if (j == value)
            return this->polynom[i];

    }

    return polynom[0];
}

double Polynomial::get(int value) const {

    double result = 0;
    int curr_power = min_power;
    double curr_powered_value = pow(value, curr_power);
    for (int i = 0; i < max_power - min_power + 1; i++) {
        result += curr_powered_value * polynom[i];
        curr_powered_value *= value;
        curr_power++;
    }

    return result;
}

//fixed operator >>
std::stringstream &operator<<(std::stringstream &ss, const Polynomial &other) {

    int current_power = other.max_power;

    for (int i = other.max_power - other.min_power; i >= 0; i--) {

        if (other.min_power == 0 && other.max_power == 0) {
            ss << other.polynom[i];
            break;
        }

        if (other.polynom[i] < 0)
            ss << '-';

        if (other.polynom[i] > 0 && current_power != other.max_power)
            ss << '+';

        if ((current_power == 0 && other.polynom[i] != 0) || std::abs(other.polynom[i]) > 1)
            ss << std::abs(other.polynom[i]);

        if (current_power != 0 && other.polynom[i] != 0) {

            ss << 'x';

            if (current_power != 1) {
                ss << '^' << current_power;
            }

        }

        current_power--;
    }

    return ss;
}

Polynomial &operator>>(std::istream &is, Polynomial &other) {

    std::stringstream ss;
    int maxp = 0, minp = 0;
    bool first = true, f1;
    std::vector<int> indexes;
    char ch = ' ', ch2 = ' ';

    while (ch != '.') {

        f1 = true;
        ss.clear();
        ss.str("");
        is >> ch;

        while (ch != 'x' && ch != '.') {
            ss << ch;
            is >> ch;
            if (ch == '+' || ch == '-') {
                is.unget();
                f1 = false;
                break;
            }
        }

        if (ss.str().empty() || ss.str() == "+") indexes.push_back(1);
        else if (ss.str() == "-") indexes.push_back(-1);
        else {
            int tmp;
            ss >> tmp;
            indexes.push_back(tmp);
            ss.clear();
            ss.str("");
            if (ch == '.') break;
        }

        if (!f1) {
            if (first) {
                first = false;
                maxp = 0;
                minp = 0;
            }
            minp--;
            continue;
        }

        ch2 = ch;
        is >> ch;
        if (ch == '.') break;

        if (ch == '^') {
            ss.clear();
            ss.str("");
            is >> ch;
            while (true) {
                ss << ch;
                is >> ch;
                if (ch == '.' || !(ch >= '0' && ch <= '9')) break;
            }
            if (first) {
                int tmp;
                ss >> tmp;
                first = false;
                maxp = tmp;
                minp = maxp;
            }
        }

        if (ch != '.') minp--;
        is.unget();

    }

    if (ch2 == 'x' && maxp == 0 && minp == 0) {
        maxp = 1;
        minp = 1;
    }

    other.max_power = maxp;
    other.min_power = minp;
    delete[] other.polynom;
    other.polynom = new int[other.max_power - other.min_power + 1];

    for (int i = 0; i < other.max_power - other.min_power + 1; i++) {
        other.polynom[i] = indexes[indexes.size() - i - 1];
    }

    return other;

}