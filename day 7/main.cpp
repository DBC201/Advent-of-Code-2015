#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
/*#include <stack>
#include <queue>*/

using namespace std;

//below is a parser where each cable has to be assigned a value before having done any operation for it
//for instance af AND ah -> ai being the first line will cause problems because none of those variables are declared
//to declare a variable one could do 123 -> ah for instance
//operate function elaborates better
/*
unsigned int return_parameter(string parameter, map<string, unsigned int> &wires){
    try {
        wires.at(parameter);
        return wires[parameter];
    } catch (out_of_range &e) {
        try {
            return stoi(parameter);
        } catch (invalid_argument &e) {
            cout << parameter << " is not a number nor a declared variable!" << endl;
            exit(-1);
        }
    }
}

string operate(string operand, map<string, unsigned int> &wires, string param1, string param2){
    string return_val;
    unsigned int p1, p2;
    p1 = return_parameter(param1, wires);

    if (operand == "->"){
        try {
            wires.at(param2);
            wires[param2] = stoi(param1);
        } catch (out_of_range &e) {
            wires.insert(pair<string, unsigned int> (param2, stoi(param1)));
        }
        return_val = param1;
    } else if (operand == "AND") {
        p2 = return_parameter(param2, wires);
        return_val = to_string( p1 & p2 );
    } else if (operand == "OR") {
        p2 = return_parameter(param2, wires);
        return_val = to_string(p1 | p2 );
    } else if (operand == "LSHIFT") {
        p2 = return_parameter(param2, wires);
        return_val = to_string(p1 << p2 );
    } else if (operand == "RSHIFT") {
        p2 = return_parameter(param2, wires);
        return_val = to_string( p1 >> p2 );
    } else if (operand == "NOT") {
        return_val = to_string(~p1);
    } else {
        cout << "Error: unrecognized operand: " << operand << endl;
        exit(-1);
    }
    return return_val;
}

bool is_operator(string operand, map<string, int> command_precedence){
    try{
        command_precedence.at(operand);
        return true;
    } catch (out_of_range &e) {
        return false;
    }
}

void parse_commands(vector<string> commands, map<string, unsigned int> &wires, map<string, int> command_precedence){
    stack<string> operators;
    queue<string> output;
    for(int i=0; i<commands.size(); i++){
        if (!is_operator(commands[i], command_precedence)){
            while (!is_operator(commands[i], command_precedence)){
                output.push(commands[i]);
                i++;
                if (i == commands.size()) {
                    break;
                }
            }
            i -= 1;// because it auto increments by 1 at the end
        } else if (commands[i] == "NOT") { // because not is right oriented so we push the thing at the right then not
            output.push(commands[i+1]);
            output.push("NOT");
            i++;
        } else {
            try {
                int current_precedence = command_precedence.at(commands[i]);
                if (!operators.empty()){
                    while (command_precedence.at(operators.top()) > current_precedence){
                        output.push(operators.top());
                        operators.pop();
                        if (operators.empty()) {
                            break;
                        }
                    }
                    operators.push(commands[i]);
                } else {
                    operators.push(commands[i]);
                }
            } catch (out_of_range &e) {
                cout << "Unknown operator type: " << commands[i] << endl;
                exit(-1);
            }
        }
    }
    while(!operators.empty()){
        output.push(operators.top());
        operators.pop();
    }

    while (!output.empty()){
        string current = output.front();
        output.pop();
        try {
            command_precedence.at(current);
            string param2 = operators.top();
            operators.pop();
            if (current == "NOT") {
                operators.push(operate(current, wires, param2, ""));
            } else {
                string param1 = operators.top();
                operators.pop();
                operators.push(operate(current, wires, param1, param2));
            }
        } catch (out_of_range &e) {
            operators.push(current);
        }
    }
}*/

vector<string> return_sides(string wire, string op){
    vector<string> return_val(2);
    if (op == "NOT"){
        return_val[0] = wire.substr(4, wire.length()-4);
        return return_val;
    }
    int middle = wire.find(op);
    return_val[0] = wire.substr(0, middle-1);
    return_val[1] = wire.substr(middle+1+op.length(), wire.length()-(middle+1+op.length()));
    return return_val;
}


unsigned int get_signal(string wire, map<string, string> &wires){
    try{
        return stoi(wire);
    } catch (invalid_argument &e) {
        wire = wires.at(wire);
        vector<string> sides(2);
       if(wire.find("AND") != string::npos){
           sides = return_sides(wire, "AND");
           return get_signal(sides[0], wires) & get_signal(sides[1], wires);
       } else if(wire.find("OR") != string::npos) {
           sides = return_sides(wire, "OR");
           return get_signal(sides[0], wires) | get_signal(sides[1], wires);
       } else if(wire.find("LSHIFT") != string::npos){
           sides = return_sides(wire, "LSHIFT");
           return get_signal(sides[0], wires) << get_signal(sides[1], wires);
       } else if(wire.find("RSHIFT") != string::npos){
           sides = return_sides(wire, "RSHIFT");
           return get_signal(sides[0], wires) >> get_signal(sides[1], wires);
       } else if(wire.find("NOT") != string::npos){
           sides = return_sides(wire, "NOT");
           return ~get_signal(sides[0], wires);
       } else {
           return get_signal(wire, wires);
       }

    }
}

int main() {
    /*map<string, int> command_precedence = {
            {"->", 1},
            {"AND", 2},
            {"OR", 2},
            {"LSHIFT", 2},
            {"RSHIFT", 2},
            {"NOT", 3}
    };
    map<string, unsigned int> wires;*/
    map<string, string> wires;
    fstream file;
    file.open("../input.txt", fstream::in);
    string line;
    while(getline(file, line)){
        string left = line.substr(0, line.find("->")-1);
        string right = line.substr(line.find("->")+3, line.length()-line.find("->")+3);
        wires.insert(pair<string, string>(right, left));
        //parse_commands(commands, wires, command_precedence);
        //my initial approach was wrong a cable can be declared before it is assigned a value
    }
    file.close();
    cout << get_signal("i", wires) << endl;
    return 0;
}
