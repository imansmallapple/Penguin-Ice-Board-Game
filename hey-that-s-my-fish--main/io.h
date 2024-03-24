#ifndef _IO_H_
#define _IO_H_

struct GameState{
    int boardX, boardY; /* width and height of the board */
    int **board; /* a 2D array containing the current state of the board */
    int current_player; /* the current player's ID */
    int penguins_left_to_place[2]; /* in the placement phase, an array containing the numer of penguins left for each player to place */
    int penguin_coordinates[2]; /* an array containing the coordinates of the penguin the user wants to move */
    int move_coordinates[2]; /* an array containing the coordinates of the desired penguin placement/destination */
    char game_phase; /* current game phase: 'p' - placement, 'm' - movement, 'e' - end */
    int score[2]; /* an array keeping track of both players' scores */
};

/* io */

/**
 * @brief this function displays the main menu on the screen 
 */
void menu();

/**
 * @brief this function displays the current state of the board on the screen
 * 
 * @param GS a pointer to the structure GameState
 */
void show_board(struct GameState *GS);

/**
 * @brief this function displays the current player's score on the screen 
 * 
 * @param GS a pointer to the structure GameState
 */
void display_score_curr_player(struct GameState *GS);

/**
 * @brief this function displays the menu at the end of the game and compares the scores in order to determine the winner 
 * 
 * @param GS a pointer to the structure GameState
 */
void end_menu(struct GameState *GS);

/**
 * @brief this function asks the player for the dimensions of the board and checks the validity of the inputs
 * 
 * @param GS a pointer to the structure GameState
 * 
 * @return the width and height of the board
 */
void dec_board_dims(struct GameState *GS);

/**
 * @brief this function asks the player for the number of penguins each player can place on the board
 * 
 * @param GS a pointer to the structure GameState
 * 
 * @return an array containing the number of penguins each player can place
 */
void dec_number_of_penguins_per_player(struct GameState *GS);

/**
 * @brief this function allows the player to declare the X and Y coordinates of the tile they want to place a penguin on 
 * 
 * @param GS a pointer to the structure GameState
 * 
 * @return the X and Y coordinates of the tile 
 */
void dec_placement(struct GameState *GS);

/**
 * @brief this function allows the player to declare the X and Y coordinates of the penguin they want to move 
 * 
 * @param GS a pointer to the structure GameState 
 * 
 * @return the X and Y coordinates of the penguin
 */
void dec_pen_to_move(struct GameState *GS);

/**
 * @brief this function allows the player to declare the X and Y coordinates of the tile they want to move their chosen penguin to
 * 
 * @param GS a pointer to the structure GameState
 * 
 * @return the X and Y coordinates of the tile 
 */
void dec_movement(struct GameState *GS);

#endif