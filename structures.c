//
// Created by Maxime Bézot on 02/11/2022.
//

#include "structures.h"

p_node createNode(char letter){
    p_node node = malloc(sizeof(t_node));
    node->letter = letter;
    return node;
}