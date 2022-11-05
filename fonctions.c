//
// Created by nolwen ngassa on 11/3/22.
//

#include "fonctions.h"
#include <string.h>

// Fonction servant à déterminer si un sous string fait partie d'un plus grand string
// Ex si Point fait partie de Barre Point
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
    // 3 car nous avons 3 catégories à ranger dans ce tableau (3 colonnes du fichiers)
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


    FILE* dictionary_file = fopen("test.txt", "r");

    // Boucle nous permettant de lire chaque ligne du fichier ci-dessus

    while (fgets(line_of_the_dictionary_file, sizeof(line_of_the_dictionary_file), dictionary_file))
    {
        p_dictionarycell cell;

        array_of_sub_lines = split_a_string(line_of_the_dictionary_file, '\t', &nb_of_characters_in_a_line);

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
    }

    fclose(dictionary_file);

    return dictionary_list;
}

t_tree addToTree(t_dictionarylist dico){
    t_tree ver_tree = createTree( '/' ); /* pre_tree, adj_tree, nom_tree, adv_tree; */

    /* variables temporaires */
    p_dictionarycell temp_line = dico.head;
    p_flechieslist newFlechiesList, tempFlechiesList;
    p_flechiescell newFlechhieCell, tempFlechieCell;
    p_node temp_node;
    int idx_char = 0, stop=0;
    char* temp_word = "null";

    /* répéter jusqu'à qu'on arrive sur une ligne vide (fin du dictionnaire) */
    while(temp_line != NULL)
    {
        /* le mot de base de la ligne est-il le même que celui utilisé précédement? */
        /* si non: */
        if (temp_word != temp_line->base_word){

            /* le nouveau mot temporaire est celui de la ligne actuelle */
            temp_word = temp_line->base_word;
            idx_char = 0;
            /* on cherche le bon arbre grace aux types */
            if (temp_line->type == "Ver"){ // Look for the type

                /* l'arbre est-il vide ? */
                if (ver_tree.root->letter == '/'){
                    ver_tree.root->letter = temp_word[idx_char];
                }

                temp_node = findIntersection(ver_tree.root, temp_word, &idx_char);
                while (temp_word[idx_char] != '\0') {
                    temp_node->child = createNode(temp_word[idx_char]);
                    temp_node = temp_node->child;
                    idx_char++;
                }
                /*
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
                    while (tempFlechieCell->next==NULL){
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

                }*/
            }
            printf("1\n");
        }
        temp_line = temp_line->next;
    }
    return ver_tree;
}

/* fonction utilisée pour trouver le dernier node a qui il faut créer un enfant pour rajouter la lettre qui suit. */
p_node findIntersection(p_node start_node, char* word, int* index){

    if (word[*index] != '\0'){
        /* la lettre du node est-elle la meme que celle du mot à l'index donné? */
        /* si oui: */
        if (start_node->letter == word[*index]){
            /* on peut explorer les nodes "enfants" à condition qu'ils ne soient pas vides */
            *index = *index +1;

            if (start_node->child != NULL){
                *index = *index +1;
                findIntersection(start_node->child, word, index);
            }
            else{
                return start_node;
            }
        }

            /* si non: */
        else {
            /* on continue à explorer les nodes au même index */
            if (start_node->next != NULL ){
                findIntersection(start_node->next, word, index);
                *index = *index + 1;
            }
            else{ /* si la lettre n'existe pas à cet index, on le crée */
                if (word[*index] != start_node->letter){
                    start_node->next = createNode(word[*index]);
                }
                start_node = start_node->next;

                return start_node;
            }
        }
    }
    return start_node;
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

void init_trees(p_tree tree_ver,p_tree tree_pre,p_tree tree_adj,p_tree tree_adv,p_tree tree_nom,t_dictionarylist* dico){
    p_dictionarycell temp_line = dico->head;
    int undefined=1;
    //char *types[] = {"Ver","Pre","Adj","Adv","Nom"};
    while(temp_line != NULL){
        undefined = 1;
        if (strcmp(temp_line->type,"Ver")==0){
            addToTree(temp_line,tree_ver);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Pre")==0){
            addToTree(temp_line,tree_pre);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Adj")==0){
            addToTree(temp_line,tree_adj);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Adv")==0){
            addToTree(temp_line,tree_adv);
            undefined = 0;
        }
        if (strcmp(temp_line->type,"Nom")==0){
            addToTree(temp_line,tree_nom);
            undefined = 0;
        }
        if (undefined==1){
            printf("%s type of word is not handled by our software :/",temp_line->type);
        }
        temp_line = temp_line->next;
    }
}




