#include <stdio.h>
#include "checks.h"

int is_positive(int a){

    if(a <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int is_last_player(int a, int b){

    if(a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_placement_valid_x(int a, int b){
    return 0;
}

int is_placement_valid_y(int a, int b){
    return 0;
}