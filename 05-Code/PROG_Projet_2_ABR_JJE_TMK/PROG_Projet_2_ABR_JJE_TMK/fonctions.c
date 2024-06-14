//------------------------------------------------------------------------------------------------//
// Auteur 				: ABR || JJE || TMK 
// Nom du projet 		: Projet 2
// Nom du fichier 		: Fonctions.c
// Date de cr�ation 	: 06.06.2024
// Date de modification : 06.06.2024
//------------------------------------------------------------------------------------------------// 

//Librairies standart
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <corecrt_math_defines.h>

//Librairies utilisateur
#include "fonctions.h"

#ifndef Fonction_ALAN
//**************************************************************                               
// Description : Gesion du menu 
//**************************************************************   
int gestionMenu(void)
{
    int redirection_menu = 0;

    do
    {
        // Affiche les options du menu
        printf("Selectionnez le numero correspondant a vos attentes\n");
        printf("====================== Menu ======================\n");
        printf("- 0 Quitter\n");
        printf("- 1 Pour la conversion Binaire\n");
        printf("- 2 Pour la fonction trigonometrique\n\n");

        // Lit la s�lection de l'utilisateur
        scanf("%d", &redirection_menu);

        // V�rifie si la s�lection de l'utilisateur est valide (entre 0 et 3)
        if (redirection_menu < 0 || redirection_menu > 2)
        {
            // Si la s�lection n'est pas valide, affiche un message d'erreur
            printf("\nLe numero entre n'est pas correct (entre 0 et 2)\n\n");
        }

        // R�p�te l'affichage du menu tant que la s�lection de l'utilisateur n'est pas valide
    } while (redirection_menu < 0 || redirection_menu > 2);

    // Retourne la s�lection valide de l'utilisateur
    return redirection_menu;
}

