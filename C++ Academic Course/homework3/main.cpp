#include <iostream>
#include "pugixml.hpp"
#include <sstream>
#include "node.h"
#include <iomanip>
#include <cmath>
#include <clocale>

const int ANGLE_180 = 180;
const int EARTH_RADIUS = 6371;

std::vector<std::vector<Station>> reading_xml_file() {

    std::vector<std::vector<Station>> types_of_transport;

//    pugi::xml_encoding encoding = pugi::encoding_utf8;
    pugi::xml_document doc;

    //fixed use / in paths, use relative paths
    if (!doc.load_file("C:/Users/Andrz/CLionProjects/IS-2020-prog-2-sem/homework3/SPB_transpornt_data.xml")) {
        std::cout << "error" << std::endl;
        exit(1);
    }

    pugi::xml_node node = doc.first_child();
    int count = 0;
    std::stringstream s1;
    std::string delim;
    for (pugi::xml_node nodes = node.first_child(); nodes; nodes = nodes.next_sibling()) {
        count++;
        int index = 0;
        std::string type_of_vehicle, object_type, name_stop, off_name, routes, coordinates, location;
        std::stringstream ss;

        for (pugi::xml_node atr = nodes.first_child(); atr; atr = atr.next_sibling()) {

            ss << atr.child_value() << ' ';

            switch (index) {

                case 1:

                    type_of_vehicle = ss.str();
                    break;

                case 2:

                    object_type = ss.str();
                    break;

                case 3:

                    name_stop = ss.str();
                    break;

                case 4:

                    off_name = ss.str();
                    break;

                case 5:

                    location = ss.str();
                    break;

                case 6:

                    routes = ss.str();

                    if (routes[routes.size() - 2] == '.')
                        routes.erase(routes.size() - 2);

                    while (routes.find(' ') != std::string::npos)
                        routes.erase(routes.find(' '));

                    while (routes.find('.') != std::string::npos)
                        routes[routes.find('.')] = ',';

                    break;

                case 7:

                    coordinates = ss.str();

                default:

                    break;

            }

            index++;
            ss.clear();
            ss.str("");

        }

        std::string delimiter = ",";
        std::vector<std::string> routes_vect;
        size_t pos;

        double c1, c2;
        bool delimiter_exists = false;
        while (((pos = routes.find(delimiter))) != std::string::npos) {

            if (pos == 0) break;
            delimiter_exists = true;

            routes_vect.push_back(routes.substr(0, pos));
            routes.erase(0, pos + delimiter.length());

            if ((pos = routes.find(delimiter)) == std::string::npos)
                routes_vect.push_back(routes);

        }

        if (!delimiter_exists)
            routes_vect.push_back(routes);

        pos = coordinates.find(delimiter);
        ss << coordinates.substr(0, pos);
        ss >> c1;
        coordinates.erase(0, pos + delimiter.length());
        ss.clear();
        ss.str("");
        ss << coordinates;
        ss >> c2;

        Station station(type_of_vehicle, object_type, name_stop, off_name, location, routes_vect, c1, c2);

        bool coincidence = false;

        for (auto &i : types_of_transport) {

            if (i[0].get_type_of_vehicle() == station.get_type_of_vehicle()) {

                i.push_back(station);
                coincidence = true;
                break;

            }

        }

        if (!coincidence)
            types_of_transport.push_back({station});

    }

    return types_of_transport;

}

std::vector<std::vector<std::pair<std::string, std::vector<Station>>>>
find_rout_with_most_stations(std::vector<std::vector<Station>> &sorted_st) {

    std::vector<std::vector<std::pair<std::string, std::vector<Station>>>> types_of_tr;
    for (auto &type_of_transport : sorted_st) {

        std::vector<std::pair<std::string, std::vector<Station>>> routes;

        for (auto &station : type_of_transport) {

            std::vector<std::string> tmp = station.get_routes();

            for (std::string &i : tmp) {

                bool flag = false;

                for (auto &route : routes) {

                    auto&[nme, sts]=route;

                    if (nme == i) {

                        sts.push_back(station);
                        flag = true;

                    }
                }

                if (!flag) {
                    std::pair<std::string, std::vector<Station>> pair(i, {station});
                    routes.push_back(pair);
                }


            }

        }

        unsigned max = 0;
        std::string index;

        for (auto &i : routes) {
            auto &[nme, sts]=i;
            if (sts.size() > max) {

                max = sts.size();
                index = nme;

            }

        }

        std::cout << "Номер маршрута с наибольшим количеством остановок для типа транспорта "
                  << type_of_transport[0].get_type_of_vehicle() << ": " << index << ' ' << max << std::endl;

        types_of_tr.push_back(routes);

    }

    return types_of_tr;

}


