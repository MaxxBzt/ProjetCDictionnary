//
// Created by nolwen on 11/20/2022.
//

#ifndef PROJETCDICTIONNARY_HANDLESENTENCES_H
#define PROJETCDICTIONNARY_HANDLESENTENCES_H

#include "handleTrees.h"


char** generateurPhraseBase(p_tree ver_tree, p_tree nom_tree, p_tree adj_tree, p_tree adv_tree, int modele);
char** generateurPhraseFlechie(p_tree ver_tree, p_tree nom_tree, p_tree adj_tree, p_tree adv_tree, p_tree det,int modele);

char* findDeterminantandAdjectives(p_tree det, p_flechiescell noun_cell);
char* findVerb(p_tree ver, p_flechiescell noun_cell);

#endif //PROJETCDICTIONNARY_HANDLESENTENCES_H
