#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void move_distiributor(vector<int> &distiributor, char step){
    if(step == '^'){
        distiributor[1]++;
    }else if(step == 'v'){
        distiributor[1]--;
    }else if(step == '>'){
        distiributor[0]++;
    }else if(step == '<'){
        distiributor[0]--;
    }else{
        cout << "Unknown dir: " << step << endl;
        exit(-1);
    }
}

int main() {
    map<string, int> houses;
    fstream file;
    string steps;
    file.open("../input.txt", fstream::in);
    file >> steps;
    file.close();
    int x,y = 0;
    vector<int> robot(2);
    vector<int> santa(2);
    houses.insert(pair<string, int>("0,0", 1));
    for(int i=0; i<steps.size(); i++){
        //solution for part 1 comment if statements
        /*move_distiributor(santa, steps[i]);
        x = santa[0];
        y = santa[1];*/
        if (i%2 == 0){
            move_distiributor(santa, steps[i]);
            x = santa[0];
            y = santa[1];
        } else {
            move_distiributor(robot, steps[i]);
            x = robot[0];
            y = robot[1];
        }
        string coords;
        coords = to_string(x) + ',' +to_string(y);
        try{
            houses.at(coords) += 1;
        } catch (out_of_range &e) {
            houses.insert(pair<string, int>(coords, 1));
        }
    }
    cout << houses.size() << endl;
    return 0;
}
