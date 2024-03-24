#ifndef _BOARDOPERATIONS_H_
#define _BOARDOPERATIONS_H_

#include "io.h"

extern struct GS;

/* board operations */

/**
 * @brief this function generates the board
 * 
 * @param GS a pointer to the structure GameState
 */
void gen_board(struct GameState *GS);

/**
 * @brief this function updates the board during the placement phase
 * 
 * @param GS a pointer to the structure GameState
 */
void update_board_p(struct GameState *GS);

/**
 * @brief this function updates the board during the movement phase
 * 
 * @param GS a pointer to the structure GameState
 */
void update_board_m(struct GameState *GS);

#endif