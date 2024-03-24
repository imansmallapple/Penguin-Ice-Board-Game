#ifndef CHECKS_H_
#define CHECKS_H_

int is_positive(int a); /* a is a number, 
the function returns 0 if a <= 0 and 1 if a > 0 */
int is_last_player(int a, int b); /* a is the current player's ID, b is the total number of players,
the function checks if it's the last player's turn */
int is_placement_valid_x(int a, int b); /*checks the validity of the desired x placement */
int is_placement_valid_y(int a, int b); /*checks the validity of the desired y placement */

#endif