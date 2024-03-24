#ifndef _GAMELOGIC_H_
#define _GAMELOGIC_H_

#include "io.h"

extern struct GS;

/* game logic */

/**
 * @brief checks if any players have penguins left to place
 * 
 * @param GS a pointer to a GameState structure
 * 
 * @return 1 if true, 0 if false
 */
int penguins_available(struct GameState *GS);

/**
 * @brief checks if the current player has penguins left to place 
 * 
 * @param GS a pointer to a GameState structure
 * 
 * @return 1 if true, 0 if false 
 */
int penguins_available_curr_player(struct GameState *GS);

/**
 * @brief checks if the desired placement is a valid one
 * 
 * @param GS a pointer to a GameState structure
 * 
 * @return 1 if true, 0 if false
 */
int is_placement_valid(struct GameState *GS);

/**
 * @brief checks if the tile is within the boundaries of the board
 * 
 * @param GS a pointer to a GameState structure 
 * @param pos_x the x coordinate of the tile
 * @param pos_y the y coordinate of the tile
 * 
 * @return 1 if true, 0 if false
 */
int isSafe(struct GameState *GS, int pos_x, int pos_y);

/**
 * @brief checks if there are any available moves for the current player
 * 
 * @param GS a pointer to a GameState structure  
 * 
 * @return 1 if true, 0 if false
 */
int is_move_available(struct GameState *GS);

/**
 * @brief checks if the chosen penguin can make a move
 *
 * 
 * @param GS a pointer to a GameState structure
 * 
 * @return 1 if true, 0 if false
 */
int is_move_available_chosen_pen(struct GameState *GS);

/**
 * @brief checks if the player chose a tile with a penguin which can move on it 
 * 
 * @param GS a pointer to a GameState structure
 * 
 * @return 1 if ture, 0 if false
 */
int is_choice_valid(struct GameState *GS);

/**
 * @brief checks if the desired move is valid 
 * 
 * @param GS a pointer to GameState structure 
 * 
 * @return 1 if true, 0 if false 
 */
int is_movement_valid(struct GameState *GS);

#endif