#include <iostream>
#include <fstream>

int count_literal (std::string str) {
    str = str.substr(1, str.length()-2);
    int count = 0;
    for (int i=0; i<str.length(); i++) {
        if ( str[i] == '\\' && (str[i+1] == '\\' || str[i+1] == '"')) {
            i++;
        } else if (str[i] == '\\') {
            i += 3;
        }
        count++;
    }
    return count;
}

int count_new_increase (std::string str) {
    str = str.substr(1, str.length()-2);
    int increase = 4;
    for (int i=0; i<str.length(); i++) {
        if ( str[i] == '\\' && (str[i+1] == '\\' || str[i+1] == '"')) {
            i++;
            increase += 2;
        } else if (str[i] == '\\') {
            i += 3;
            increase++;
        }
    }
    return increase;
}

int main() {
    std::fstream file;
    file.open("../input.txt", std::fstream::in);
    if (!file.is_open()) {
        std::cout << "unable to open file" << std::endl;
        return -1;
    }
    std::string line;
    int literal_count = 0, memory_space = 0, new_count = 0;
    while (getline(file, line)) {
        memory_space += line.length();
        literal_count += count_literal(line);;
        new_count += line.length()+count_new_increase(line);
    }
    std::cout << memory_space-literal_count << std::endl;
    std::cout << new_count-memory_space << std::endl;
    return 0;
}
