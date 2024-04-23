#include <iostream>
#include <array>
#include <vector>
#include <stdexcept>
#include <string>

#include "../field.hpp"


void test_of_init() {
    // Test of initialization.
    Field field = {{1, 2, 3, 4, 5, 6}};
    if (field.values != std::array<int, 9>({1, 2, 3, 4, 5, 6}))
        throw std::logic_error("Invalid work of initialization.");
}


void test_of_have_line_1() {
    // Test of line detection.
    Field field;
    std::vector<std::array<int, 9>> all_variants;

    for (int v = 0; v <= 2; ++v) {
        all_variants = {
            {v, v, v, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, v, v, v, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, v, v, v},
            {v, 0, 0, v, 0, 0, v, 0, 0},
            {0, v, 0, 0, v, 0, 0, v, 0},
            {0, 0, v, 0, 0, v, 0, 0, v},
            {v, 0, 0, 0, v, 0, 0, 0, v},
            {0, 0, v, 0, v, 0, v, 0, 0},
            {v, v, v, v, v, v, v, v, v},
        };

        for (auto i : all_variants) {
            field.values = i;
            // field.print_values();
            // std::cout << "\n";

            if (!field.have_line(v)) {
                std::string err_str = "Field.have_line() doesn't count ";
                for (auto c : i) err_str += std::to_string(c);
                throw std::logic_error(err_str + " as line.");
            }
        }

    }
}


int main() {

//     try {
//         test_of_init();
//         test_of_have_line_1();
//         std::cout << "All tests were passed.\n";
//     }
//     catch (std::logic_error &err) {
//         std::cout << err.what() << "\n";
//     }

    test_of_init();
    test_of_have_line_1();

    std::cout << "All tests were passed.\n";

    return 0;
}


