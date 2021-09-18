#include <iostream>

int main() {
    uint_fast64_t repeating_count;
    char digit;
    uint_fast64_t iteration_count;
    uint_fast64_t i, j;
    std::string input;
    std::string next;

    input = "1113222113";
    iteration_count = 50;

    for (i=0; i<iteration_count; i++) {
        next = "";
        digit = input[0];
        repeating_count = 0;
        for (j=0; j<input.length(); j++) {
            if (input[j] != digit) {
                next += std::to_string(repeating_count);
                next += digit;
                digit = input[j];
                repeating_count = 1;
            } else {
                repeating_count++;
            }
        }
        next += std::to_string(repeating_count);
        next += digit;
        input = next;
    }
    std::cout << input.length() << std::endl;
    return EXIT_SUCCESS;
}
