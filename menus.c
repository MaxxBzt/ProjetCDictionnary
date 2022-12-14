//
// Created by nolwen on 11/11/2022.
//

#include "menus.h"

void starter_menu(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants){
    printf("-------------------------------------------------\n");
    printf("-                 MENU                          -\n");
    printf("-------------------------------------------------\n");

    printf("- Enter 1 to search if a word is in a tree      -\n");
    printf("- Enter 2 to obtain a random word from a tree   -\n");
    printf("- Enter 3 to generate random sentences          -\n");
    printf("- Enter 0 to exit the program                   -\n");
    printf("-------------------------------------------------\n");

    printf(">>");

    int option;
    option = secure_input_int();
    switch(option){
        case 0:
        {
            break; // EXIT THE PROGRAM
        }
        case 1:
        {
            FirstChoice_Submenu_One(tree_ver,tree_adj,tree_adv,tree_nom,determinants); //Search if a word is in a tree
        }
        case 2:
        {
            SecondChoice_Submenu_One(tree_ver,tree_adj,tree_adv,tree_nom,determinants); //Extract a random word from a tree
        }
        case 3:
        {
            ThirdChoice_Submenu_One(tree_ver,tree_adj,tree_adv,tree_nom,determinants); //generate random sentences
        }
        default:
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
    }
}