//fixed consts
double count_distance(const Station &st1, const Station &st2) {

    double x1 = st1.get_coordinate1() * M_PI / ANGLE_180, x2 = st2.get_coordinate1() * M_PI / ANGLE_180;
    double y1 = st1.get_coordinate2() * M_PI / ANGLE_180, y2 = st2.get_coordinate2() * M_PI / ANGLE_180;

    return acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(y1 - y2)) * EARTH_RADIUS;

}


double find_rout_length(std::vector<Station> &stations) {

    double length_of_the_root = 0;

    Station start_st = stations[0];
    Station closest_st;

    std::vector<Station> longest_root{start_st};
    std::vector<bool> used_st;

    used_st.assign(stations.size(), false);
    used_st[0] = true;
    bool first_time;
    while (longest_root.size() < stations.size()) {

        //fixed random const
        double min_lngth_btw_st;
        first_time = true;
        int cur_num_of_st = -1;
        int num_of_cl_st = -1;

        for (auto &st : stations) {

            cur_num_of_st++;
            double res_dist = count_distance(st, start_st);


            if ((first_time || (res_dist < min_lngth_btw_st)) && !used_st[cur_num_of_st]) {

                first_time = false;
                min_lngth_btw_st = res_dist;
                closest_st = st;
                num_of_cl_st = cur_num_of_st;

            }

        }

        used_st[num_of_cl_st] = true;

        if (count_distance(longest_root[0], closest_st) < min_lngth_btw_st) {

            length_of_the_root += count_distance(longest_root[0], closest_st);
            std::vector<Station> tmp;

            for (size_t i = 0; i < longest_root.size(); i++)
                tmp.push_back(longest_root[longest_root.size() - i - 1]);

            tmp.push_back(closest_st);
            longest_root = tmp;
            start_st = closest_st;

        } else {

            length_of_the_root += min_lngth_btw_st;
            longest_root.push_back(closest_st);
            start_st = closest_st;

        }

    }

    return length_of_the_root;

}

void find_max_way(std::vector<std::vector<std::pair<std::string, std::vector<Station> > > > &types_of_srted_rts) {

    for (auto &i : types_of_srted_rts) {

        std::vector<std::pair<std::string, double>> lengths_of_rts;
        std::vector<Station> sts;

        for (auto &rout : i) {

            auto&[name, sts] = rout;
            lengths_of_rts.emplace_back(name, find_rout_length(sts));

        }
        double size = -1;
        std::string name_of_rout;

        for (auto &rout : lengths_of_rts) {

            auto&[name, length] = rout;

            if (size < length) {

                size = length;
                name_of_rout = name;

            }

        }

        auto&[nme, station]=i[0];

        std::cout << "Номер маршрута наибольшей длины для типа транспорта " << station[0].get_type_of_vehicle()
                  << ' ' << name_of_rout << ' ' << size << std::endl;

    }

}

void find_street_with_max_st(std::vector<std::vector<Station>> &st1) {

    int maximum = -1;
    std::string name;
    std::vector<std::pair<std::string, int>> streets;

    for (auto &st : st1) {

        for (auto &station : st) {

            bool exitst = false;

            std::string name1 = station.get_location();
            std::string name12;
            std::string delim = ",";

            if (name1.find(delim) != std::string::npos) {

                name12 = name1.substr(0, name1.find(delim));
                name1.erase(0, name1.find(delim) + 2);

            }

            for (auto &street : streets) {

                auto&[nme, counting] = street;

                if (nme == name1 || (!name12.empty() && nme == name12)) {

                    counting++;
                    exitst = true;

                }

            }

            if (!exitst && name1 != " ") {

                streets.emplace_back(name1, 1);

                if (!name12.empty() && name12 != " ")
                    streets.emplace_back(name12, 1);

            }

        }

    }

    for (auto &street :streets) {

        auto&[nme, counting] = street;

        if (counting > maximum) {

            name = nme;
            maximum = counting;

        }

    }

    std::cout << "Улица с наибольшим количеством остановок: " << name << ' ' << maximum << std::endl;

}

int main() {

    system("chcp 65001");
    std::cout << std::setprecision(10);

    std::vector<std::vector<Station>> st;
    std::vector<std::vector<std::pair<std::string, std::vector<Station>>>> types_of_rts;

    st = reading_xml_file();
    types_of_rts = find_rout_with_most_stations(st);
    find_max_way(types_of_rts);
    find_street_with_max_st(st);

    return 0;

}