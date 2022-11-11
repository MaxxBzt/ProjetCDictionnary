//
// Created by nolwen ngassa on 11/3/22.
//

#include "fonctions.h"
#include <string.h>

/* Fonction servant à déterminer si un sous string fait partie d'un plus grand string
 * Ex : si 'Point' fait partie de 'Barre Point' */
int Search_string_in_string(char* string, char *string_to_search)
{
    // Renvoie NULL si le string à rechercher ne fait pas partie du string
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
    // Nouveau tableau où chaque élement est une sous-liste de la liste (string)
    char **tableau = NULL;
    // 3 puisque nous avons 3 catégories à ranger dans ce tableau (3 colonnes du fichier)
    int nbr = 3;
    tableau = malloc( sizeof(char*) * nbr);
    int idx = 0;

    // On compte le nombre de charactère dans le string
    while(string[idx] != '\n')
    {
        (*len_string)++;
        idx++;
    }

    // allouer une taille à chaque case du tableau
    for (int i=0; i<nbr;i++) {
        tableau[i] = malloc(sizeof(char)* (*len_string));
    }

    // On compte le nombre de separateur (dans le projet TAB) dans le string
    int counter_separator = 1;
    idx = 0;
    while(string[idx] != '\n')
    {
        if(string[idx] == separator)
            counter_separator++;
        idx++;
    }

    // On va splitter le string puis le conserver dans le nouveau tableau
    char * current_col = strtok(string,&separator);
    // Sprintf = print dans une variable. Au lieu de printer, ca store le print dans une variable
    idx = 0;
    for(int i=0; i < counter_separator ; i++)
    {
        sprintf(tableau[idx],"%s",current_col);
        current_col = strtok(NULL,&separator); // Coupe tout le temps pour chaque separeteur
        idx ++;
    }

    return tableau;

}



