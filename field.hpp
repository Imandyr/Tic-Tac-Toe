#ifndef FIELD_VAR
#define FIELD_VAR


#include <array>
#include <algorithm>
#include <iostream>
#include <unordered_map>


class Field {
/*
* The class of Tic Tac Toe field.
* Game values are contained in "values" int array, where naughts are 1s, and crosses are 2s.
*/

private:
    // Char converter.
    std::unordered_map<int, char> char_converter = {{0, '.'}, {1, 'o'}, {2, 'x'}};

public:

    // Main container for game values.
    std::array<int, 9> values = {};

    // Default initialization.
    Field() {}

    // Initialization of values using values from another array.
    Field(std::array<int, 9> input) {values = input;}

    bool have_line(int number) {
        // Does field have line with given number or not.
        if (values[0] == number) {
            if (
                (values[1] == number && values[2] == number) ||
                (values[3] == number && values[6] == number) ||
                (values[4] == number && values[8] == number)
            ) return true;
        }
        if (values[6] == number) {
            if (
                (values[4] == number && values[2] == number) ||
                (values[7] == number && values[8] == number)
            ) return true;
        }
        if (values[5] == number) {
            if (
                (values[2] == number && values[8] == number) ||
                (values[3] == number && values[4] == number)
            ) return true;
        }
        if (values[1] == number && values[4] == number && values[7] == number) return true;
        return false;
    }

    int winner() {
        // Returns 0 if no winners, 1 if naughts have won, 2 if crosses have won and 3, if it's a draw.
        if (have_line(1)) return 1;
        if (have_line(2)) return 2;
        if (std::find(values.begin(), values.end(), 0) == values.end()) return 3;
        return 0;
    }

    void print_values() {
        // Prints values of field.
        for (uint i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0) std::cout << "\n";
            std::cout << char_converter[values[i]] << " ";
        }
        std::cout << "\n";
    }

};


template <typename T> void print_1d_iter(T &iter) {
    // Function which prints content of 1d iterator.
    std::cout << "[";
    for (auto i : iter) std::cout << "\"" << i << "\", ";
    std::cout << "]\n";
}


#endif
