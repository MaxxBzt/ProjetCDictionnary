//
// Created by Maxime Bézot on 02/11/2022.
//

#include "structures.h"


/* Function to create a cell in the list of the dictionary file according to the structure dictionary_cell*/

p_dictionarycell createCell_DictionaryList(char *forme_flechie, char *base_word, char *declinaison)
{
    p_dictionarycell cell = (t_dictionarycell*)malloc(sizeof(t_dictionarycell));
    cell->forme_flechie = forme_flechie;
    cell->base_word = base_word;
    cell->declinaison = declinaison;
    cell->next = NULL;
    return cell;

}

/* Function to create the tree according to the structure s_tree */

p_tree createTree(char letter){
    p_tree new_tree;
    new_tree = (p_tree) malloc(sizeof(t_tree));
    new_tree->root = createNode(letter);
    return new_tree;
}

/* Function to create a node of a tree according to the structure s_node*/

p_node createNode(char letter){
    p_node node = malloc(sizeof(t_node));
    node->letter = letter;
    node->child = NULL;
    node->next = NULL;
    node->formes_flechies = NULL;
    return node;
}
/* Function to create the list of formes fléchies stored in a node according to the structure flechieslist */

p_flechieslist createFlechiesList(char * base_word, p_flechiescell head){
    p_flechieslist new;
    new = (p_flechieslist) malloc(sizeof (t_flechieslist));
    new->base_word = base_word;
    new->head = head;
    new->number = 1;

    return new;
}

/* Function to create the cell of a formes fléchies according to the structure flechies_cell */

p_flechiescell createFlechieCell(char* flechie, char* declinaison){
    p_flechiescell new;
    new = (p_flechiescell)malloc(sizeof(t_flechiescell));
    new->flechie_word = flechie;
    new->declinaison = declinaison;
    new->next = NULL;

    return new;
}

void addFlechieCell(p_flechieslist list, p_flechiescell cell){
    p_flechiescell temp = list->head;
    while(temp->next != NULL){
        if ( temp->flechie_word == cell->flechie_word && temp->declinaison == cell->declinaison){
            printf("This flechie_word already exists in the list");
            return;
        }
        temp = temp->next;
    }
    temp->next = cell;
    list->number++;
}

/* Function to create the cell of a formes fléchies according to the structure flechies_cell */

p_flechiesearch createFlechieSearch(char* base_word, char* flechie, char* declinaison){
    p_flechiesearch new;
    new = (p_flechiesearch)malloc(sizeof(t_flechiesearch));
    new->flechie_word = flechie;
    new->declinaison = declinaison;
    new->base_word = base_word;

    return new;
}

void displayFlechieList(p_flechieslist list){
    p_flechiescell temp = list->head;
    printf("Base word : %s\nNumber of flechies forms : %d\n ", list->base_word,list->number);
    while(temp != NULL){
        printf("Word Flechie : %s || Declinaison : %s\n", temp->flechie_word, temp->declinaison);
        temp = temp->next;
    }
}
