#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "gamelogic.h"


/* game logic */

int penguins_available(struct GameState *GS){

    int pen_available = 0;

    for(int i = 0; i < 2; i++)
    {
        if(GS->penguins_left_to_place[i] > 0)
        {
            pen_available = 1;
            break;
        }
    }

    if(pen_available == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
} 

int penguins_available_curr_player(struct GameState *GS){

    int pen_available_curr = 0;

    if(GS->penguins_left_to_place[GS->current_player - 1] > 0)
    {
        pen_available_curr = 1;
    }

    if(pen_available_curr == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_placement_valid(struct GameState *GS){
    int valid = 1;

    if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 0)
    {
        printf("You cannot place a penguin on water, please try again. \n");
        valid = 0;
    }
    else if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] < 10 && GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] > 0)
    {
        printf("You cannot place a penguin on a tile that has another penguin on it, please try again. \n");
        valid = 0;
    }

    if(valid == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSafe(struct GameState *GS, int pos_x, int pos_y){

    if(pos_x >= 0 && pos_x < GS->boardX && pos_y >= 0 && pos_y < GS->boardY)
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}

int is_move_available(struct GameState *GS){
    
    int move_available = 0;

    if(GS->current_player == 1)
    {
        for(int i = 0; i < GS->boardY; i++)
        {
            for(int j = 0; j < GS->boardX; j++)
            {
                if(GS->board[i][j] == 1)
                {
                    if(isSafe(GS, i - 1, j) == 1)
                    {
                        if( GS->board[i - 1][j] == 10 ||
                            GS->board[i - 1][j] == 20 ||
                            GS->board[i - 1][j] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }
                    
                    if(isSafe(GS, i, j + 1) == 1)
                    {
                        if( GS->board[i][j + 1] == 10 ||
                            GS->board[i][j + 1] == 20 ||
                            GS->board[i][j + 1] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }

                    if(isSafe(GS, i + 1, j) == 1)
                    {
                        if( GS->board[i + 1][j] == 10 ||
                            GS->board[i + 1][j] == 20 ||
                            GS->board[i + 1][j] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }

                    if(isSafe(GS, i, j - 1) == 1)
                    {
                        if( GS->board[i][j - 1] == 10 ||
                            GS->board[i][j - 1] == 20 ||
                            GS->board[i][j - 1] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }
                }
            }
        }
    }
    else if (GS->current_player == 2)
    {
        for(int i = 0; i < GS->boardY; i++)
        {
            for(int j = 0; j < GS->boardX; j++)
            {
                if(GS->board[i][j] == 2)
                {
                    if(isSafe(GS, i - 1, j) == 1)
                    {
                        if( GS->board[i - 1][j] == 10 ||
                            GS->board[i - 1][j] == 20 ||
                            GS->board[i - 1][j] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }
                    
                    if(isSafe(GS, i, j + 1) == 1)
                    {
                        if( GS->board[i][j + 1] == 10 ||
                            GS->board[i][j + 1] == 20 ||
                            GS->board[i][j + 1] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }

                    if(isSafe(GS, i + 1, j) == 1)
                    {
                        if( GS->board[i + 1][j] == 10 ||
                            GS->board[i + 1][j] == 20 ||
                            GS->board[i + 1][j] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }

                    if(isSafe(GS, i, j - 1) == 1)
                    {
                        if( GS->board[i][j - 1] == 10 ||
                            GS->board[i][j - 1] == 20 ||
                            GS->board[i][j - 1] == 30)
                            {
                                move_available = 1;
                                return move_available;
                            }
                    }
                }
            }
        }
    }    

    if(move_available == 0)
    {
       return move_available; 
    }
}

int is_move_available_chosen_pen(struct GameState *GS){

    int move_available = 0;
    if(isSafe(GS, GS->penguin_coordinates[0] - 2, GS->penguin_coordinates[1] - 1) == 1)
    {
        if(GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 2] == 10 ||
        GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 2] == 20 ||
        GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 2] == 30)
        {
            move_available = 1;
            return 1;
        }
    }
    if(isSafe(GS, GS->penguin_coordinates[0] - 1, GS->penguin_coordinates[1]) == 1)
    {
        if(GS->board[GS->penguin_coordinates[1]][GS->penguin_coordinates[0] - 1] == 10 ||
        GS->board[GS->penguin_coordinates[1]][GS->penguin_coordinates[0] - 1] == 20 ||
        GS->board[GS->penguin_coordinates[1]][GS->penguin_coordinates[0] - 1] == 30)
        {
            move_available = 1;
            return 1;
        }
    }
    if(isSafe(GS, GS->penguin_coordinates[0], GS->penguin_coordinates[1] - 1) == 1)
    {
        if(GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0]] == 10 ||
        GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0]] == 20 ||
        GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0]] == 30)
        {
            move_available = 1;
            return 1;
        }
    }    
    if(isSafe(GS, GS->penguin_coordinates[0] - 1, GS->penguin_coordinates[1] - 2) == 1)
    {
        if(GS->board[GS->penguin_coordinates[1] - 2][GS->penguin_coordinates[0] - 1] == 10 ||
        GS->board[GS->penguin_coordinates[1] - 2][GS->penguin_coordinates[0] - 1] == 20 ||
        GS->board[GS->penguin_coordinates[1] - 2][GS->penguin_coordinates[0] - 1] == 30)
        {
            move_available = 1;
            return 1;
        }
    }

    if(move_available == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int is_choice_valid(struct GameState *GS){

    if(GS->current_player == 1)
    {
        if(GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 1] != 1)
        {
            printf("Please select a tile with Your penguin on it.\n");
            return 0;
        }
    }
    else if(GS->current_player == 2)
    {
        if(GS->board[GS->penguin_coordinates[1] - 1][GS->penguin_coordinates[0] - 1] != 2)
        {
            printf("Please select a tile with Your penguin on it.\n");
            return 0;
        }
    }

    if(is_move_available_chosen_pen(GS) == 0)
    {
        printf("This penguin cannot move, please choose a different one.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int is_movement_valid(struct GameState *GS){

    int valid = 1;
    int distance_x = (GS->penguin_coordinates[0] - GS->move_coordinates[0]);
    int distance_y = (GS->penguin_coordinates[1] - GS->move_coordinates[1]);

    if(abs(distance_x) <= 3 && abs(distance_y) == 0 ||
       abs(distance_x) == 0 && abs(distance_y) <= 3)
    {   
        if(distance_y == 0)
        {   
            if(isSafe(GS, GS->move_coordinates[0] - 1, GS->move_coordinates[1] - 1) == 0)
            {
                valid = 0;
                printf("Please choose a tile which is within the boundaries of the board.\n");
                return 0;
            }

            if(distance_x == 0)
            {
                printf("Please select a tile different than the one your penguin is standing on.\n");
                valid = 0;
            }
            else if(distance_x > 0)
            {
                for(int i = 1; i < abs(distance_x); i++)
                {   
                    if(isSafe(GS, GS->move_coordinates[0] - 1 + i, GS->move_coordinates[1] - 1) == 1)
                    {
                       if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 + i] == 10 ||
                        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 + i] == 20 ||
                        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 + i] == 30)
                        {
                            if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 1 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 2 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 0)
                            {
                                printf("You cannot move to a tile with a penguin on it or on water.\n");
                                valid = 0;
                                break;
                            }
                        }
                        else
                        {   
                            printf("The penguins cannot jump over water or other penguins, please try again.\n");
                            valid = 0;
                            break;
                        } 
                    }
                }
            }
            else if(distance_x < 0)
            {   
                for(int i = 1; i < abs(distance_x); i++)
                {   
                    if(isSafe(GS, GS->move_coordinates[0] - 1 - i, GS->move_coordinates[1] - 1) == 1)
                    {
                        if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 - i] == 10 ||
                        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 - i] == 20 ||
                        GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1 - i] == 30)
                        {
                            if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 1 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 2 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 0)
                            {
                                printf("You cannot move to a tile with a penguin on it or on water.\n");
                                valid = 0;
                                break;
                            }
                        }
                        else
                        {   
                            printf("The penguins cannot jump over water or other penguins, please try again.\n");
                            valid = 0;
                            break;
                        }
                    }
                }
            }
        }
        else if(distance_x == 0)
        {
            if(distance_y == 0)
            {
                printf("Please select a tile different than the one your penguin is standing on.\n");
                valid = 0;
            }
            else if (distance_y > 0)
            {
                for(int i = 1; i < abs(distance_y); i++)
                {   
                    if(isSafe(GS, GS->move_coordinates[0] - 1, GS->move_coordinates[1] - 1 + i) == 1)
                    {
                        if(GS->board[GS->move_coordinates[1] - 1 + i][GS->move_coordinates[0] - 1] == 10 ||
                        GS->board[GS->move_coordinates[1] - 1 + i][GS->move_coordinates[0] - 1] == 20 ||
                        GS->board[GS->move_coordinates[1] - 1 + i][GS->move_coordinates[0] - 1] == 30)
                        {
                            if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 1 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 2 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 0)
                            {
                                printf("You cannot move to a tile with a penguin on it or on water.\n");
                                valid = 0;
                                break;
                            }
                        }
                        else
                        {   
                            printf("The penguins cannot jump over water or other penguins, please try again.\n");
                            valid = 0;
                            break;
                        }
                    }
                }
            }
            else if (distance_y < 0)
            {
                for(int i = 1; i < abs(distance_y); i++)
                {
                    if(isSafe(GS, GS->move_coordinates[0] - 1, GS->move_coordinates[1] - 1 - i) == 1)
                    {
                        if(GS->board[GS->move_coordinates[1] - 1 - i][GS->move_coordinates[0] - 1] == 10 ||
                        GS->board[GS->move_coordinates[1] - 1 - i][GS->move_coordinates[0] - 1] == 20 ||
                        GS->board[GS->move_coordinates[1] - 1 - i][GS->move_coordinates[0] - 1] == 30)
                        {
                            if(GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 1 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 2 ||
                               GS->board[GS->move_coordinates[1] - 1][GS->move_coordinates[0] - 1] == 0)
                            {
                                printf("You cannot move to a tile with a penguin on it or on water.\n");
                                valid = 0;
                                break;
                            }
                        }
                        else
                        {   
                            printf("The penguins cannot jump over water or other penguins, please try again.\n");
                            valid = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {   
        printf("Please choose a tile that is at most 3 tiles away from your penguin (horizontally or vertically).\n");
        valid = 0;
    }


    if(valid == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}