//**************************************************************                               
// Description : Fonction pour afficher un entier en binaire 
// avec un nombre de bits sp�cifi�
// Param�tres d'entr�e :
//   - int valBinaire
//   - int optionAffichage
//**************************************************************   
void impressionBinaire(int valBinaire, int optionAffichage)
{
    // Si optionAffichage est 0, calcule le nombre minimal de bits n�cessaires
    if (optionAffichage == 0)
    {
        int start = 0;
        // D�cale valBinaire vers la droite jusqu'� ce qu'il devienne 0
        // Le nombre de d�calages est le nombre minimal de bits n�cessaires
        while ((valBinaire >> start) != 0) start++;
        // Met � jour optionAffichage avec le nombre minimal de bits n�cessaires
        optionAffichage = start;
    }

    // Parcourt chaque bit de valBinaire de gauche � droite
    for (int i = optionAffichage - 1; i >= 0; i--)
    {
        // Affiche le bit en position i
        printf("%d", (valBinaire >> i) & 1);
        // Ajoute un espace apr�s chaque groupe de 4 bits pour une meilleure lisibilit�
        if (i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }
}

//**************************************************************                               
// Description :  Fonction pour afficher un nombre � virgule
//  en binaire
// Param�tres d'entr�e :
//   - int valBinaire
//************************************************************** 
void impressionDecimale(float valBinaire)
{
    // S�pare la partie enti�re de la partie fractionnaire
    int int_part = (int)valBinaire;
    float frac_part = valBinaire - int_part;

    // Affiche la partie enti�re en binaire
    if (int_part == 0)
        printf("0");
    else
        impressionBinaire(int_part, 0);

    // Affiche le s�parateur pour la partie fractionnaire
    printf(".");

    // Boucle pour convertir et afficher la partie fractionnaire
    while (frac_part != 0.0)
    {
        // Multiplie la partie fractionnaire par 2
        frac_part *= 2;

        // Si la partie fractionnaire est sup�rieure ou �gale � 1
        if (frac_part >= 1.0)
        {
            // Affiche 1
            printf("1");
            // Soustrait 1 de la partie fractionnaire
            frac_part -= 1.0;
        }
        else
        {
            // Si la partie fractionnaire est inf�rieure � 1, affiche 0
            printf("0");
        }
    }
}

//**************************************************************                               
// Description : Fonction pour convertir et afficher un nombre 
// selon l'option choisie
// Param�tres d'entr�e :
//   - char input
//   - int optionAffichage
//************************************************************** 
void ImpressionEtConversion(char* input, int optionAffichage)
{
    // Convertit la cha�ne de caract�res en nombre flottant
    float num = atof(input);

    // V�rifie si le nombre est entier
    if (num == (int)num)
    {
        int int_num = (int)num;

        // V�rification si le nombre de bits est suffisant pour repr�senter l'entier
        if (optionAffichage != 0 && optionAffichage < (int)(log2(abs(int_num)) + 1))
        {
            printf("Erreur : le nombre de bits sp�cifi� est insuffisant pour repr�senter le nombre.\n");
            return;
        }

        // Affiche le pr�fixe binaire
        printf("0b ");

        // V�rifie si le nombre entier est n�gatif
        if (int_num < 0)
        {
            // Convertit l'entier en non-sign� pour l'affichage en binaire
            unsigned int bin_num = (unsigned int)int_num;
            impressionBinaire(bin_num, optionAffichage);
        }
        else
        {
            // Affiche l'entier en binaire
            impressionBinaire(int_num, optionAffichage);
        }
    }
    else
    {
        // Si le nombre est � virgule flottante, affiche la partie enti�re et fractionnaire en binaire
        impressionDecimale(num);
    }

    // Passe � la ligne suivante apr�s l'affichage
    printf("\n");
}

//**************************************************************                               
// Description : Fonction pour convertir et afficher un nombre 
// selon l'option choisie
// Param�tres d'entr�e :
//   - int valBinaire
//**************************************************************
void conversionBinaire()
{
    char input[20];  // D�claration d'un tableau de caract�res pour stocker l'entr�e de l'utilisateur
    int option;      // D�claration d'un entier pour stocker l'option choisie

    // Demande � l'utilisateur de saisir une valeur d�cimale � convertir en binaire
    printf("\nSaisissez la valeur decimale a convertir en binaire\n\n");
    scanf("%s", input);  // Lit la cha�ne de caract�res saisie par l'utilisateur

    // Boucle pour v�rifier que l'option choisie est valide
    do
    {
        printf("\nChoix de la representation binaire\n");
        printf("- 1 Pour afficher sur le nombre minimum de bits\n");
        printf("- 2 Pour afficher sur 8 bits\n");
        printf("- 3 Pour afficher sur 16 bits\n");
        printf("- 4 Pour afficher sur 32 bits\n\n");
        scanf("%d", &option);  // Lit l'option choisie par l'utilisateur

        // V�rifie si l'option est valide (entre 1 et 4)
        if (option < 1 || option > 4)
        {
            printf("\nLe numero entre n est pas correct (entre 1 et 4)\n\n");
        }
    } while (option < 1 || option > 4);  // R�p�te la demande tant que l'option n'est pas valide

    // Utilise un switch pour g�rer les diff�rentes options choisies
    switch (option)
    {
    case 1:
        ImpressionEtConversion(input, 0);  // Appelle ImpressionEtConversion avec option 0 pour le nombre minimum de bits
        break;
    case 2:
        ImpressionEtConversion(input, 8);   // Appelle ImpressionEtConversion avec option 8 pour 8 bits
        break;
    case 3:
        ImpressionEtConversion(input, 16);  // Appelle ImpressionEtConversion avec option 16 pour 16 bits
        break;
    case 4:
        ImpressionEtConversion(input, 32);  // Appelle ImpressionEtConversion avec option 32 pour 32 bits
        break;
    default:
        printf("Option invalide.\n");  // Message d'erreur pour une option invalide
        break;
    }
}



#endif 

#ifndef Fonction_THOMAS
//**************************************************************                               
// Description : Prends la valeur calcul� par le programme de trigo/bin 
// et l'enregistre sur un fichier .txt de log.
// Garde en m�moire le nombre de fois le le programme � fait une conversion 
// bin ou une opp�ration trigo
// Param�tres d'entr�e : 
//   - choix (permet de savoir trigo ou bin)
//   - valeur (valeur calcul� avec les fonctions de mes coll�gues)
//************************************************************** 

int fonction_sauvgarde(int choix, int valeur)
{
    // D�clarations des fonctions
    void fonction_binaire(FILE * log_file, int* compteur_binaire);
    void fonction_trigo(FILE * log_file, int* compteur_trigo);
    void ajouter_log(FILE * log_file, const char* message);
    void mettre_a_jour_compteurs(const char* filename, int compteur_binaire, int compteur_trigo);
    void lire_compteurs(const char* filename, int* compteur_binaire, int* compteur_trigo);

    //Paramttrage du fichier de log    
    const char* filename = "log.txt";
    FILE* log_file;
    int compteur_binaire = 0; // Initialisation du compteur de fonction binaire
    int compteur_trigo = 0;   // Initialisation du compteur de fonction trigo

    // Lire les compteurs du fichier
    lire_compteurs(filename, &compteur_binaire, &compteur_trigo);

    // Ouverture du fichier log 
    log_file = fopen(filename, "a");
    if (log_file == NULL)
    {
        // Affichage d'erreur si fichier pas ouvrable
        perror("Erreur lors de l'ouverture du fichier log");
        return EXIT_FAILURE;
    }

    // Boucle permettant de s�lectionner quel compteur sera incr�ment�e dans le fichier
    while (1)
    {
        if (choix == 1)
        {
            fonction_binaire(log_file, &compteur_binaire);
        }

        if (choix == 2)
        {
            fonction_trigo(log_file, &compteur_trigo);
        }

        if (choix == 0)
        {
            // Sortir de la boucle si choix est 0
            break;
        }
    }

    // Mettre � jour les compteurs au d�but du fichier
    mettre_a_jour_compteurs(filename, compteur_binaire, compteur_trigo);

    // Fermeture du fichier log
    fclose(log_file);
    return 0;
}
//**************************************************************                               
// Description : Recuperation de la valeur � inscrire dans le
// fichier de log de la fonction bin. 
// (Va �tre modifi� � l'avenir car non conforme � la donn�e).
//************************************************************** 
void fonction_binaire(FILE* log_file, int* compteur_binaire)
{
    int valeur;
    (*compteur_binaire)++; // Incr�mentation du compteur execution du covertisseur binaire    
       

    // Cr�ation du message � ajouter au log
    char message[200];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);     //addition du temps local (PC)
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%d.%m.%Y - %H:%M", t); //Format de dates europe

    snprintf(message, sizeof(message), ".%d\n%s\nValeur entr�e : %d\n", valeur, date_time, valeur);

    // Ajout du message au fichier log
    ajouter_log(log_file, message);

    printf("Compteur utilisation fonction binaire : %d\n", *compteur_binaire);
}
//**************************************************************                               
// Description : Recuperation de la valeur � inscrire dans le
// fichier de log de la fonction trigo. 
// (Va �tre modifi� � l'avenir car non conforme � la donn�e).
//************************************************************** 
void fonction_trigo(FILE* log_file, int* compteur_trigo)
{
    int valeur;
    (*compteur_trigo)++; // Incr�mentation du compteur trigo


    // Cr�ation du message � ajouter au log
    char message[200];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%d.%m.%Y - %H:%M", t);

    snprintf(message, sizeof(message), "%d\n%s\nR�sultat de l'op�ration : %d\n", valeur, date_time, valeur);

    // Ajout du message au fichier log
    ajouter_log(log_file, message);

    printf("Compteur utilisation fonction trigo : %d\n", *compteur_trigo);
}
//**************************************************************                               
// Description : �criture des donn�es calcul�es dans le fichier
//************************************************************** 
void ajouter_log(FILE* log_file, const char* message)
{
    // �criture du message dans le fichier log
    fprintf(log_file, "%s", message);
    // Assure que les donn�es sont �crites imm�diatement
    fflush(log_file);
}
//**************************************************************                               
// Description : MAJ du compteur d'utilisation de fonction
//************************************************************** 
void mettre_a_jour_compteurs(const char* filename, int compteur_binaire, int compteur_trigo)
{
    // Lire le contenu existant du fichier
    FILE* log_file = fopen(filename, "r");
    if (log_file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier log");
        exit(EXIT_FAILURE);
    }

    fseek(log_file, 0, SEEK_END);
    long taille_fichier = ftell(log_file);
    fseek(log_file, 0, SEEK_SET);

    // Allocation de m�moire pour le contenu du fichier
    char* contenu = malloc(taille_fichier + 1);
    if (contenu == NULL)
    {
        perror("Erreur d'allocation de m�moire");
        fclose(log_file);
        exit(EXIT_FAILURE);
    }

    // Lecture du contenu du fichier
    fread(contenu, 1, taille_fichier, log_file);
    contenu[taille_fichier] = '\0';
    fclose(log_file);

    // R��crire les compteurs et le reste du contenu dans le fichier
    log_file = fopen(filename, "w");
    if (log_file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier log");
        free(contenu);
        exit(EXIT_FAILURE);
    }
    // �criture des compteurs au d�but du fichier
    fprintf(log_file, "Compteur binaire : %d\nCompteur trigo : %d\n", compteur_binaire, compteur_trigo);
    // �criture du reste du contenu
    fprintf(log_file, "%s", contenu);

    // Lib�ration de la m�moire allou�e
    free(contenu);
    fclose(log_file);
}
//**************************************************************                               
// Description : Lecture du fichier de sauvgarde pour le nombre
// de fonctions execut�es. Initialisation � 0 si le fichier 
// n'exsiste pas. 
//************************************************************** 
void lire_compteurs(const char* filename, int* compteur_binaire, int* compteur_trigo)
{
    // Ouverture du fichier en mode lecture
    FILE* log_file = fopen(filename, "r");
    if (log_file == NULL)
    {
        // Si le fichier n'existe pas, initialiser les compteurs � 0
        *compteur_binaire = 0;
        *compteur_trigo = 0;
        return;
    }

    // Lecture des compteurs � partir du fichier
    if (fscanf(log_file, "Compteur binaire : %d\nCompteur trigo : %d\n", compteur_binaire, compteur_trigo) != 2)
    {
        // Si la lecture �choue, initialiser les compteurs � 0
        *compteur_binaire = 0;
        *compteur_trigo = 0;
    }

    // Fermeture du fichier
    fclose(log_file);
}
#endif 

