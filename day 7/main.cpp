#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

using namespace std;

map<string, int> command_precedence = {
        {"->", 1},
        {"AND", 2},
        {"OR", 2},
        {"LSHIFT", 2},
        {"RSHIFT", 2},
        {"NOT", 3}
};

string operate(string operand, map<string, unsigned int> &wires, string param1, string param2){
    string return_val;
    if (operand == "->"){
        try {
            wires.at(param1);
            wires[param1] = stoi(param2);
        } catch (out_of_range &e) {
            wires.insert(pair<string, unsigned int> (param1, stoi(param2)));
        }
        return_val = param1;
    } else if (operand == "AND") {
        return_val = to_string( stoi(param1) & stoi(param2));
    } else if (operand == "OR") {
        return_val = to_string(stoi(param1) | stoi(param2));
    } else if (operand == "LSHIFT") {
        return_val = to_string(stoi(param1) << stoi(param2));
    } else if (operand == "RSHIFT") {
        return_val = to_string(stoi(param1) >> stoi(param2));
    } else if (operand == "NOT") {
        return_val = to_string(stoi(param1) & stoi(param2));
    } else {
        cout << "Error: unrecognized operand: " << operand << endl;
        exit(-1);
    }
    return return_val;
}

bool is_operator(string operand){
    try{
        command_precedence.at(operand);
        return true;
    } catch (out_of_range &e) {
        return false;
    }
}


void parse_commands(vector<string> commands, map<string, unsigned int> &wires){
    stack<string> operators;
    queue<string> output;
    for(int i=0; i<commands.size(); i++){
        if (!is_operator(commands[i])){
            while (!is_operator(commands[i])){
                output.push(commands[i]);
                i++;
            }
            continue;
        } else if (commands[i] == "NOT") {
            output.push("NOT");
        } else {
            try {
                int current_precedence = command_precedence.at(commands[i]);
                if (!operators.empty()){
                    while (stoi(operators.top()) > current_precedence){
                        output.push(operators.top());
                        operators.pop();
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
    if (!output.empty()) {
        ;
    } else {
        cout << "An error occured during parsing" << endl;
        exit(-1);
    }
}

int main() {
    map<string, unsigned int> wires;
    fstream file;
    file.open("../input.txt", fstream::in);
    string line;
    while(getline(file, line)){
        vector<string> commands;
        string command;
        stringstream ss(line);
        while(getline(ss, command, ' ')){
            commands.push_back(command);
        }
        parse_commands(commands, wires);
    }
    for (auto wire: wires){
        cout << wire.first << ": " << wire.second << endl;
    }
    return 0;
}
