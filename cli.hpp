#ifndef FIELD_CLI_VAR
#define FIELD_CLI_VAR


#include <iostream>
#include <string>
#include <regex>

#include "field.hpp"



class Player {
public:
    // Name and value of player.
    std::string name = "";
    int value = 0;
    // Initialization.
    Player(std::string n, int v) {name = n; value = v;}
};


class CLITicTacToe {
/* Tic Tac Toe with command line interface.
 * Create instance and call .play() to start.
 */
private:

    // Pattern for input.
    std::regex input_pattern{"([0-8])"};
    // Players.
    Player player_1{"Naughts", 1};
    Player player_2{"Crosses", 2};
    // Field.
    Field field;
    // Who is a current player.
    Player *current_player = &player_1;
    // Who is the winner.
    int winner = 0;


    Player next_player() {
        // Changes current player to the next player.
        if (current_player->value == 1) current_player = &player_2;
        else current_player = &player_1;
        return *current_player;
    }


    void turn() {
        // One turn of a game, performed by current player.

        Player player = *current_player;

        //Prints current values.
        std::cout << "Turn of player \"" << player.name << "\":\n";
        field.print_values();

        // Getting an input.
        std::cout << "Place index: ";
        std::string input; std::smatch match;
        std::getline(std::cin, input);

        // If valid, extracts and adds value, else tries again.
        if (std::regex_search(input, match, input_pattern)) {
            int target = std::stoi(match.str());
            // If index not already in use.
            if (field.values[target] == 0) {
                field.values[target] = player.value;
                winner = field.winner();
                next_player();
            }
            else std::cout << "This index is already in use.\n";

        }
        else std::cout << "Invalid input.\n";
    }


public:

    void play() {
        // Method for performing of game play.

        field = {};
        winner = 0;

        std::cout << "The game of Tic Tac Toe:\n";

        while (winner == 0) {
            turn();
        }
        field.print_values();

        if (winner == 3) std::cout << "The draw.\n";
        else std::cout << "The \"" << next_player().name << "\" has won.\n";
    }

};







#endif
