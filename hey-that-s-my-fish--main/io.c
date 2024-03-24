#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"

void menu(){

    printf("Penguins Game. \n");
    printf("   __\n");
    printf("-=(o '.\n");
    printf("   '.-.\\\n");
    printf("   /|  \\\n");
    printf("   '|  ||\n");
    printf("    _\\_):,_    (c)GroupF\n");
}

void show_board(struct GameState *GS){
    
    printf("Current state of the board: \n");

    printf(" XX");   
    for(int i = 0; i < GS->boardX; i++)
    {
        if(i < 9)
        {
           printf(" 0%d", i + 1);  
        }
        else
        {
            printf(" %d", i + 1);
        }
    }
    printf("\n");
    for(int i = 0; i < GS->boardY; i++)
    {
        if(i < 9)
        {
           printf(" 0%d", i + 1);  
        }
        else
        {
            printf(" %d", i + 1);
        }
        for(int j = 0; j < GS->boardX; j++)
        {
            if(GS->board[i][j] == 0)
            {
                printf(" ~~");
            } 
            else if (GS->board[i][j] == 10)
            {
                printf(" #1");
            }
            else if(GS->board[i][j] == 20)
            {
                printf(" #2");
            }
            else if(GS->board[i][j] == 30)
            {
                printf(" #3");
            }
            else if(GS->board[i][j] == 1)
            {
                printf(" P1");
            }
            else if(GS->board[i][j] == 2)
            {
                printf(" P2");
            }
        }
        printf("\n");
    }
}

void display_score_curr_player(struct GameState *GS){
    printf("Player's %d score is: %d.\n", GS->current_player, GS->score[GS->current_player - 1]);
}

void end_menu(struct GameState *GS){

    printf("\nThe game has ended. \n\n");

    show_board(GS);
    if(GS->score[0] == GS->score[1])
    {
        printf("It's a draw!\n");
    }
    else if(GS->score[0] > GS->score[1])
    {
        printf("Player 1 won!\n");
    }
    else
    {
        printf("Player 2 won!\n");
    }

    printf("\nPress any key to exit.\n");
    char c;
    scanf("%c", &c);
    switch(c)
    {
        default:
            exit(-1);
    }
}

void dec_board_dims(struct GameState *GS){

    int temp_x, temp_y;

    printf("Please input the width of the board: \n");
    scanf("%d", &temp_x);

    while(temp_x <= 0)
    {
        printf("Please input a number bigger than 0. \n");
        scanf("%d", &temp_x);
    }

    printf("Please input the height of the board: \n");
    scanf("%d", &temp_y);

    while(temp_y <= 0)
    {
        printf("Please input a number bigger than 0. \n");
        scanf("%d", &temp_y);
    }

    GS -> boardX = temp_x;
    GS -> boardY = temp_y;
}

void dec_number_of_penguins_per_player(struct GameState *GS){

    int temp_num;

    printf("Please state the number of penguins per player: \n");
    scanf("%d", &temp_num);

    while(temp_num <= 0)
    {
        printf("Please input a positive number.\n");
        scanf("%d", &temp_num);
    }

    for(int i = 0; i < 2; i++)
    {
        GS->penguins_left_to_place[i] = temp_num;
    }
}

void dec_placement(struct GameState *GS){

    printf("Please input the X coordinate of tile You want to place Your penguin in. \n");
    scanf("%d", &(GS->move_coordinates[0]));
    while(GS->move_coordinates[0] <= 0 || GS->move_coordinates[0] > GS->boardX)
    {
        printf("Please input a number that greater than zero but smaller than the width of the board. \n");
        scanf("%d", &(GS->move_coordinates[0]));
    }

    printf("Please input the Y coordinate of tile You want to place Your penguin in. \n");
    scanf("%d", &(GS->move_coordinates[1]));
    while(GS->move_coordinates[1] <= 0 || GS->move_coordinates[1] > GS->boardY)
    {
        printf("Please input a number that is greater than zero but smaller than the height of the board. \n");
        scanf("%d", &(GS->move_coordinates[1]));
    }
}

void dec_pen_to_move(struct GameState *GS){

    printf("Please input the coordinates of the penguin You want to move: \n");
    printf ("X: ");
    scanf("%d", &(GS->penguin_coordinates[0]));
    while(GS->penguin_coordinates[0] <= 0 || GS->penguin_coordinates[0] > GS->boardX)
    {
        printf("Please input a number greater than zero and smaller than the width of the board.\n");
        scanf("%d", &(GS->penguin_coordinates[0]));
    }
    printf("Y: ");
    scanf("%d", &(GS->penguin_coordinates[1]));
    while(GS->penguin_coordinates[1] <= 0 || GS->penguin_coordinates[1] > GS->boardY)
    {
        printf("Please input a number greater than zero and smaller than the height of the board.\n");
        scanf("%d", &(GS->penguin_coordinates[1]));
    }
}

void dec_movement(struct GameState *GS){

    printf("Please input the X coordinate of tile You want to move Your penguin to. \n");
    scanf("%d", &(GS->move_coordinates[0]));
    while(GS->move_coordinates[0] <= 0 || GS->move_coordinates[0] > GS->boardX)
    {
        printf("Please input a number that greater than zero but smaller than the width of the board. \n");
        scanf("%d", &(GS->move_coordinates[0]));
    }

    printf("Please input the Y coordinate of tile You want to place Your penguin in. \n");
    scanf("%d", &(GS->move_coordinates[1]));
    while(GS->move_coordinates[1] <= 0 || GS->move_coordinates[1] > GS->boardY)
    {
        printf("Please input a number that is greater than zero but smaller than the height of the board. \n");
        scanf("%d", &(GS->move_coordinates[1]));
    }
}
