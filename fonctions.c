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
        current_col = strtok(NULL,&separator);
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


