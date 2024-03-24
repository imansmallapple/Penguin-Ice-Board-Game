#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datamanipulation.h"

/* data manipluation */
void reduce_no_of_pen(struct GameState *GS){
    GS->penguins_left_to_place[GS->current_player - 1]--;
    printf("No of penguins left for player %d: %d. \n", GS->current_player,GS->penguins_left_to_place[GS->current_player - 1]);
}

void change_curr_player(struct GameState *GS){
    if(GS->current_player == 2)
    {
        GS->current_player = 1;
    }
    else
    {
        GS->current_player++;
    }
}

void add_score(struct GameState *GS){
    
    if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 10)
    {
        GS->score[GS->current_player - 1] += 1;
    }
    else if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 20)
    {
        GS->score[GS->current_player - 1] += 2;
    }
    else if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 30)
    {
        GS->score[GS->current_player - 1] += 3;
    }
}