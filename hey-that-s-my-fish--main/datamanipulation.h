#ifndef _DATAMANIPULATION_H_
#define _DATAMANIPULATION_H_

#include "io.h"

extern struct GS;

/* data manipulation */

/**
 * @brief this function reduces the number of penguins available to place for the current player
 * 
 * @param GS a pointer to the structure GameState
 */
void reduce_no_of_pen(struct GameState *GS);

/**
 * @brief this function changes the current player
 * 
 * @param GS a pointer to the structure GameState
 */
void change_curr_player(struct GameState *GS);

/**
 * @brief this function adds the number of collected fish to the current palyer's score
 * 
 * @param GS a pointer to the structure GameState
 */
void add_score(struct GameState *GS);

#endif