#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define ON 'o'
#define OFF 'x'

int width = 1000;
int height = 1000;

vector<int> return_rectangle(vector<int> start, vector<int> finish) { // returns a rectangle relative to start point
    vector<int> return_val(2);
    return_val[0] = abs(finish[0] - start[0]);
    return_val[1] = abs(finish[1] - start[1]);
    return return_val;
}

vector<int> return_coordinates(string coordinates){
    stringstream ss(coordinates);
    vector<int> return_value;
    string coordinate;
    while(getline(ss, coordinate, ',')){
        return_value.push_back(stoi(coordinate));
    }
    return return_value;
}


void toggle(vector<char> &lights, vector<int> start, vector<int> finish) {
    vector<int> rectangle = return_rectangle(start, finish);
    int row_start = start[0] + (width*start[1]);
    for (int row=0; row<=rectangle[1]; row++){
        for (int light=row_start; light<=row_start+rectangle[0]; light++) {
            if (lights[light] == OFF) {
                lights[light] = ON;
            } else if (lights[light] == ON) {
                lights[light] = OFF;
            } else {
                cout << "Unrecognized light state: " << lights[light] << endl;
                exit(-1);
            }
        }
        row_start += width;
    }
}

void turn(vector<char> &lights, vector<int> start, vector<int> finish, bool turn_on){
    vector<int> rectangle = return_rectangle(start, finish);
    int row_start = start[0] + (width*start[1]);
    for (int row=0; row<=rectangle[1]; row++){
        for (int light=row_start; light<=row_start+rectangle[0]; light++) {
            if (turn_on) {
                lights[light] = ON;
            } else {
                lights[light] = OFF;
            }
        }
        row_start += width;
    }
}

void toggle2(vector<int> &lights, vector<int> start, vector<int> finish) {
    vector<int> rectangle = return_rectangle(start, finish);
    int row_start = start[0] + (width*start[1]);
    for (int row=0; row<=rectangle[1]; row++){
        for (int light=row_start; light<=row_start+rectangle[0]; light++) {
            lights[light] += 2;
        }
        row_start += width;
    }
}

void turn2(vector<int> &lights, vector<int> start, vector<int> finish, bool turn_on){
    vector<int> rectangle = return_rectangle(start, finish);
    int row_start = start[0] + (width*start[1]);
    for (int row=0; row<=rectangle[1]; row++){
        for (int light=row_start; light<=row_start+rectangle[0]; light++) {
            if (turn_on) {
                lights[light]++;
            } else if (lights[light] > 0){
                lights[light]--;
            }
        }
        row_start += width;
    }
}

void show_lights(vector<char> lights){
    for (int i=0; i<lights.size(); i++){
        if ( (i == width) || (i > width && i%width == 0)  ){
            cout << endl;
        }
        cout << lights[i] << " ";
    }
    cout << endl;
}

int main() {
    // 1000 x 1000 grid
    // o means on x means off
    vector<char> lights(width * height);
    vector<int> lights2(width * height);
    for (int i = 0; i < lights.size(); i++) {
        lights[i] = OFF;
        lights2[i] = 0;
    }
    fstream file;
    file.open("../input.txt", fstream::in);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string param;
        vector<string> command;
        while (ss >> param) {
            command.push_back(param);
        }
        if (command[0] == "toggle") {
            toggle(lights, return_coordinates(command[1]), return_coordinates(command[3]));
            toggle2(lights2, return_coordinates(command[1]), return_coordinates(command[3]));
        } else if (command[1] == "on") {
            turn(lights, return_coordinates(command[2]), return_coordinates(command[4]), true);
            turn2(lights2, return_coordinates(command[2]), return_coordinates(command[4]), true);
        } else if (command[1] == "off") {
            turn(lights, return_coordinates(command[2]), return_coordinates(command[4]), false);
            turn2(lights2, return_coordinates(command[2]), return_coordinates(command[4]), false);
        } else {
            cout << "Error, unrecognized command: " << line << endl;
            exit(-1);
        }
    }
    file.close();
    int on_count = 0;
    int brightness = 0;
    for (int i=0; i<lights.size(); i++){
        if(lights[i] == ON){
            on_count++;
        }
        brightness += lights2[i];
    }
    cout << on_count << " " << brightness << endl;
    return 0;
}
