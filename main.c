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
    t_tree vb_tree = createTree('a');
    printf("%c\n\n\n",vb_tree.root->letter);

    // Series of test for the display tree function

    p_node test1,test2,test3,test4,test5, tpouet;
    t_tree pouet = addToTree(dictionary_list);
    displayNodeChild(pouet.root);


    return 0;
}

