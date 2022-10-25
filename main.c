//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>

int main(){

    // STRUCTURES DU COURS, a changer les noms pour adapter à nos structures
    struct s_cell
    {
        char *nom;
        char *f_flechie;
        struct s_cell *next;

    };
    typedef struct s_cell t_cell, *p_cell;

    typedef struct s_std_list

    {
        p_cell head;
    } t_std_list;

    return 0;
}