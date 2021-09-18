#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../common/library.cpp"
#include <string>

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

int min_dfs(std::string starting_vertex) {
    std::unordered_map<std::string, bool> visited;
    for (const auto& v: distances) {
        visited.insert({v.first, false});
    }

    int smallest_distance = 0;
    std::string vertex = starting_vertex;

    while (!vertex.empty()) {
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
            vertex = smallest_neighbor.first;
            smallest_distance += smallest_neighbor.second;
        } else {
            break;
        }
    }
    return smallest_distance;
}

int minimum() {
    int minimum = INT_MAX;
    for (const auto& v: distances) {
        minimum = std::min(min_dfs(v.first), minimum);
    }
    return minimum;
}

int max_dfs(std::string starting_vertex) {
    std::unordered_map<std::string, bool> visited;
    for (const auto& v: distances) {
        visited.insert({v.first, false});
    }

    int max_distance = 0;
    std::string vertex = starting_vertex;

    while (!vertex.empty()) {
        visited.at(vertex) = true;
        std::pair<std::string, int> smallest_neighbor;
        smallest_neighbor.first = "";
        smallest_neighbor.second = 0;
        for (const auto &neighbor: distances.at(vertex)) {
            if (!visited.at(neighbor.first) && neighbor.second > smallest_neighbor.second) {
                smallest_neighbor = neighbor;
            }
        }
        if (smallest_neighbor.first != "") {
            vertex = smallest_neighbor.first;
            max_distance += smallest_neighbor.second;
        } else {
            break;
        }
    }
    return max_distance;
}

int maximum() {
    int maximum = 0;
    for (const auto& v: distances) {
        maximum = std::max(max_dfs(v.first), maximum);
    }
    return maximum;
}

int main() {
    readfile();
    std::cout << minimum() << std::endl;
    std::cout << maximum() << std::endl;
    return EXIT_SUCCESS;
}
