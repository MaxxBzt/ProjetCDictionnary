//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"
#include "fonctions.h"

int main()
{
    /*
    p_node test;
    test = createNode('a');
    printf("%c",test->letter);*/

    /*

    t_dictionarylist dictionary_list;
    dictionary_list = Split_dictionary_in_linked_list();
    p_dictionarycell temp = dictionary_list.head;
    if(temp == NULL)
    {
        printf("list empty");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%s %s %s %s",temp->type,temp->forme_flechie,temp->base_word,temp->declinaison);
            temp = temp->next;
        }
    }
    */

    // Series of test for the display tree function

    p_tree pouet = createTree('/');

    p_node un = createNode('a');
    p_node deux = createNode('b');
    p_node trois = createNode('c');
    p_node quatre = createNode('d');

    un->next = deux;
    deux->next = trois;
    trois->next = quatre;

    /*
    if (findIfLetterInList(un,'d')!=NULL){
        printf("%c\n",findIfLetterInList(un,'d')->letter);
    }
     */


    init_trees(pouet, NULL, NULL, NULL, NULL);

    displayNodeChild(pouet->root);

    return 0;
}

