//
// Created by nolwen on 11/20/2022.
//


#include "handleSentences.h"


/* Function used to generate sentences from the base forms of a word, according to the model chosen by
 * our team */

char** generateurPhraseBase(p_tree ver_tree, p_tree nom_tree, p_tree adj_tree, p_tree adv_tree, int modele){
    char** phrase = NULL;
    int size;

    // We allocate the list which will contain the sentences
    if(modele == 1  || modele == 3)
    {
        phrase = malloc( sizeof(char*) * 4);
        size = 4;
    }
    else
    {
        phrase = malloc( sizeof(char*) * 6);
        size = 6;
    }

    // We allocate a size to each case of the list
    for (int i=0; i<size;i++) {
        phrase[i] = malloc(sizeof(char)* 20);
    }

    switch (modele)
    {
        case 1:
        {
            //noun : adjective : verb : noun
            phrase[0] = Extract_random_base_word_from_tree(nom_tree);
            phrase[1] = Extract_random_base_word_from_tree(adj_tree);
            phrase[2] = Extract_random_base_word_from_tree(ver_tree);
            phrase[3] = Extract_random_base_word_from_tree(nom_tree);
            break;
        }
        case 2:
        {
            // noun : qui : verb : verb : noun : adjective
            phrase[0] = Extract_random_base_word_from_tree(nom_tree);
            phrase[1] = "qui";
            phrase[2] = Extract_random_base_word_from_tree(ver_tree);
            phrase[3] = Extract_random_base_word_from_tree(ver_tree);
            phrase[4] = Extract_random_base_word_from_tree(nom_tree);
            phrase[5] = Extract_random_base_word_from_tree(adj_tree);
            break;
        }
        case 3:
        {
            // // noun : adjective : verb : adverbe
            phrase[0] = Extract_random_base_word_from_tree(nom_tree);
            phrase[1] = Extract_random_base_word_from_tree(adj_tree);
            phrase[2] = Extract_random_base_word_from_tree(ver_tree);
            phrase[3] = Extract_random_base_word_from_tree(adv_tree);
            break;
        }
    }
    return phrase;
}



/* Function used to generate sentences from the flechies forms of a word, according to the model chosen by
 * our team.*/

char** generateurPhraseFlechie(p_tree ver_tree, p_tree nom_tree, p_tree adj_tree, p_tree adv_tree, p_tree det,int modele){
    char** phrase = NULL;
    int size;
    if(modele == 1)
    {
        phrase = malloc( sizeof(char*) * 6);
        size = 6;
    }
    else if(modele==3)
    {
        phrase = malloc( sizeof(char*) * 5);
        size = 5;
    }
    else
    {
        phrase = malloc( sizeof(char*) * 8);
        size = 8;
    }

    // We allocate a size to each case of the list
    for (int i=0; i<size;i++) {
        phrase[i] = malloc(sizeof(char)* 20);
    }

    char *random_word;
    p_flechiescell temp_cell;
    switch (modele)
    {
        case 1:
        {
            //noun : adjective : verb : noun

            // First noun
            random_word = Extract_random_base_word_from_tree(nom_tree);
            temp_cell = randomFlechiesWord(random_word,nom_tree);
            phrase[1] = temp_cell->flechie_word;

            //find determinant of the first noun
            phrase[0] = findDeterminantandAdjectives(det, temp_cell);

            phrase[2] = findDeterminantandAdjectives(adj_tree,temp_cell);

            phrase[3] = findVerb(ver_tree,temp_cell);

            // Second noun
            random_word = Extract_random_base_word_from_tree(nom_tree);
            temp_cell = randomFlechiesWord(random_word,nom_tree);
            phrase[5] = temp_cell->flechie_word;

            //find determinant of the second noun
            phrase[4] = findDeterminantandAdjectives(det, temp_cell);
            break;
        }
        case 2:
        {
            // noun : qui : verb : verb : noun : adjective

            // First noun
            random_word = Extract_random_base_word_from_tree(nom_tree);
            temp_cell = randomFlechiesWord(random_word,nom_tree);
            phrase[1] = temp_cell->flechie_word;

            //find determinant of the first noun
            phrase[0] = findDeterminantandAdjectives(det, temp_cell);

            phrase[2] = "qui";
            phrase[3] = findVerb(ver_tree,temp_cell);
            phrase[4] = findVerb(ver_tree,temp_cell);

            // Second noun
            random_word = Extract_random_base_word_from_tree(nom_tree);
            temp_cell = randomFlechiesWord(random_word,nom_tree);
            phrase[6] = temp_cell->flechie_word;

            //find determinant of the second noun
            phrase[5] = findDeterminantandAdjectives(det, temp_cell);

            phrase[7] = findDeterminantandAdjectives(adj_tree, temp_cell);
            break;
        }
        case 3:
        {
            // noun : adjective : verb : adverbe

            // First noun
            random_word = Extract_random_base_word_from_tree(nom_tree);
            temp_cell = randomFlechiesWord(random_word,nom_tree);
            phrase[1] = temp_cell->flechie_word;

            //find determinant of the first noun
            phrase[0] = findDeterminantandAdjectives(det, temp_cell);

            phrase[2] = findDeterminantandAdjectives(adj_tree, temp_cell);
            phrase[3] = findVerb(ver_tree,temp_cell);

            phrase[4] = Extract_random_base_word_from_tree(adv_tree);

            break;
        }
    }
    return phrase;
}

