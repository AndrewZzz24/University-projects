#include <string>
#include <utility>
#include <vector>

#ifndef IS_2020_PROG_2_SEM_NODE_H
#define IS_2020_PROG_2_SEM_NODE_H


class Station {
private:
    std::string type_of_vehicle;
    std::string object_type;
    std::string name_stopping;
    std::string the_off_name_stopping;
    std::string location;
    std::vector<std::string> roots;
    double coord1;
    double coord2;
public:

    explicit Station(std::string s1 = "", std::string s2 = "", std::string s3 = "", std::string s4 = "",
                     std::string s5 = "", std::vector<std::string> vect = std::vector<std::string>(),
                     double c1 = 0,
                     double c2 = 0) : type_of_vehicle(std::move(s1)), object_type(std::move(std::move(s2))),
                                      name_stopping(std::move(s3)),
                                      the_off_name_stopping(std::move(std::move(s4))), location(std::move(s5)),
                                      roots(std::move(vect)), coord1(c1), coord2(c2) {}

    [[nodiscard]] std::string get_type_of_vehicle() const;

    [[nodiscard]] std::string get_object_type() const;

    [[nodiscard]] std::string get_name_stopping() const;

    [[nodiscard]] std::string get_the_off_name_stopping() const;

    [[nodiscard]] double get_coordinate1() const;

    [[nodiscard]] double get_coordinate2() const;

    [[nodiscard]] std::string get_location() const;

    [[nodiscard]] std::vector<std::string> get_routes() const;
};


#endif //IS_2020_PROG_2_SEM_NODE_H