#ifndef Fonction_JEREMIE
//**************************************************************                               
// Description : Converti une valeur enti�re ou r�ele d�cimale 
// de l'utilisateur et la convertir en binaire et l'affiche dans la console
// Param�tres d'entr�e :
//   - valeur d�cimale 
//************************************************************** 
void fonction_trigonometrique(double abscisse, double oppose, double hypotenuse, int choixUtilisateurCote, int choixUtilisateurAngle)
{
    // D�finition structure
    typedef struct
    {
        double abscisse;
        double oppose;
        double hypotenuse;
        double sinus;
        double cosinus;
        double tangente;
        int    angleAlpha;
    } Triangle;

    // D�finition onion
    typedef union
    {
        int    angleAlphaDegres;
        double angleAlphaRad;
    } AngleAlpha;

    // D�claration variables
    double  sinus, cosinus, tangente;
    int     angleAlphaDegre;
    double  angleAlphaRad;

    if (choixUtilisateurCote == 1)                                          // Abscisse et c�t� oppos� connus
    {
        hypotenuse = sqrt(abscisse * abscisse + oppose * oppose);       // Calcul de l'hypot�nuse avec Pythagore
        printf("L'hypotenuse est : %.2lf\n", hypotenuse);
    }
    else if (choixUtilisateurCote == 2)                                     // Abscisse et hypoth�nuse connus
    {
        oppose = sqrt(hypotenuse * hypotenuse - abscisse * abscisse);   // Calcul de l'oppos� avec Pythagore
        printf("Le cote oppose est : %.2lf\n", oppose);
    }
    else if (choixUtilisateurCote == 3)                                     // C�t� oppos� et hypoth�nuse connus 
    {
        abscisse = sqrt(hypotenuse * hypotenuse - oppose * oppose);     // Calcul de l'abscisse avec Pythagore
        printf("L'abscisse est : %.2lf\n", abscisse);
    }
    else
    {
        printf("Erreur : Parametres inconnus.\n");
    }

    if (choixUtilisateurAngle == 1)
    {
        /* Calcul de l'angle Alpha en degr�s */
        angleAlphaDegre = atan(oppose / abscisse) * (180.0 / M_PI);

        /* Calcul du sinus, cosinus et tangente de l'angle Alpha */
        sinus = sin(angleAlphaDegre * (M_PI / 180.0));
        cosinus = cos(angleAlphaDegre * (M_PI / 180.0));
        tangente = tan(angleAlphaDegre * (M_PI / 180.0));

        /* Affichage des valeurs calcul�es pr�c�demment */
        printf("L'angle alpha est : %d degres\n", angleAlphaDegre);
        printf("Le sinus(alpha) est : %.2lf\n", sinus);
        printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
        printf("La tangente(alpha) est : %.2lf\n", tangente);
    }

    else if (choixUtilisateurAngle == 2)
    {
        /* Calcul de l'angle Alpha en radians */
        angleAlphaRad = acos(abscisse / hypotenuse);

        /* Calcul du sinus, cosinus et tangente de l'angle Alpha */
        sinus = sin(angleAlphaRad);
        cosinus = cos(angleAlphaRad);
        tangente = tan(angleAlphaRad);

        /* Affichage des valeurs calcul�es pr�c�demment */
        printf("L'angle alpha est : %.2lf radians\n", angleAlphaRad);
        printf("Le sinus(alpha) est : %.2lf\n", sinus);
        printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
        printf("La tangente(alpha) est : %.2lf\n", tangente);
    }
}
#endif 














