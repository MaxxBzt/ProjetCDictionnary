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


    FILE* dictionary_file = fopen("/Users/max/Library/CloudStorage/OneDrive-Personal/L2/SEM 3/C/ProjetCDictionnary/test.txt", "r");

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

t_tree dicoFillLetters(t_dictionarylist dico){
    t_tree ver_tree, pre_tree, adj_tree, nom_tree, adv_tree;

    /* variables temporaires */
    p_dictionarycell temp_line = dico.head;
    p_node temp_node;
    int idx_char = 0;
    char* temp_word;

    /* répéter jusqu'à qu'on arrive sur une ligne vide (fin du dictionnaire) */
    while(temp_line != NULL)
    {
        /* le mot de base de la ligne est-il le même que celui utilisé précédement? */
        /* si non: */
        if (temp_word != temp_line->base_word){

            /* le nouveau mot temporaire est celui de la ligne actuelle */
            temp_word = temp_line->base_word;

            /* on cherche le bon arbre grace aux types */
            if (temp_line->type == 'Ver'){

                /* l'arbre est-il vide ? */
                if (ver_tree.root == NULL){
                    ver_tree = createTree( temp_word[idx_char] );
                    idx_char++;
                }

                temp_node = findIntersection(ver_tree.root, temp_word, &idx_char);
                while (temp_word[idx_char] != '\0') {
                    temp_node->child = createNode(temp_word[idx_char]);
                    idx_char++;
                }

                /* insert ici la fonction ajouter aux formes fléchies */
            }

        }
        temp_line = temp_line->next;
    }
}

/* fonction utilisée pour trouver le dernier node a qui il faut créer un enfant pour rajouter la lettre qui suit. */
p_node findIntersection(p_node start_node, char* word, int* index){

    /* la lettre du node est-elle la meme que celle du mot à l'index donné? */
    /* si oui: */
    if (start_node->letter == word[*index]){

        /* on peut explorer les nodes "enfants" à condition qu'ils ne soient pas vides */
        if (start_node->child != NULL){
            *index = *index +1;
            findIntersection(start_node->child, word, *index);
        }
        else{
            return start_node;
        }
    }

    /* si non: */
    else {

        /* on continue à explorer les nodes au même index */
        if (start_node->next != NULL){
            findIntersection(start_node->next, word, *index);
        }
        else{ /* si la lettre n'existe pas à cet index, on le crée */
            if (word[*index] != start_node->letter){
                start_node->next = createNode(word[*index]);
            }
            *index = *index+1;
            start_node = start_node->next;

            return start_node;
        }
    }
}

void displayNodeChild(p_node node){
    p_node temp=node;
    printf("%c",temp->letter);
    if (temp->child == NULL && temp->next==NULL){
        return;
    }
    else{
        if (temp->child != NULL){
            printf("\ngoing in the children\n");
            displayNodeChild(temp->child);
        }
        if (temp->next !=NULL) {
            printf("\ngoing to the next letter\n");
            displayNodeChild(temp->next);
        }
    }
    return;

}
