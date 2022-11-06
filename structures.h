 //
// Created by Maxime Bézot on 02/11/2022.
//

#ifndef PROJETCDICTIONNARY_STRUCTURES_H
#define PROJETCDICTIONNARY_STRUCTURES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct flechies_cell
{
    char* flechie_word;
    char* declinaison;
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

 typedef struct dictionary_cell
 {
     char* forme_flechie;
     char* base_word;
     char* declinaison;
     char* type;
     struct dictionary_cell *next;
 } t_dictionarycell, *p_dictionarycell;

 typedef struct dictionary_list
 {
     p_dictionarycell head;
 } t_dictionarylist;

p_node createNode(char);
p_dictionarycell createCell_DictionaryList(char*, char*, char* );

p_tree createTree(char letter);
p_flechiescell createFlechieCell(char*, char*);
p_flechieslist createFlechiesList(char *, p_flechiescell);


#endif //PROJETCDICTIONNARY_STRUCTURES_H
