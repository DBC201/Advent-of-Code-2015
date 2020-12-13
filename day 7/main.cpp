#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> return_sides(string wire, string op){
    vector<string> return_val;
    if (op == "NOT"){
        return_val.push_back(wire.substr(4, wire.length()-4));
        return return_val;
    }
    int middle = wire.find(op);
    return_val.push_back(wire.substr(0, middle-1));
    return_val.push_back(wire.substr(middle+1+op.length(), wire.length()-(middle+1+op.length())));
    return return_val;
}

unsigned int flip_relevant_bits (unsigned int digit) {
    for (int i=0; i<16; i++) {
        unsigned int single_bit = 1 << i;
        digit = digit ^ single_bit;
    }
    return digit;
}

map<string, unsigned int> cache;
unsigned int get_signal(string wire, map<string, string> &wires){
    try{
        return stoi(wire);
    } catch (invalid_argument &e) {
        string wire_val = wires.at(wire);
        vector<string> sides;
        auto check_cache = [] (string val, map<string, string> &wires) {
            try {
                return cache.at(val);
            } catch (out_of_range &e) {
                cache.insert({val, get_signal(val, wires)});
                return cache.at(val);
            }
        };
        if(wire_val.find("NOT") != string::npos){
            sides = return_sides(wire_val, "NOT");
            return flip_relevant_bits(check_cache(sides[0], wires));
        }
        if(wire_val.find("AND") != string::npos){
            sides = return_sides(wire_val, "AND");
            return check_cache(sides[0], wires) & check_cache(sides[1], wires);
        } else if(wire_val.find("OR") != string::npos) {
            sides = return_sides(wire_val, "OR");
            return check_cache(sides[0], wires) | check_cache(sides[1], wires);
        } else if(wire_val.find("LSHIFT") != string::npos){
            sides = return_sides(wire_val, "LSHIFT");
            return check_cache(sides[0], wires) << check_cache(sides[1], wires);
        } else if(wire_val.find("RSHIFT") != string::npos){
            sides = return_sides(wire_val, "RSHIFT");
            return check_cache(sides[0], wires) >> check_cache(sides[1], wires);
        }  else {
            return check_cache(wire_val, wires);
        }
    }
}

int main() {
    map<string, string> wires;
    fstream file;
    file.open("../input.txt", fstream::in);
    string line;
    while(getline(file, line)){
        string left = line.substr(0, line.find("->")-1);
        string right = line.substr(line.find("->")+3, line.length()-line.find("->")+3);
        wires.insert(pair<string, string>(right, left));
    }
    file.close();
    unsigned int signal_a = get_signal("a", wires);
    cout << signal_a << endl;
    wires.at("b") = to_string(signal_a);
    cache.clear();
    cout << get_signal("a", wires) << endl;
    return 0;
}
