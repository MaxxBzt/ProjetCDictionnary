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
    p_node test1,test2,test3,test4,test5;
    test1 = createNode('a');
    test2 = createNode('b');
    test3 = createNode('c');
    test4 = createNode('a');
    test5 = createNode('d');

    test1->child = test2;
    test2->next = test3;
    test3->child = test4;
    test4->next = test5;

    displayNodeChild(test1);




    return 0;
}

