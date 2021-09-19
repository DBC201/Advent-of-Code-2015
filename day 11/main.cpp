#include <iostream>
#include <unordered_set>

bool has_increasing_three(std::string str) {
    int i;
    for (i=0;i<str.length()-3; i++) {
        if (str[i] == str[i+1]-1 && str[i+2]-1 == str[i+1]) {
            return true;
        }
    }
    return false;
}

bool no_forbidden_characters(std::string str) {
    std::unordered_set<char> forbiddens = {
      'i',
      'o',
      'l'
    };
    for (const auto &c: str) {
        if (forbiddens.find(c) != forbiddens.end()) {
            return false;
        }
    }
    return true;
}

bool has_two_pairs(std::string str) {
    int i;
    int pair_count = 0;
    char last_pair;
    last_pair = '\0';
    for (i=0; i<str.length()-1; i++) {
        if (str[i] == str[i+1] && str[i] != last_pair) {
            last_pair = str[i];
            pair_count++;
            i++;
        }

        if (pair_count >= 2) {
            return true;
        }
    }
    return pair_count >= 2;
}

void increment_password (std::string &password) {
    bool increment_next;
    int index = password.length() - 1;
    do {
        increment_next = false;
        password[index] = ++password[index];
        if (password[index] > 'z') {
            password[index] = 'a';
            index--;
            if (index < 0) {
                return;
            }
            increment_next = true;
        }
    } while (increment_next);
}

int main() {
    std::string password = "cqjxxyzz";
    do  {
        increment_password(password);
    } while (
            !(
                    has_increasing_three(password)
                    && no_forbidden_characters(password)
                    && has_two_pairs(password)
            )
    );
    std::cout << password << std::endl;
    return 0;
}
