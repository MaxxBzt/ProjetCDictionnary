//
// Created by nolwen on 11/11/2022.
//

#ifndef PROJETCDICTIONNARY_MENUS_H
#define PROJETCDICTIONNARY_MENUS_H

#include <stdio.h>
#include "structures.h"
#include "fonctions.h"

void starter_menu(p_tree,p_tree,p_tree,p_tree,p_tree);
void FirstChoice_Submenu_One(p_tree,p_tree,p_tree,p_tree,p_tree);
void FirstChoice_Submenu_Two(p_tree current_tree,p_tree,p_tree,p_tree,p_tree,p_tree);

void SecondChoice_Submenu_One(p_tree,p_tree,p_tree,p_tree,p_tree);
void SecondChoice_Submenu_Two(p_tree current_tree,p_tree,p_tree,p_tree,p_tree,p_tree);

void ThirdChoice_Submenu_One(p_tree,p_tree,p_tree,p_tree,p_tree);
void ThirdChoice_Submenu_Two(char type,p_tree,p_tree,p_tree,p_tree,p_tree);
#endif //PROJETCDICTIONNARY_MENUS_H
