#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    fstream file;
    int total_area, total_ribbon = 0;
    file.open("../input.txt", fstream::in);
    string line;
    //rectangular prism area + area of smallest side
    while(getline(file, line)){
        stringstream ss(line);
        string number;
        vector<int> lwh;
        while(getline(ss, number, 'x')){
            lwh.push_back(stoi(number));
        }
        sort(lwh.begin(), lwh.end());
        int smallest_side = lwh[0] * lwh[1];
        int area = 0;
        int volume = lwh[0] * lwh[1] * lwh[2];
        int smallest_perimeter = (lwh[0] + lwh[1]) * 2;
        total_ribbon += volume + smallest_perimeter;
        for(int i=0; i<lwh.size(); i++){// yes i was too lazy to type
            if(i == lwh.size()-1){
                area += lwh[i] * lwh[0] * 2;
                break;
            }
            area += lwh[i] * lwh[i+1] * 2;
        }
        total_area += area + smallest_side;
        lwh.clear();
    }
    file.close();
    cout << total_area << " " << total_ribbon << endl;
    return 0;
}
