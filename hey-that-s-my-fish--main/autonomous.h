#ifndef _AUTONOMOUS_H_
#define _AUTONOMOUS_H_

struct Params{
    char mode;
    char game_phase;
    int **board;
    int penguin_count;
    int no_of_players;
    int my_id;
    char *names[9];
    int ids[9];
    int scores[9];
    int boardX;
    int boardY;
};

/* autonomous mode */

/**
 * @brief this function processes the parameters given by the user
 * 
 * @param Params a pointer to the structure Params
 * @param argc the number of parameters provided by the user (includes the name of the executable file in space 0)
 * @param argv an array containing the parameters provided by the user  
 */
void process_params(struct Params *Params, int argc, char *argv[]);

/**
 * @brief this function fetches the names of the input and outpt files given by the user 
 * 
 * @param Params a pointer to the structure Params
 * @param argv an array containing the paramaters provided by the user
 */
void get_file_names(struct Params *Params, char *argv[]);

/**
 * @brief this function fetches the amount of penguins to place 
 * 
 * @param Params a pointer to the structure Params 
 * @param argv an array containing the paramaters provided by the user
 */
void get_penguin_count(struct Params *Params, char *argv[]);

/**
 * @brief this function fetches all the data from the input file(dimensions of the board, the state of the board, palyers' ids, names and scores)
 * 
 * @param Params a pointer to the structure Params 
 * @param argv an array containing the paramaters provided by the user 
 * 
 * @return this function returns 0 if the data is read and 2 if there is an error
 */
int get_board(struct Params *Params, char *argv[]);

/**
 * @brief this function check if this team's name is present in the file and if not, it adds it
 * 
 * @param Params a pointer to the structure Params 
 * @param argv an array containing the paramaters provided by the user 
 */
void is_name_in_file(struct Params *Params, char* argv[]);

/**
 * @brief this function checks if the tile which is about to be operated on is within the boundaries of the board
 * 
 * @param Params a pointer to the structure Params
 * @param x the x coordinate of the tile
 * @param y the y coordinate of the tile
 * 
 * @return 1 if true, 0 if false
 */
int isSafe2(struct Params *Params, int x, int y);

/**
 * @brief this function checks if there are any available moves
 * 
 * @param Params a pointer to the structure Params
 * 
 * @return 1 is there are available moves, 0 if no moves are available
 */
int is_move_available2(struct Params *Params);

/**
 * @brief this function checks if the penguin chosen by the computer can move 
 * 
 * @param Params a pointer to the structure Params 
 * 
 * @return 1 if true, 0 if false
 */
int is_move_available_chosen_pen2(struct Params *Params);

/**
 * @brief this fuction places a penguin on the board during the placement phase
 * 
 * @param Params a pointer to the structure Params 
 * 
 * @return 0 if penguin placed correctly, 1 if no placements available 
 */
int place_penguin(struct Params *Params);

/**
 * @brief this function makes a move in the movement phase 
 * 
 * @param Params a pointer to the structure Params 
 * @param argv an array containing the paramaters provided by the user 
 * 
 * @return 1 if move made, 0 if no moves available 
 */
int make_movement(struct Params *Params);

/**
 * @brief this function writes the state of the game to the output file specified by the user
 * 
 * @param Params a pointer to the structure Params 
 * @param argv an array containing the paramaters provided by the user  
 */
void write_board(struct Params *Params, char *argv[]);

/**
 * @brief this function displays the team's name
 * 
 * @param Params a pointer to the structure Params 
 */
void display_name(struct Params *Params);

#endif