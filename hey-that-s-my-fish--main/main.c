#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "io.h"
#include "boardoperations.h"
#include "gamelogic.h"
#include "datamanipulation.h"
#include "autonomous.h"

#define GAMEMODE 1 /* 1 - interactive mode, 2 - automatic mode */

int main(int argc, char *argv[]){
    
    #if GAMEMODE == 1
       menu();

        struct GameState GS;

        dec_board_dims(&GS);
        dec_number_of_penguins_per_player(&GS);
        gen_board(&GS);

        GS.current_player = 1;
        GS.game_phase = 'p';
        GS.score[0] = 0;
        GS.score[1] = 0;

        printf("Beginning of the placement phase. \n");

        while(GS.game_phase == 'p')
        {
            if(penguins_available(&GS) == 1)
            {
                if(penguins_available_curr_player(&GS) == 1)
                {
                    show_board(&GS);
                    
                    printf("It's %d player's turn.\n", GS.current_player);

                    dec_placement(&GS);
                    while(is_placement_valid(&GS) == 0)
                    {
                        dec_placement(&GS);
                    }

                    add_score(&GS);
                    update_board_p(&GS);
                    display_score_curr_player(&GS);

                    reduce_no_of_pen(&GS);
                    change_curr_player(&GS);
                    continue;
                }
                else
                {
                    change_curr_player(&GS);
                    continue;
                }
            }
            else
            {
                GS.game_phase = 'm'; 
                GS.current_player = 1;
                break;
            }
        }

        printf("Beginning of movement phase. \n");

        while(GS.game_phase == 'm')
        {
            if(is_move_available(&GS) == 1)
            {   
                show_board(&GS);

                printf("It's %d player's turn.\n", GS.current_player);

                dec_pen_to_move(&GS);
                while(is_choice_valid(&GS) == 0)
                {
                    dec_pen_to_move(&GS);
                }

                dec_movement(&GS);
                while(is_movement_valid(&GS) == 0)
                {
                    dec_movement(&GS);
                }

                add_score(&GS);
                update_board_m(&GS);
                display_score_curr_player(&GS);
                change_curr_player(&GS);
                continue;
            }
            else
            {
                change_curr_player(&GS);
                if(is_move_available(&GS) == 0)
                {
                    GS.game_phase = 'e';
                    break;
                }
                else
                {
                    continue;
                }
            }
        }

        end_menu(&GS); 
    
    #else
        struct Params Params;

        process_params(&Params, argc, argv);

        if(Params.mode == 'g')
        {
            if(Params.game_phase == 'p')
            {   
                int return_val = 0;

                get_penguin_count(&Params, argv);
                if(get_board(&Params, argv) == 2)
                {
                    return 2;
                }

                is_name_in_file(&Params, argv);
                if(place_penguin(&Params) == 1)
                {
                    return_val = 1;
                }
                write_board(&Params, argv);

                return return_val;
            }
            else if(Params.game_phase == 'm')
            {   
                int return_val = 0;

                if(get_board(&Params, argv) == 2)
                {
                    return 2;
                }
                is_name_in_file(&Params, argv);
                if(make_movement(&Params) == 0)
                {
                    return_val = 1;
                }
                write_board(&Params, argv);

                return return_val;
            }
        }
        else if(Params.mode == 'n')
        {
            display_name(&Params);
        }
    #endif
}
