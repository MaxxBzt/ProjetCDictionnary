//
// Created by nolwen on 11/20/2022.
//

#include "handleTrees.h"


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


/* Function which initializes every tree (per type) */
void init_trees(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants){
    char line_of_the_dictionary_file[150];
    char **array_of_sub_lines;
    char *types[] = {"Ver","Adj", "Adv", "Nom","Det"};
    int nbr_of_types = 5;
    p_dictionarycell cell;
    FILE* dictionary_file = fopen("C:\\Users\\nolwen\\Documents\\GitHub\\ProjetCDictionnary\\dictionnaire_non_accentue.txt", "r");

    while (fgets(line_of_the_dictionary_file, sizeof(line_of_the_dictionary_file), dictionary_file))
    {
        array_of_sub_lines = split_a_string(line_of_the_dictionary_file, '\t',3);

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
        if (strcmp(cell->type,"Ver")==0){
            addToTree(cell,tree_ver);
            tree_ver->type = cell->type;
        }

        if (strcmp(cell->type,"Adj")==0){
            addToTree(cell,tree_adj);
            tree_adj->type = cell->type;
        }
        if (strcmp(cell->type,"Adv")==0){
            addToTree(cell,tree_adv);
            tree_adv->type = cell->type;
        }
        if (strcmp(cell->type,"Nom")==0){
            addToTree(cell,tree_nom);
            tree_nom->type = cell->type;
        }
        if (strcmp(cell->type,"Det")==0){
            addToTree(cell,determinants);
            tree_nom->type = cell->type;
        }
        free(cell);


    }
}


// Function used to be able to create a node, inside the tree
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
            search = findIfLetterInNode(search, word[index]);
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
    search = findIfLetterInNode(search, word[index]);
    return search;
}

void ask_to_add_flechie_word(p_tree tree,char* word,p_node node){
    int choice;

    printf("Do you want to add a flechie form to '%s'\n"
           "1. Enter 1 for yes\n"
           "2. Enter 2 for no \n>>>",word);
    choice = secure_input_int();
    if (choice==2){
        return;
    }
    else{
        char* flechies_form = malloc(sizeof(char)*15);
        char* declinaison = malloc(sizeof(char)*15);
        printf("Enter the flechie form of '%s'\n>>>",word);
        scanf("%s",flechies_form);
        printf("Enter the declinaison of '%s'\n>>>",flechies_form);
        scanf("%s",declinaison);



        p_flechiescell temp_flechie = createFlechieCell(flechies_form,declinaison);
        p_flechiescell tempcell = node->formes_flechies->head;


        while(tempcell->next != NULL){
            if ( tempcell->flechie_word == flechies_form && tempcell->declinaison == declinaison){
                printf("This flechie_word already exists in the list\n.");
                return;
            }
            tempcell = tempcell->next;
        }
        tempcell->next = temp_flechie;


        node->formes_flechies->number++;
    }

}


// Function used to display all the flechies words of a word
void displayFlechieList(p_flechieslist list){
    p_flechiescell temp = list->head;
    int choice;
    printf("Base word : '%s' || Number of flechies forms : %d\n\n ", list->base_word,list->number);
    printf("Do you want to display every flechies form of the word '%s' ?\n"
           "1. Enter 1 for yes\n"
           "2. Enter 2 for no \n>>>",list->base_word);
    choice = secure_input_int();
    if(choice == 1)
    {
        printf("List of all flechies forms :\n ");
        while(temp != NULL){
            printf("    Word Flechie : %s || Declinaison : %s\n", temp->flechie_word, temp->declinaison);
            sleep(1);
            temp = temp->next;
        }
    }
    else
    {
        return;
    }
}

// ---------- FUNCTIONS USED WHEN SEARCHING A WORD IN A TREE --------

p_node isWordInTree(char* word, p_tree tree){

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
                return NULL;
        }
        current_parent = temp;
        idx++;
    }
    // If the current parent foudn doesn't have a list of formes flechies, that means that it isn't a word of the dictionary.
    if(current_parent->formes_flechies == NULL)
        return NULL;
    return current_parent;

}


/* Function used to extract a random word from a giving trees */
char* Extract_random_base_word_from_tree(p_tree tree)
{

    int idx = 0;
    // We create a list that will contain the letters of the randomly selected word
    char *word = malloc( sizeof(char*));
    int random;
    p_node temp = tree->root->child;
    int count;
    int areWeInFirstLevelOfTree = 1;
    /* B is going to be the variable which will get us out or not of our loop. If B=1, we stay in the loop.
     * B will be equal to 0 according to a probability of 1/2. If we found a word in the tree, there is a one out of 2
     * chances that the program will select it as our extracted word. When it does, b becomes 0 and break us out the loop*/
    int b = 1;

    while(b)
    {

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

        // The 'if' happens only when we are not in the first level of the tree (first letter of words)
        if(areWeInFirstLevelOfTree != 1)
        {
            // One chance out of two to stop when we come to a word
            if(temp->formes_flechies != NULL)
                b = rand()%2;
        }

        // If temp->chilld is NULL, we can't go farther because there is no child so b becomes 0 and breaks out of the loop.
        if(temp->child == NULL)
            b = 0;

        // We go to the first child of the current parent
        temp = temp->child;
        areWeInFirstLevelOfTree++;
    }
    word = realloc(word,strlen(word)+2);
    word[idx] = '\0';
    return word;
}

// Function usedd to search a random flechies word in the tree, according to a chosen base form
p_flechiescell randomFlechiesWord(char* word, p_tree tree){
    p_node temp = isWordInTree(word,tree);
    if (temp->formes_flechies==NULL){
        return NULL;
    }
    p_flechieslist list = temp->formes_flechies;
    p_flechiescell cell = list->head;
    int count = list->number;
    int random = rand()%count;
    for(int i = 0; i < random; i++)
    {
        cell = cell->next;
    }
    return cell;
}

// Function used to search if a node has a formes flechies or not.
p_flechiesearch searchFormeFlechie(p_node node, char* word)
{
    if(node->formes_flechies == NULL){
        // if there is no form flechies we return NULL -> not a word
        return NULL;
    }
    p_flechieslist tempList=node->formes_flechies;
    p_flechiescell tempCell=tempList->head;
    while (tempCell!=NULL)
    {
        if (strcmp(tempCell->flechie_word,word)==0){
            //we check if we find the flechie word
            p_flechiesearch result = createFlechieSearch(tempList->base_word,tempCell->flechie_word,tempCell->declinaison);
            printf("The word : '%s' is in the tree.\nIts base form is '%s' and its declinaison is '%s'\n",result->flechie_word,result->base_word,result->declinaison);
            return result;
        }
        tempCell=tempCell->next;
    }
}

/* We are at a node, we check if it has a child, next and form flechies. if not, then current node doesn't form word*/
p_flechiesearch searchBaseWord(p_node node, char* word)
{
    p_node temp = node;

    if ( (temp->child==NULL) && (temp->next==NULL) && (node->formes_flechies==NULL))
    {
        return NULL;
    }
    if (temp->next!=NULL)
    {
        searchBaseWord(temp->next,word);
    }
    if (temp->child!=NULL)
    {
        searchBaseWord(temp->child,word);
    }
    return searchFormeFlechie(temp,word);
}
