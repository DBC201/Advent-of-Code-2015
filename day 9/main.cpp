#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../common/library.cpp"
#include <string>
#include <queue>
#include <algorithm>

std::unordered_map<std::string, std::unordered_map<std::string, int>> distances;

void readfile() {
    std::fstream file;
    std::string line;
    std::vector<std::string> cities;
    std::unordered_map<std::string, int> neighbors;
    int distance;

    file.open("../input.txt", std::fstream::in);
    if (!file.is_open()) {
        throw std::runtime_error("unable to open file");
    }

    while (getline(file, line)) {
        cities = split(line.substr(0, line.find(" =")), " to ");
        distance = stoi(line.substr(line.find('=') + 2));
        try {
            distances.at(cities[0]).insert({cities[1], distance});
        } catch (std::out_of_range &e) {
            neighbors.clear();
            neighbors.insert({cities[1], distance});
            distances.insert({cities[0], neighbors});
        }

        try {
            distances.at(cities[1]).insert({cities[0], distance});
        } catch (std::out_of_range &e) {
            neighbors.clear();
            neighbors.insert({cities[0], distance});
            distances.insert({cities[1], neighbors});
        }
    }
    file.close();
}

int min_primm(std::string starting_vertex) {
    std::unordered_map<std::string, bool> visited;
    for (const auto& v: distances) {
        visited.insert({v.first, false});
    }


    std::queue<std::string> q;
    q.push(starting_vertex);

    int smallest_distance = 0;
    std::string vertex;

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        visited.at(vertex) = true;
        std::pair<std::string, int> smallest_neighbor;
        smallest_neighbor.first = "";
        smallest_neighbor.second = INT_MAX;
        for (const auto &neighbor: distances.at(vertex)) {
            if (!visited.at(neighbor.first) && neighbor.second < smallest_neighbor.second) {
                smallest_neighbor = neighbor;
            }
        }
        if (smallest_neighbor.first != "") {
            q.push(smallest_neighbor.first);
            smallest_distance += smallest_neighbor.second;
        }
    }
    return smallest_distance;
}

int minimum_using_primm() {
    int minimum = INT_MAX;
    for (const auto& v: distances) {
        minimum = std::min(min_primm(v.first), minimum);
    }
    return minimum;
}

int max_primm(std::string starting_vertex) {
    std::unordered_map<std::string, bool> visited;
    for (const auto& v: distances) {
        visited.insert({v.first, false});
    }


    std::queue<std::string> q;
    q.push(starting_vertex);

    int max_distance = 0;
    std::string vertex;

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        visited.at(vertex) = true;
        std::pair<std::string, int> max_neighbor;
        max_neighbor.first = "";
        max_neighbor.second = 0;
        for (const auto &neighbor: distances.at(vertex)) {
            if (!visited.at(neighbor.first) && neighbor.second > max_neighbor.second) {
                max_neighbor = neighbor;
            }
        }
        if (max_neighbor.first != "") {
            q.push(max_neighbor.first);
            max_distance += max_neighbor.second;
        }
    }
    return max_distance;
}

int maximum_using_primm() {
    int maximum = 0;
    for (const auto& v: distances) {
        maximum = std::max(max_primm(v.first), maximum);
    }
    return maximum;
}

int main() {
    readfile();
    std::cout << minimum_using_primm() << std::endl;
    std::cout << maximum_using_primm() << std::endl;
    return EXIT_SUCCESS;
}
