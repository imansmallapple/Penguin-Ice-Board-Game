#ifndef DATAMANIP_H_
#define DATAMANIP_H_

void gen_board(int a, int b, int c); /*a is the width of the board, b is the height of the board, c is the number of players,
generating a random board */
void write_placement(int a, int b); /* write the placement of a penguin to the board.txt file */
void process_move(int a, int b);
void add_score(int a, int b);
#endif