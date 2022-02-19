#include "node.h"

std::string Station::get_type_of_vehicle() const {
    return type_of_vehicle;
}

std::string Station::get_object_type() const {
    return object_type;
}

std::string Station::get_name_stopping() const {
    return name_stopping;
}

std::string Station::get_the_off_name_stopping() const {
    return the_off_name_stopping;
}

double Station::get_coordinate1() const {
    return coord1;
}

double Station::get_coordinate2() const {
    return coord2;
}

std::string Station::get_location() const {
    return location;
}

std::vector<std::string> Station::get_routes() const {
    return roots;
}