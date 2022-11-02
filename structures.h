//
// Created by Maxime Bézot on 02/11/2022.
//

#ifndef PROJETCDICTIONNARY_STRUCTURES_H
#define PROJETCDICTIONNARY_STRUCTURES_H

#include <stdlib.h>

typedef struct flechies_cell
{
    char* flechie_word;
    char* type;
    struct flechies_cell *next;
} t_flechiescell, *p_flechiescell;

typedef struct flechieslist
{
    int number;
    char* base_word;
    p_flechiescell head;
} t_flechieslist, *p_flechieslist;

typedef struct s_node
{
    char letter;
    p_flechieslist formes_flechies ;
    struct s_node *child, *next;
}t_node, *p_node;

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

p_node createNode(char);


#endif //PROJETCDICTIONNARY_STRUCTURES_H
