#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int return_floor(string inst){
    int floor = 0;
    for(char c: inst){
        if(c == '('){
            floor++;
        }else if(c == ')'){
            floor--;
        }else{
            cout << "\a Wrong input: " << c << endl;
            exit(-1);
        }
    }
    return floor;
}

vector<int> basement_indexes(string inst){
    vector<int> return_vec;
    int floor = 0;
    for(int i=0; i<inst.length(); i++){
        if (floor == -1){
            return_vec.push_back(i);
            // no i-1 because index starts from 0 and the fact that i increases
            // after each iteration makes up
        }
        if(inst[i] == '('){
            floor++;
        }else if(inst[i] == ')'){
            floor--;
        }else{
            cout << "Unknown character: " << inst[i] << endl;
            exit(-1);
        }
    }
    return return_vec;
}

int main() {
    fstream file;
    string input;
    file.open("../input.txt", fstream::in);
    file >> input;
    file.close();
    cout << return_floor(input) << endl;
    cout << basement_indexes(input)[0] << endl;
    return 0;
}
