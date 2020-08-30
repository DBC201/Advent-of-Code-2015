#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int substr(string main, string sub){
    // should have used a map for bad words here for O(1) time smh x 2
    if(main.length() < sub.length()){
        return -1;
    }
    for(int i=0; i<main.length(); i++){
        bool valid = true;
        for(int j=0; j<sub.length(); j++){
            if(main[i+j] != sub[j]){
                valid = false;
                break;
            }
        }
        if(valid){
            return i;
        }
    }
    return -1;
}

bool letter_twice(string str){
    for(int i=1; i<str.length(); i++){
        if(str[i-1] == str[i]){
            return true;
        }
    }
    return false;
}

bool enough_vowels(string str){
    map<char, int> vowels = { // O(1) lookup time? well doesn't really matter for 5 variables actually smh
        {'a', 1},
        {'e', 1},
        {'i', 1},
        {'o', 1},
        {'u', 1}
    };
    int vowel_count = 0;
    for (char letter: str){
        try{
            vowels.at(letter);
            vowel_count++;
        } catch (out_of_range &e) {
            ;
        }
    }
    return vowel_count >= 3;
}


bool has_between(string str){
    for(int i=2; i<str.length(); i++){
        if(str[i-2] == str[i]){
            return true;
        }
    }
    return false;
}

bool has2pairs(string str){
    for(int i=1; i<str.length(); i++){
        string main = str.substr(i-1, 2);
        for(int j=i+1; j<str.length(); j++){
            string current = str.substr(j-1, 2);
            if( (main[0] == main[1]) && (i == j-1) ){ //in case 3 same letters
                continue;
            }else if(current == main){
                return true;
            }
        }
    }
    return false;
}


bool valid_part2(string str){
    return has2pairs(str) && has_between(str);
}


int main() {
    fstream file;
    file.open("../input.txt", fstream::in);
    string str;
    string bad_strings[]= {"ab", "cd", "pq", "xy"};
    int good_count1 = 0, good_count2 = 0;
    while(getline(file, str)){
        if(valid_part2(str)){
            good_count2++;
        }
        bool valid = true;
        for(string bad: bad_strings){
            if(substr(str, bad) != -1){
                valid = false;
            }
        }
        if(!letter_twice(str)){
            valid = false;
        }
        if(!enough_vowels(str)){
            valid = false;
        }
        if(valid){
            good_count1++;
        }
    }
    file.close();
    cout << good_count1 << " " << good_count2 << endl;
    return 0;
}