void FirstChoice_Submenu_One(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants)
{
    /*

     */
    int submenu_choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("What is the type of your word?\n"
           "ATTENTION: If you don't know the type of your word, please look it up on the internet.\n"
           "1. Enter 1 for verbs\n"
           "2. Enter 2 for adjectives\n"
           "3. Enter 3 for adverbs\n"
           "4. Enter 4 for nouns\n"
           "5. Enter 5 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    submenu_choice = secure_input_int();

    switch (submenu_choice)
    {
        case 1 :
        { // We search the word in tree of verbs

            FirstChoice_Submenu_Two(tree_ver,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 2:
        { // We search the word in tree of adjectives
            FirstChoice_Submenu_Two(tree_adj,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 3:
        { // We search the word in tree of adverbs
            FirstChoice_Submenu_Two(tree_adv,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 4 :
        { // We search the word in tree of nouns
            FirstChoice_Submenu_Two(tree_nom,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 5 :
        { // to go back to the starter menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default :
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }

    }
}

void FirstChoice_Submenu_Two(p_tree current_tree,p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants){
    /*
     * The function will make the program search if the word entered by the user in the current tree
     */
    int choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("Do you want to search the word according to its forme de base or forme flechie?\n"
           "1. Enter 1 for formes de bases\n"
           "2. Enter 2 for formes flechies\n"
           "3. Enter 3 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    choice = secure_input_int();

    char mot[30];
    p_node isWordIntree;
    switch(choice)
    {
        case 1:
        { //formes de bases
            printf("What is your word?\n");
            scanf("%s",mot);
            isWordIntree = isWordInTree(mot,current_tree);
            if (isWordIntree != NULL){
                printf("The word : '%s' is in the tree of type : '%s'\n\n",mot,current_tree->type);
                ask_to_add_flechie_word(current_tree,mot,isWordIntree);
                sleep(1);
                displayFlechieList(isWordIntree->formes_flechies);
                }
            else
                printf("The word : '%s' is not in the tree of type : '%s'\n",mot,current_tree->type);
            break;
        }
        case 2 :
        { // formes fl??chies
            printf("What is your word?\n");
            scanf("%s",mot);
            printf("If the output is empty then the word is not in the tree:\n");
            searchBaseWord(current_tree->root,mot);
            break;
        }
        case 3:
        { // going back to menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default:
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
    }
}

void SecondChoice_Submenu_One(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants)
{
    /*

     */
    int submenu_choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("What is the type of your word?\n"
           "ATTENTION: If you don't know the type of your word, please look it up on the internet.\n"
           "1. Enter 1 for verbs\n"
           "2. Enter 2 for adjectives\n"
           "3. Enter 3 for adverbs\n"
           "4. Enter 4 for nouns\n"
           "5. Enter 5 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    submenu_choice = secure_input_int();

    switch (submenu_choice)
    {
        case 1 :
        { // We search a random word in the tree of verbs
            SecondChoice_Submenu_Two(tree_ver,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 2:
        { // We search a random word in the tree of adjectives
            SecondChoice_Submenu_Two(tree_adj,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 3:
        { // We search a random word in the tree of adverbs
            SecondChoice_Submenu_Two(tree_adv,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 4 :
        { // We search a random word in the tree of verbs nouns
            SecondChoice_Submenu_Two(tree_nom,tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 5 :
        { // go back to the starter menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default :
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }

    }
}

void SecondChoice_Submenu_Two(p_tree current_tree,p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants){
    /*
     *
     */
    int choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("Do you want to generate a random word according to its forme de base or forme flechie?\n"
           "1. Enter 1 for formes de bases\n"
           "2. Enter 2 for formes flechies\n"
           "3. Enter 3 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    choice = secure_input_int();

    char *random_word;
    switch(choice)
    {
        case 1:
        { //formes de bases
            random_word = Extract_random_base_word_from_tree(current_tree);
            printf("The randomly selected word is '%s'. Its type is : '%s'\n",random_word,current_tree->type);

            break;
        }
        case 2 :
        { // formes fl??chies
            random_word = Extract_random_base_word_from_tree(current_tree);
            p_flechiescell temp_cell = randomFlechiesWord(random_word,current_tree);
            printf("The randomly selected flechie word is '%s'. Its declinaison is : %s\n",temp_cell->flechie_word,temp_cell->declinaison);
            break;
        }
        case 3:
        { // going back to menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default:
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
    }
}


void ThirdChoice_Submenu_One(p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants){
    /*
     *
     */
    int choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("Do you want to generate sentences of words based on their forme de base or forme flechie?\n"
           "1. Enter 1 for formes de bases\n"
           "2. Enter 2 for formes flechies\n"
           "3. Enter 3 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    choice = secure_input_int();

    switch(choice)
    {
        case 1:
        { //formes de bases
            // A VOIR
            ThirdChoice_Submenu_Two('b',tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            break;
        }
        case 2 :
        { // formes fl??chies
            // A VOIR
            ThirdChoice_Submenu_Two('f',tree_ver,tree_adj,tree_adv,tree_nom,determinants);
            break;
        }
        case 3:
        { // going back to menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default:
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
    }
}

void ThirdChoice_Submenu_Two(char type,p_tree tree_ver,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,p_tree determinants)
{
    char ** phrase_baseword;
    char **phrase_flechie;
    int submenu_choice;
    printf("---------------------------------------------------------------------------------------\n");
    printf("From which model do you want the sentences to be generated ?\n"
           "1. Enter 1 for the model : noun : adjective : verb : noun\n"
           "2. Enter 2 for the model : noun : qui : verb : verb : noun : adjective\n"
           "3. Enter 3 for the model : noun : adjective : verb : adverb\n"
           "4. Enter 4 to go back to the starter menu\n");
    printf("---------------------------------------------------------------------------------------\n>>>");
    submenu_choice = secure_input_int();

    phrase_baseword = generateurPhraseBase(tree_ver, tree_nom, tree_adj, tree_adv, submenu_choice);
    phrase_flechie = generateurPhraseFlechie(tree_ver, tree_nom, tree_adj, tree_adv, determinants,submenu_choice);

    printf("Your random generated sentence is :\n");

    switch (submenu_choice)
    {
        case 1 :
        { // MODELE 1
            if(type == 'f')// Model with formes flechies
            {
                printf("%s %s %s %s %s %s\n\n", phrase_flechie[0], phrase_flechie[1],
                       phrase_flechie[2],phrase_flechie[3],phrase_flechie[4],phrase_flechie[5]);
            }
            else // Model with formes de bases
            {
                printf("%s %s %s %s\n\n", phrase_baseword[0], phrase_baseword[1],phrase_baseword[2],phrase_baseword[3]);
            }
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 2:
        { // MODELE 2
            if(type == 'f')// Model with formes flechies
            {
                printf("%s %s %s %s %s %s %s %s\n\n", phrase_flechie[0], phrase_flechie[1],
                       phrase_flechie[2],phrase_flechie[3],phrase_flechie[4],phrase_flechie[5],phrase_flechie[6],phrase_flechie[7]);
            }
            else // Model with formes de bases
            {
                printf("%s %s %s %s %s %s\n\n", phrase_baseword[0], phrase_baseword[1],phrase_baseword[2],phrase_baseword[3],phrase_baseword[4],phrase_baseword[5]);
            }
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 3:
        { // MODELE 3
            if(type == 'f')// Model with formes flechies
            {
                printf("%s %s %s %s %s\n\n", phrase_flechie[0], phrase_flechie[1],
                       phrase_flechie[2],phrase_flechie[3],phrase_flechie[4]);
            }
            else // Model with formes de bases
            {
                printf("%s %s %s %s\n\n", phrase_baseword[0], phrase_baseword[1],phrase_baseword[2],phrase_baseword[3]);
            }
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        case 4 :
        { // go back to the starter menu
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
        default :
        {
            printf("The selected choice is not proposed.\n");
            starter_menu(tree_ver,tree_adj,tree_adv,tree_nom,determinants);
        }
    }
    free(phrase_baseword);
}