// Function used to find the correct 'determinant' according to the noun that it determines
char* findDeterminantandAdjectives(p_tree det, p_flechiescell noun_cell)
{

    char* random_word;
    p_flechiescell temp_cell;

    // SINGULIER + FEMININ DETERMINANT

    if(isSubstringInString(noun_cell->declinaison, "SG") == 1 && isSubstringInString(noun_cell->declinaison, "Fem") == 1)
    {
        // First we choose a random base word from the tree
        random_word = Extract_random_base_word_from_tree(det);
        // Then from that base word, we select a random flechies word
        temp_cell = randomFlechiesWord(random_word,det);
        // If the chosen flechie word isn't adapted according to the noun, we choose again until we find one which is correct
        while((isSubstringInString(temp_cell->declinaison, "SG") == 0) &&
              (isSubstringInString(temp_cell->declinaison, "Fem") == 0 ||
               isSubstringInString(temp_cell->declinaison, "InvGen") == 0))
        {
            random_word = Extract_random_base_word_from_tree(det);
            temp_cell = randomFlechiesWord(random_word,det);
        }
        // When we've found a flechie word that is grammatically correct, we return it as our 'determinant'
        return temp_cell->flechie_word;
    }

    // PLURIEL + FEMININ DETERMINANT
    else if(isSubstringInString(noun_cell->declinaison, "PL") == 1 && isSubstringInString(noun_cell->declinaison, "Fem") == 1)
    {
        random_word = Extract_random_base_word_from_tree(det);
        temp_cell = randomFlechiesWord(random_word,det);
        while((isSubstringInString(temp_cell->declinaison, "PL") == 0) &&
              (isSubstringInString(temp_cell->declinaison, "Fem") == 0 ||
               isSubstringInString(temp_cell->declinaison, "InvGen") == 0))
        {
            random_word = Extract_random_base_word_from_tree(det);
            temp_cell = randomFlechiesWord(random_word,det);
        }
        return temp_cell->flechie_word;
    }


    // SG + MASC DETERMINANT
    else if(isSubstringInString(noun_cell->declinaison, "SG") == 1 && isSubstringInString(noun_cell->declinaison, "Mas") == 1)
    {
        random_word = Extract_random_base_word_from_tree(det);
        temp_cell = randomFlechiesWord(random_word,det);
        while((isSubstringInString(temp_cell->declinaison, "SG") == 0) &&
              (isSubstringInString(temp_cell->declinaison, "Mas") == 0 ||
               isSubstringInString(temp_cell->declinaison, "InvGen") == 0))
        {
            random_word = Extract_random_base_word_from_tree(det);
            temp_cell = randomFlechiesWord(random_word,det);
        }
        return temp_cell->flechie_word;
    }


    // PL + MASC DETERMINANT + INVPL
    else
    {
        random_word = Extract_random_base_word_from_tree(det);
        temp_cell = randomFlechiesWord(random_word,det);
        while((isSubstringInString(temp_cell->declinaison, "PL") == 0) &&
              (isSubstringInString(temp_cell->declinaison, "Mas") == 0 ||
               isSubstringInString(temp_cell->declinaison, "InvGen") == 0))
        {
            random_word = Extract_random_base_word_from_tree(det);
            temp_cell = randomFlechiesWord(random_word,det);
        }
        return temp_cell->flechie_word;
    }
}

/* Function used to find the correct 'verb' according to the noun that it does the action. If the noun is plural,
 * the verb will be according to the third person of singular */
char* findVerb(p_tree ver, p_flechiescell noun_cell)
{
    char* random_word;
    p_flechiescell temp_cell;

    // IF THE NOUN IS SINGULAR
    if(isSubstringInString(noun_cell->declinaison,"SG") == 1)
    {
        // First we choose a random base word from the tree
        random_word = Extract_random_base_word_from_tree(ver);
        // Then from that base word, we select a random flechies word
        temp_cell = randomFlechiesWord(random_word,ver);

        // If the chosen flechie word isn't adapted according to the noun, we choose again until we find one which is correct
        while( isSubstringInString(temp_cell->declinaison,"SG+P3") == 0 )
        {
            random_word = Extract_random_base_word_from_tree(ver);
            temp_cell = randomFlechiesWord(random_word,ver);
        }
        // When we've found a flechie word that is grammatically correct, we return it as our 'verb'
        return temp_cell->flechie_word;
    }

    // IF THE NOUN IS PLURAL OR INVPL
    else
    {
        random_word = Extract_random_base_word_from_tree(ver);
        temp_cell = randomFlechiesWord(random_word,ver);


        while( isSubstringInString(temp_cell->declinaison,"PL+P3") == 0 )
        {
            random_word = Extract_random_base_word_from_tree(ver);
            temp_cell = randomFlechiesWord(random_word,ver);
        }
        return temp_cell->flechie_word;
    }
}
