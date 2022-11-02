//
// Created by Maxime Bézot on 17/10/2022.
//
#include <stdio.h>
#include "structures.h"

int main(){
    p_node test;
    test = createNode('a');
    printf("%c",test->letter);
    return 0;
}