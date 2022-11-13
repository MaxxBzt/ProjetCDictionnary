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

    p_tree verbe_arbre = createTree('0');
    p_tree adj_arbre = createTree('0');
    p_tree adv_arbre = createTree('0');
    p_tree pre_arbre = createTree('0');
    p_tree nom_arbre = createTree('0');

    /*
    p_node un = createNode('a');
    p_node deux = createNode('b');
    p_node trois = createNode('c');
    p_node quatre = createNode('d');

    un->next = deux;
    deux->next = trois;
    trois->next = quatre;
    p_node cinq ;


    printf("%c\n", cinq->letter);
    printf("%c\n", quatre->next->letter);
     */

    /*
    p_node root = createNode('/');

    createNodeInTree(root,"avoir");
    createNodeInTree(root,"avoire");
    createNodeInTree(root,"avortement");
    createNodeInTree(root,"battre");

     */


    init_trees(verbe_arbre, pre_arbre, adj_arbre, adv_arbre, nom_arbre);



    /*

    // Search word in verbe_arbre
    char word[20] = "abaisser";
    int test = isWordInTree(word, verbe_arbre);
    printf("is word in tree verbe: %d\n",test);
     */



    return 0;
}

