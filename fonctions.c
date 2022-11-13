//
// Created by nolwen ngassa on 11/3/22.
//

#include "fonctions.h"
#include <string.h>

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


// Fonction servant à séparer un string par rapport à un délimiteur
char** split_a_string(char* string, char separator, int *len_string)
{
    // New list where each element is a sub-list of the string
    char **list = NULL;
    // 3 because we have 3 categories to store in the previous list (3 columns in the file)
    list = malloc( sizeof(char*) * 3);
    int idx = 0;

    // We count the numbers of characters in the string
    while(string[idx] != '\n')
    {
        (*len_string)++;
        idx++;
    }

    // We allocate a size to each case of the list
    for (int i=0; i<3;i++) {
        list[i] = malloc(sizeof(char)* (*len_string));
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


/* Function which add a string in the tree */
void addToTree(p_dictionarycell temp_line, p_tree word_tree){

    p_flechieslist newFlechiesList, tempFlechiesList;
    p_flechiescell newFlechhieCell, tempFlechieCell;
    p_node temp_node;
    int stop=0;

    temp_node = createNodeInTree(word_tree->root, temp_line->base_word);

    if (temp_node->formes_flechies==NULL){
        // If there is no forme flechies yet, we create the list and assign the first word
        newFlechhieCell = createFlechieCell( temp_line->forme_flechie, temp_line->declinaison );
        newFlechiesList = createFlechiesList( temp_line->base_word, newFlechhieCell );
        temp_node->formes_flechies = newFlechiesList;
    }
    else{
        // If there is already a list of forme flechies
        tempFlechiesList = temp_node->formes_flechies;
        tempFlechieCell = tempFlechiesList->head;
        while ( tempFlechieCell->next != NULL ){
            // We go to the end of the list to add the new flechie word
            if (tempFlechieCell->flechie_word == temp_line->forme_flechie && tempFlechieCell->declinaison == temp_line->declinaison ){
                // If the forme fléchie exists already we don't add it
                stop = 1;
                break;
            }
            tempFlechieCell = tempFlechieCell->next;
        }
        if (stop == 0)
        {
            // If the forme flechie doesn't exist then we add the new one
            newFlechhieCell = createFlechieCell(temp_line->forme_flechie, temp_line->declinaison);
            tempFlechieCell->next = newFlechhieCell;
            tempFlechiesList->number++;
        }

    }
    return;
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

/* Function which initializes every tree (per type) */
void init_trees(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom){
    int undefined;
    //char *types[] = {"Ver","Pre","Adj","Adv","Nom"};


    char line_of_the_dictionary_file[100];
    char **array_of_sub_lines;
    int nb_of_characters_in_a_line = 0 ;
    char *types[] = {"Ver","Adj", "Adv", "Nom"};
    int nbr_of_types = 4;
    p_dictionarycell cell;
    FILE* dictionary_file = fopen("C:\\Users\\nolwen\\Documents\\GitHub\\ProjetCDictionnary\\test.txt", "r");


    while (fgets(line_of_the_dictionary_file, sizeof(line_of_the_dictionary_file), dictionary_file))
    {
        array_of_sub_lines = split_a_string(line_of_the_dictionary_file, '\t', &nb_of_characters_in_a_line);

        cell = createCell_DictionaryList(array_of_sub_lines[0], array_of_sub_lines[1], array_of_sub_lines[2]);

        for(int i = 0; i < nbr_of_types ;i++)
        {
            if(isSubstringInString(array_of_sub_lines[2], types[i]) == 1)
            {
                cell->type = types[i];
                break;
            }
            else{
                cell->type = "/";
            }
        }
        undefined = 1;
        if (strcmp(cell->type,"Ver")==0){
            addToTree(cell,tree_ver);
            tree_ver->type = cell->type;
            //printf("%s\n",cell->base_word);
            undefined = 0;
        }

        if (strcmp(cell->type,"Adj")==0){
            addToTree(cell,tree_adj);
            tree_adj->type = cell->type;
            undefined = 0;
        }
        if (strcmp(cell->type,"Adv")==0){
            addToTree(cell,tree_adv);
            tree_adv->type = cell->type;
            undefined = 0;
        }
        if (strcmp(cell->type,"Nom")==0){
            addToTree(cell,tree_nom);
            tree_nom->type = cell->type;
            undefined = 0;
        }
        free(cell);
        /*
        if (undefined==1){
            printf("%s type of word is not handled by our software \n",cell->type);
        }*/



    }

/*
    while(temp_line != NULL){
        undefined = 1;
        if (strcmp(temp_line->type,"Ver")==0){
            addToTree(temp_line->base_word,tree_ver);
            printf("%s\n",temp_line->base_word);
            undefined = 0;
        }
        /*
        if (strcmp(temp_line->type,"Adj")==0){
            addToTree(temp_line->base_word,tree_adj);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Adv")==0){
            addToTree(temp_line->base_word,tree_adv);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Nom")==0){
            addToTree(temp_line->base_word,tree_nom);
            undefined = 0;
        }
        if (undefined==1){
            printf("%s type of word is not handled by our software \n",temp_line->type);
        }
        temp_line = temp_line->next;
    }*/

}

p_node findIfLetterInList(p_node node,char letter){
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
        return findIfLetterInList(node->next, letter);
    }
}

p_node createNodeInTree(p_node node,char* word){
    int index = 0;
    p_node search = NULL;
    if (node->letter=='0'){
        node->letter = '/';
        node->child = createNode(word[index]);
    }
    search = node->child;

    while (word[index+1]!='\0'){
        if (search->letter == word[index]){
            if (search->child == NULL){
                search->child = createNode(word[index+1]);
                search = search->child;
            }
            else{
                search = search->child;
            }
        }
        else{
            search = findIfLetterInList(search, word[index]);
            if (search->child == NULL){
                search->child = createNode(word[index+1]);
                search = search->child;
            }
            else{
                search = search->child;
            }
        }

        index++;
    }
    return search;
}

/* Function which checks if a word is in a tree */
int isWordInTree(char* word, p_tree tree){

    int idx = 0;
    p_node temp;
    p_node current_parent = tree->root;
    while(word[idx] != '\0')
    {
        temp = current_parent->child;
        // We check if among the letters that temp(letter) can be, we have the letter in word[idx].
        while(word[idx] != temp->letter)
        {
            temp = temp->next;

            /* If temp = Null, that means that none of the letters of the level idx+1 is stored in the tree
            so the word isn't in the tree. */
            if (temp == NULL)
                return 0;
        }
        current_parent = temp;
        idx++;
    }
    // If the current parent foudn doesn't have a list of formes flechies, that means that it isn't a word of the dictionary.
    if(current_parent->formes_flechies == NULL)
        return 0;
    return 1;

}

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

/* Function which checks if a word is in a tree */
char* Extract_random_word_from_tree(p_tree tree)
{

    int idx = 0;
    // We create a list that will contain the letters of the randomly selected word
    char *word = malloc( sizeof(char*));
    int random;
    p_node temp = tree->root;
    int count;
    int b = 1;

    while(b)
    {
        // We go to the first child of the current parent
        temp = temp->child;

        // We count the number of next of the current child
        count = countNumberOfNextOfANode(temp);
        random = rand()%count;


        // After finding which letter will be our next letter, we go store it in temp
        for(int i = 0; i < random; i++)
        {
            temp = temp->next;
        }

        // We increase the size of our list. +1 to remove '/0' and +1 to add a space
        word = realloc(word,strlen(word)+2);

        word[idx] = temp->letter;
        idx++;

        // One chance out of two to stop when we come to a word
        if(temp->formes_flechies != NULL)
            b = rand()%2;
        // peut pas aller plus loin
        if(temp->child == NULL)
            b = 0;
    }
    word = realloc(word,strlen(word)+2);
    word[idx] = '\0';
    return word;

}

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

