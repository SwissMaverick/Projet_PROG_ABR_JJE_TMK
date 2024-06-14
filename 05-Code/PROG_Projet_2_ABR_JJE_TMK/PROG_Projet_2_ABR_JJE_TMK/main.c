//------------------------------------------------------------------------------------------------//
// Auteur 				: ABR || JJE || TMK 
// Nom du projet 		: Projet 2
// Nom du fichier 		: main.c
// Date de cr�ation 	: 06.06.2024
// Date de modification : 06.06.2024
//------------------------------------------------------------------------------------------------// 

//Librairies standart
#include <stdio.h>
#include <stdlib.h>
#include <corecrt_math_defines.h>

//Librairies utilisateur
#include "fonctions.h"

int main()
{

    // D�claration variables trigo
    int     paramCote1, paramCote2;
    int     paramAngle;
    double  abscisse = 0.0, oppose = 0.0, hypotenuse = 0.0;

        switch (gestionMenu())
        {
        case 0:
            return 1;
            break;
        case 1:

            conversionBinaire();
            break;

        case 2: // Main pour la fonction trigonom�trique

            /* S�quence pour entrer les param�tres */
            printf("Choisissez deux parametres parmi les suivants :\n");
            printf("1 - Abscisse (cote adjacent)\n");
            printf("2 - Cote oppose\n");
            printf("3 - Hypothenuse\n");
            printf("Attention, l'hypotenuse doit etre plus grande que l'abscisse ou l'oppose\n");
            printf("Entrez le numero du premier parametre : ");
            scanf("%d", &paramCote1);
            printf("Entrez le numero du deuxieme parametre : ");
            scanf("%d", &paramCote2);
            printf("Choisissez l'unite de l'angle Alpha :\n");
            printf("1 - Degre\n");
            printf("2 - Radian\n");
            printf("Entrez le numero de l'unite de l'angle Alpha\n");
            scanf("%d", &paramAngle);

            if (paramAngle == 1)    /* Dans le cas o� on a choisi l'angle en degr�s */
            {
                /* Dans le cas o� on a choisi l'abscisse et l'oppos� */
                if ((paramCote1 == 1 && paramCote2 == 2) || (paramCote1 == 2 && paramCote2 == 1))
                {
                    printf("Entrez la valeur de l'abscisse : ");
                    scanf("%lf", &abscisse);
                    printf("Entrez la valeur du cote oppose : ");
                    scanf("%lf", &oppose);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 1, 1);  //La variable "choixUtilisateur" est � "1"
                }

                /* Dans le cas o� on a choisi l'abscisse et l'hypot�nuse */
                else if ((paramCote1 == 1 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 1))
                {
                    printf("Entrez la valeur de l'abscisse : ");
                    scanf("%lf", &abscisse);
                    printf("Entrez la valeur de l'hypotenuse : ");
                    scanf("%lf", &hypotenuse);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 2, 1);  //La variable "choixUtilisateur" est � "2"
                }

                /* Dans le cas o� on a choisi l'oppos� et l'hypot�nuse */
                else if ((paramCote1 == 2 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 2))
                {
                    printf("Entrez la valeur du cote oppose : ");
                    scanf("%lf", &oppose);
                    printf("Entrez la valeur de l'hypotenuse : ");
                    scanf("%lf", &hypotenuse);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 3, 1);  //La variable "choixUtilisateur" est � "3"
                }

                else
                {
                    printf("Erreur : choix invalides.\n");                      // Dans le cas o� on n'a pas rentr� de bons param�tres
                }
            }

            else if (paramAngle == 2)   /* Dans le cas o� on a choisi l'angle en radians */
            {
                /* Dans le cas o� on a choisi l'abscisse et l'oppos� */
                if ((paramCote1 == 1 && paramCote2 == 2) || (paramCote1 == 2 && paramCote2 == 1))
                {
                    printf("Entrez la valeur de l'abscisse : ");
                    scanf("%lf", &abscisse);
                    printf("Entrez la valeur du cote oppose : ");
                    scanf("%lf", &oppose);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 1, 2);  //La variable "choixUtilisateur" est � "1"
                }

                /* Dans le cas o� on a choisi l'abscisse et l'hypot�nuse */
                else if ((paramCote1 == 1 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 1))
                {
                    printf("Entrez la valeur de l'abscisse : ");
                    scanf("%lf", &abscisse);
                    printf("Entrez la valeur de l'hypotenuse : ");
                    scanf("%lf", &hypotenuse);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 2, 2);  //La variable "choixUtilisateur" est � "2"
                }

                /* Dans le cas o� on a choisi l'oppos� et l'hypot�nuse */
                else if ((paramCote1 == 2 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 2))
                {
                    printf("Entrez la valeur du cote oppose : ");
                    scanf("%lf", &oppose);
                    printf("Entrez la valeur de l'hypotenuse : ");
                    scanf("%lf", &hypotenuse);
                    fonction_trigonometrique(abscisse, oppose, hypotenuse, 3, 2);  //La variable "choixUtilisateur" est � "3"
                }

                else
                {
                    printf("Erreur : choix invalides.\n");                      // Dans le cas o� on n'a pas rentr� de bons param�tres
                }
            }

            else
            {
                printf("Erreur : choix invalides.\n");
            }
            break;

        default:
            printf("La valeur entr�e n'est pas correcte\n\n\n");

            break;
        }
        //fichierLogs();
}
