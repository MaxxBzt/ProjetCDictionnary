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

/* Function used to check if a substring belongs to a string
* Example : if 'Point' belongs to 'Barre Point', the function returns */
int isSubstringInString(char* string, char *string_to_search)
{
    //strstr returns NULL if substring not in string
    if(strstr(string,string_to_search) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/* Function used to split a string (in n number of substrings) according to a chosen separator */
char** split_a_string(char* string, char separator,int size)
{
    // New list where each element is a sub-list of the string
    char **list = NULL;

    list = malloc( sizeof(char*) * size);
    int idx = 0;
    int len_string = 0;

    // We count the numbers of characters in the string
    while(string[idx] != '\n')
    {
        (len_string)++;
        idx++;
    }

    // We allocate a size to each case of the list
    for (int i=0; i<size;i++) {
        list[i] = malloc(sizeof(char)* (len_string));
    }


    // We count the numbers of separators (in this projet separator is tab) in the string
    int counter_separator = 1;
    idx = 0;
    while(string[idx] != '\n')
    {
        if(string[idx] == separator)
            counter_separator++;
        idx++;
    }

    // We split the string, then store it in the new list
    char * current_col = strtok(string,&separator);
    // Sprintf = allows us to print, then store the print in a variable
    idx = 0;
    for(int i=0; i < counter_separator ; i++)
    {
        sprintf(list[idx],"%s",current_col);
        current_col = strtok(NULL,&separator); // Cuts every time the separator appears
        idx ++;
    }

    return list;
}

/* Function to display the child or next of a node */
void displayNodeChild(p_node node){
    p_node temp=node;
    if (temp->child == NULL && temp->next==NULL){
        printf("node %c ",temp->letter);
        printf("no other child or next in node \n\n");
        return;
    }
    else{
        printf("node %c ",temp->letter);
        if (temp->child != NULL){
            printf("children :\n");
            displayNodeChild(temp->child);
        }
        if (temp->next !=NULL) {
            printf("next letter :\n");
            displayNodeChild(temp->next);
        }
    }
    return;

}

// Function used to find if a letter is in a node. If it does, it returns the p_node where the letter is
p_node findIfLetterInNode(p_node node, char letter){
    p_node temp = NULL;
    if (node->letter == letter){
        return node;
    }
    if (node->next==NULL){
        temp = createNode(letter);
        node->next = temp;
        return temp;
    }
    else{
        return findIfLetterInNode(node->next, letter);
    }
}

// Function used to count the number of nodes who are on the same level of the current node in the tree
int countNumberOfNextOfANode(p_node node)
{
    int count = 0;
    p_node temp = node;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function used to secure an INT Input, in case the user enters a string, when asked for an INT
int secure_input_int()
{
    int option = 1;
    int choice_read = 0;
    choice_read = scanf(" %d", &option);
    while(choice_read != 1)
    {
        printf("Input not a number.\n");
        scanf("%*[^\n]");
        printf("Enter a proper number, which is among the proposed ones.\n>>>");
        choice_read = scanf(" %d", &option);
    }
    return option;
}