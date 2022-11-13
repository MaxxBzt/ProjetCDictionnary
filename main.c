//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"
#include "fonctions.h"
#include "menus.h"


int main()
{
    p_tree verbe_arbre = createTree('0');
    p_tree adj_arbre = createTree('0');
    p_tree adv_arbre = createTree('0');
    p_tree nom_arbre = createTree('0');
    init_trees(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);
    srand(time(NULL));
    starter_menu(verbe_arbre, adj_arbre, adv_arbre, nom_arbre);

    /*
    p_node test;
    test = createNode('a');
    printf("%c",test->letter);*/

    /*t_dictionarylist dictionary_list;
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
    }*/


    /*
    // Series of test for the display tree function

    p_tree tree_ver = createTree('/');

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




    init_trees(tree_ver, NULL, NULL, NULL, NULL);

    displayNodeChild(tree_ver->root);

    // Search word in tree_ver
    char word[20] = "avoir";
    int test = isWordInTree(word, tree_ver);
    printf("is word in tree verbe: %d\n",test);*/

    return 0;
}

