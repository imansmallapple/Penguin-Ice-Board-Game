#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boardoperations.h"

void gen_board(struct GameState *GS){

    srand(time(NULL));

    GS->board = (int**)malloc(GS->boardY * (sizeof(int*)));

    for(int i = 0; i < GS->boardY; i++)
    {
            (GS->board)[i] = (int*)malloc(sizeof(int) * GS->boardX);
    }
    for(int i = 0; i < GS->boardY; i++)
    {
        for(int j = 0; j < (GS->boardX); j++)
        {
            int temp = rand() % (3 - 0 + 1) + 0;
            if(temp == 0)
            {
                (GS->board)[i][j] = 0;
            }
            else if(temp == 1)
            {
                (GS->board)[i][j] = 10;
            }
            else if(temp == 2)
            {
                (GS->board)[i][j] = 20;
            }
            else if(temp == 3)
            {
                (GS->board)[i][j] = 30;
            }
        }
    }
}

void update_board_p(struct GameState *GS){

    if(GS->current_player == 1)
    {
        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] = 1;
    }
    else
    {
        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] = 2;
    }
}

void update_board_m(struct GameState *GS){

    if(GS->current_player == 1)
    {
        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] = 1;
    }
    else if(GS->current_player == 2)
    {
        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] = 2;
    }

    GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 1] = 0;
}