p_node searchNextNode(p_node start_node, char letter){
    p_node temp_node = start_node;

    if (temp_node->letter == letter){
        return temp_node;
    }
    if (temp_node->next != NULL){
        temp_node = temp_node->next;
        searchNextNode(temp_node, letter);
    }
    else{
        temp_node->next = createNode(letter);
        return temp_node->next;
    }
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


/* Fonction chargée de chercher si un mot se trouve dans un arbre selon la structure du projet */

int isWordInTree(char* word, p_tree tree){

    int idx = 0;
    p_node temp;
    p_node current_parent;
    while(word[idx] != '\0')
    {
        // Si l'index est 0, on compare la première lettre du mot donc on assigne le root
        if(idx == 0)
            temp = tree->root;
        // Si l'index est différent de 0, on s'attaque aux autres lettres du mots, qui sont les child
        else
            temp = current_parent->child;

        // On regarde si parmi les lettres que peut prendre temp(letter), on a la lettre contenue dans word[idx].
        while(word[idx] != temp->letter)
        {
            temp = temp->next;

            /* Si temp = Null, cela veut dire qu'aucune lettre du level idx+1 n'était contenue dans l'arbre donc
            le mot n'est pas dans l'arbre. */
            if (temp == NULL)
                return 0;
        }
        current_parent = temp;
        idx++;
    }
    // Si le current parent trouvé n'a pas de formes flechies, cela veut dire qu'il n'est pas un mot du dictionnaire.
    if(current_parent->formes_flechies == NULL)
        return 0;
    return 1;

}

/* fonction utilisée pour trouver le dernier node a qui il faut créer un enfant pour rajouter la lettre qui suit. */
p_node findIntersection(p_node start_node, char* word, int* index){
    p_node temp_node ;
    temp_node = start_node;

    if ( word[*index] != '\0'){

        temp_node = searchNextNode(temp_node, word[*index]);
        *index = *index + 1;

        if (temp_node->child != NULL){
            temp_node = findIntersection(temp_node->child, word, index);
        }
        else{
            return temp_node;
        }
    }
    return temp_node;
}

void addToTree(p_dictionarycell temp_line, p_tree word_tree){

    p_flechieslist newFlechiesList, tempFlechiesList;
    p_flechiescell newFlechhieCell, tempFlechieCell;
    char* base_word = temp_line->base_word;
    p_node temp_node;
    int idx_char = 0, stop=0;

    if (word_tree->root->letter == '/'){
        word_tree->root->letter = base_word[0];
    }
    /* else {
        searchNextNode(word_tree->root, base_word[0]);
    }*/

    temp_node = findIntersection(word_tree->root, base_word, &idx_char);
    while ( base_word[idx_char] != '\0'){

        temp_node->child = createNode(base_word[idx_char]);
        idx_char++;
        temp_node = temp_node->child;
    }

    if (temp_node->formes_flechies==NULL){
        // If there is no forme flechies yet we create the list and assign the first word
        newFlechhieCell = createFlechieCell(temp_line->forme_flechie,temp_line->declinaison);
        newFlechiesList = createFlechiesList(temp_line->base_word,newFlechhieCell);
        temp_node->formes_flechies = newFlechiesList;
    }
    else{
        // If there is already a list of forme flechies
        tempFlechiesList = temp_node->formes_flechies;
        tempFlechieCell = tempFlechiesList->head;
        while ( tempFlechieCell->next != NULL ){
            // We go to the end of the list to add the new flechie word
            if (tempFlechieCell->flechie_word==temp_line->forme_flechie && tempFlechieCell->declinaison==temp_line->declinaison ){
                // If the forme fléchie exists already we dont add it
                stop=1;
                break;
            }
            tempFlechieCell=tempFlechieCell->next;
        }
        if (stop==0)
        {
            // If the forme flechie doesn't exist then we add the new one
            newFlechhieCell = createFlechieCell(temp_line->forme_flechie, temp_line->declinaison);
            tempFlechieCell->next = newFlechhieCell;
            tempFlechiesList->number++;
        }

    }

}

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

void init_trees(p_tree tree_ver,p_tree tree_pre,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom){
    int undefined;
    //char *types[] = {"Ver","Pre","Adj","Adv","Nom"};


    char line_of_the_dictionary_file[500];
    char **array_of_sub_lines;
    int nb_of_characters_in_a_line = 0 ;
    char *types[] = {"Ver","Pre","Adj","Adv","Nom"};
    int nbr_of_types = 5;
    p_dictionarycell cell;
    FILE* dictionary_file = fopen("C:\\Users\\nolwen\\Documents\\GitHub\\ProjetCDictionnary\\test.txt", "r");


    while (fgets(line_of_the_dictionary_file, sizeof(line_of_the_dictionary_file), dictionary_file))
    {
        array_of_sub_lines = split_a_string(line_of_the_dictionary_file, '\t', &nb_of_characters_in_a_line);

        cell = createCell_DictionaryList(array_of_sub_lines[0], array_of_sub_lines[1], array_of_sub_lines[2]);

        for(int i = 0; i < nbr_of_types ;i++)
        {
            if(Search_string_in_string(array_of_sub_lines[2], types[i]) == 1)
            {
                cell->type = types[i];
                break;
            }
        }
        undefined = 1;
        if (strcmp(cell->type,"Ver")==0){
            addToTree(cell,tree_ver);
            printf("%s\n",cell->base_word);
            undefined = 0;
        }
        /* if (strcmp(temp_line->type,"Pre")==0){
            addToTree(temp_line->base_word,tree_pre);
            undefined = 0;
        }
        if (strcmp(cell->type,"Adj")==0){
            addToTree(cell,tree_adj);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Adv")==0){
            addToTree(temp_line->base_word,tree_adv);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Nom")==0){
            addToTree(temp_line->base_word,tree_nom);
            undefined = 0;
        }*/
        if (undefined==1){
            printf("%s type of word is not handled by our software \n",cell->type);
        }



    }



/*
    while(temp_line != NULL){
        undefined = 1;
        if (strcmp(temp_line->type,"Ver")==0){
            addToTree(temp_line->base_word,tree_ver);
            printf("%s\n",temp_line->base_word);
            undefined = 0;
        }
        /* if (strcmp(temp_line->type,"Pre")==0){
            addToTree(temp_line->base_word,tree_pre);
            undefined = 0;
        }
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


// Fonction servant à découper les lignes du dictionnaire_non_accentue.txt et à conserver les données dans une structure
t_dictionarylist Split_dictionary_in_linked_list()
{

    // ON INITIALIZE DES VARIABLES
    t_dictionarylist dictionary_list;
    p_dictionarycell current_cell;
    char line_of_the_dictionary_file[500];
    char **array_of_sub_lines;
    int nb_of_characters_in_a_line = 0 ;
    int is_it_first_node_of_the_list = 0;
    char *types[] = {"Ver","Pre","Adj","Adv","Nom"};
    int nbr_of_types = 5;


    FILE* dictionary_file = fopen("/Users/max/Library/CloudStorage/OneDrive-Personal/L2/SEM 3/C/ProjetCDictionnary/test.txt", "r");

    // Boucle nous permettant de lire chaque ligne du fichier ci-dessus

    while (fgets(line_of_the_dictionary_file, sizeof(line_of_the_dictionary_file), dictionary_file))
    {
        p_dictionarycell cell;

        array_of_sub_lines = split_a_string(line_of_the_dictionary_file, '\t', &nb_of_characters_in_a_line);

        cell = createCell_DictionaryList(array_of_sub_lines[0], array_of_sub_lines[1], array_of_sub_lines[2]);

        for(int i = 0; i < nbr_of_types ;i++)
        {
            if(Search_string_in_string(array_of_sub_lines[2], types[i]) == 1)
            {
                cell->type = types[i];

                break;
            }
        }

        /*
        // On s'occupe d'abord de ranger la première ligne en tant que Head de la liste
        if (is_it_first_node_of_the_list == 0)
        {
            // On range les informations découpées de la ligne dans une structure
            current_cell = createCell_DictionaryList(array_of_sub_lines[0], array_of_sub_lines[1], array_of_sub_lines[2]);

            // Maintenant nous conservons le type de la ligne (si c'est un verbe etc..) dans la structure
            for(int i = 0; i < nbr_of_types ;i++)
            {
                if(Search_string_in_string(array_of_sub_lines[2], types[i]) == 1)
                {
                    current_cell->type = types[i];
                    break;
                }
            }
            dictionary_list.head = current_cell;
            is_it_first_node_of_the_list++;
        }
        // On s'occupe désormais des autres lignes du fichier
        else
        {
            cell = createCell_DictionaryList(array_of_sub_lines[0], array_of_sub_lines[1], array_of_sub_lines[2]);

            for(int i = 0; i < nbr_of_types ;i++)
            {
                if(Search_string_in_string(array_of_sub_lines[2], types[i]) == 1)
                {
                    cell->type = types[i];

                    break;
                }
            }
            current_cell->next = cell;
            current_cell = cell;
        }
        */


    }



    fclose(dictionary_file);

    return dictionary_list;
}


