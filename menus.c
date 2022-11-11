//
// Created by nolwen on 11/11/2022.
//

#include "menus.h"

void starter_menu(){
    int option = 0;
    printf("-------------------------------------------------\n");
    printf("-                 MENU                          -\n");
    printf("-------------------------------------------------\n");

    printf("- Entrer 1 pour chercher un mot                 -\n");
    printf("- Entrer 2 pour chercher un mot aleatoire       -\n");
    printf("- Entrer 3 pour generer des phrases aleatoires  -\n");
    printf("- Entrer 0 pour sortir du programme             -\n");
    printf("-------------------------------------------------\n");

    printf(">>");
    scanf(" %d", &option);

    switch(option){
        case 0:
        {
            break; // Sortir du programme
        }
        case 1:
        {
            FirstChoice_Submenu_One(); //Chercher un mot
        }
        case 2:
        {
            SecondChoice_Submenu_One(); //search a word randomly
        }
        case 3:
        {
            ThirdChoice_Submenu_One(); //generate random sentences
        }
        default:
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }
    }
}

void FirstChoice_Submenu_One(){
    /*
     * L'utilisateur cherche si le mot qu'il entre est dans la base de donnée
     */
    int choice;
    printf("Voulez vous chercher les mots a partir de leurs formes de bases ou leurs mots flechies ?\n"
           "1. Entrer 1 pour formes de bases\n"
           "2. Entrer 2 pour formes flechies\n"
           "3. Entrer 3 pour revenir sur le menu de depart\n>>>");
    scanf(" %d", &choice);

    char mot[30];
    switch(choice)
    {
        case 1:
        { //formes de bases
            printf("Quel est votre mot ?\n");
            scanf("%s",mot);
            FirstChoice_Submenu_Two('b',mot);
            break;
        }
        case 2 :
        { // formes fléchies
            printf("Quel est votre mot ?\n");
            scanf("%s",mot);
            FirstChoice_Submenu_Two('f',mot);
            break;
        }
        case 3:
        { // going back to menu
            starter_menu();
        }
        default:
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }
    }
}

void FirstChoice_Submenu_Two(char type, char *mot)
{
    /*

     */
    int submenu_choice;
    printf("Quel est le type de votre mot\n"
           "ATTENTION: Si vous ne connaissez pas le type de votre mot, cherchez sur internet.\n"
           "1. Entrer 1 pour verbes\n"
           "2. Entrer 2 pour adjectifs\n"
           "3. Entrer 3 pour adverbes\n"
           "4. Entrer 4 pour noms\n"
           "5. Entrer 5 pour revenir au menu de depart\n>>>");
    scanf(" %d", &submenu_choice);

    switch (submenu_choice)
    {
        case 1 :
        { // On cherche un mot dans l'arbre des verbes

            starter_menu();
        }
        case 2:
        { // On cherche un mot dans l'arbre des adjectifs
            starter_menu();
        }
        case 3:
        { // On cherche un mot dans l'arbre des adverbes
            starter_menu();
        }
        case 4 :
        { // On cherche un mot dans l'arbre des noms
            starter_menu();
        }
        case 5 :
        { // Retourner au menu de départ
            starter_menu();
        }
        default :
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }

    }
}

void SecondChoice_Submenu_One(){
    /*
     *
     */
    int choice;
    printf("Voulez vous generer un mot aleatoire a partir de leurs formes de bases ou leurs mots flechies ?\n"
           "1. Entrer 1 pour formes de bases\n"
           "2. Entrer 2 pour formes flechies\n"
           "3. Entrer 3 pour revenir sur le menu de depart\n>>>");
    scanf(" %d", &choice);

    switch(choice)
    {
        case 1:
        { //formes de bases
            // A VOIR
            SecondChoice_Submenu_Two('b');
            break;
        }
        case 2 :
        { // formes fléchies
            // A VOIR
            SecondChoice_Submenu_Two('f');
            break;
        }
        case 3:
        { // going back to menu
            starter_menu();
        }
        default:
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }
    }
}

void SecondChoice_Submenu_Two(char type)
{
    /*

     */
    int submenu_choice;
    printf("Quel est le type de votre mot\n"
           "ATTENTION: Si vous ne connaissez pas le type de votre mot, cherchez sur internet.\n"
           "1. Entrer 1 pour verbes\n"
           "2. Entrer 2 pour adjectifs\n"
           "3. Entrer 3 pour adverbes\n"
           "4. Entrer 4 pour noms\n"
           "5. Entrer 5 pour revenir au menu de depart\n>>>");
    scanf(" %d", &submenu_choice);

    switch (submenu_choice)
    {
        case 1 :
        { // On cherche un mot aléatoire dans l'arbre des verbes

            starter_menu();
        }
        case 2:
        { // On cherche un mot aléatoire dans l'arbre des adjectifs
            starter_menu();
        }
        case 3:
        { // On cherche un mot aléatoire dans l'arbre des adverbes
            starter_menu();
        }
        case 4 :
        { // On cherche un mot aléatoire dans l'arbre des noms
            starter_menu();
        }
        case 5 :
        { // Retourner au menu de départ
            starter_menu();
        }
        default :
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }

    }
}

void ThirdChoice_Submenu_One(){
    /*
     *
     */
    int choice;
    printf("Voulez vous chercher generer les phrases avec des mots a partir leurs formes de bases ou leurs mots flechies ?\n"
           "1. Entrer 1 pour formes de bases\n"
           "2. Entrer 2 pour formes flechies\n"
           "3. Entrer 3 pour revenir sur le menu de depart\n>>>");
    scanf(" %d", &choice);

    char mot[30];
    switch(choice)
    {
        case 1:
        { //formes de bases
            // A VOIR
            ThirdChoice_Submenu_Two('b');
            break;
        }
        case 2 :
        { // formes fléchies
            // A VOIR
            ThirdChoice_Submenu_Two('f');
            break;
        }
        case 3:
        { // going back to menu
            starter_menu();
        }
        default:
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }
    }
}

void ThirdChoice_Submenu_Two(char type)
{
    /*

     */
    int submenu_choice;
    printf("A partir de quel modele voulez-vous que les phrases soient generees ?\n"
           "1. Entrer 1 pour le modele : nom : adjectif : verbe : nom\n"
           "2. Entrer 2 pour le modele : nom : ‘qui’ : verbe : verbe : nom : adjectif\n"
           "3. Entrer 3 pour le modele : nom : verbe : adjectif : nom\n"
           "4. Entrer 4 pour revenir au menu de depart\n>>>");
    scanf(" %d", &submenu_choice);

    switch (submenu_choice)
    {
        case 1 :
        { // On cherche un mot aléatoire dans l'arbre des verbes

            starter_menu();
        }
        case 2:
        { // On cherche un mot aléatoire dans l'arbre des adjectifs
            starter_menu();
        }
        case 3:
        { // On cherche un mot aléatoire dans l'arbre des adverbes
            starter_menu();
        }
        case 4 :
        { // Retourner au menu de départ
            starter_menu();
        }
        default :
        {
            printf("Le choix selectionne n'est pas propose.\n");
            starter_menu();
        }

    }
}