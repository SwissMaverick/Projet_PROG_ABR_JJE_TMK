//------------------------------------------------------------------------------------------------//
// Auteur 				: ABR || JJE || TMK 
// Nom du projet 		: Projet 2
// Nom du fichier 		: Fonctions.c
// Date de création 	: 06.06.2024
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

        // Lit la sélection de l'utilisateur
        scanf("%d", &redirection_menu);

        // Vérifie si la sélection de l'utilisateur est valide (entre 0 et 3)
        if (redirection_menu < 0 || redirection_menu > 2)
        {
            // Si la sélection n'est pas valide, affiche un message d'erreur
            printf("\nLe numero entre n'est pas correct (entre 0 et 2)\n\n");
        }

        // Répète l'affichage du menu tant que la sélection de l'utilisateur n'est pas valide
    } while (redirection_menu < 0 || redirection_menu > 2);

    // Retourne la sélection valide de l'utilisateur
    return redirection_menu;
}

//**************************************************************                               
// Description : Fonction pour afficher un entier en binaire 
// avec un nombre de bits spécifié
// Paramètres d'entrée :
//   - int valBinaire
//   - int optionAffichage
//**************************************************************   
void impressionBinaire(int valBinaire, int optionAffichage)
{
    // Si optionAffichage est 0, calcule le nombre minimal de bits nécessaires
    if (optionAffichage == 0)
    {
        int start = 0;
        // Décale valBinaire vers la droite jusqu'à ce qu'il devienne 0
        // Le nombre de décalages est le nombre minimal de bits nécessaires
        while ((valBinaire >> start) != 0) start++;
        // Met à jour optionAffichage avec le nombre minimal de bits nécessaires
        optionAffichage = start;
    }

    // Parcourt chaque bit de valBinaire de gauche à droite
    for (int i = optionAffichage - 1; i >= 0; i--)
    {
        // Affiche le bit en position i
        printf("%d", (valBinaire >> i) & 1);
        // Ajoute un espace après chaque groupe de 4 bits pour une meilleure lisibilité
        if (i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }
}

//**************************************************************                               
// Description :  Fonction pour afficher un nombre à virgule
//  en binaire
// Paramètres d'entrée :
//   - int valBinaire
//************************************************************** 
void impressionDecimale(float valBinaire)
{
    // Sépare la partie entière de la partie fractionnaire
    int int_part = (int)valBinaire;
    float frac_part = valBinaire - int_part;

    // Affiche la partie entière en binaire
    if (int_part == 0)
        printf("0");
    else
        impressionBinaire(int_part, 0);

    // Affiche le séparateur pour la partie fractionnaire
    printf(".");

    // Boucle pour convertir et afficher la partie fractionnaire
    while (frac_part != 0.0)
    {
        // Multiplie la partie fractionnaire par 2
        frac_part *= 2;

        // Si la partie fractionnaire est supérieure ou égale à 1
        if (frac_part >= 1.0)
        {
            // Affiche 1
            printf("1");
            // Soustrait 1 de la partie fractionnaire
            frac_part -= 1.0;
        }
        else
        {
            // Si la partie fractionnaire est inférieure à 1, affiche 0
            printf("0");
        }
    }
}

//**************************************************************                               
// Description : Fonction pour convertir et afficher un nombre 
// selon l'option choisie
// Paramètres d'entrée :
//   - char input
//   - int optionAffichage
//************************************************************** 
void ImpressionEtConversion(char* input, int optionAffichage)
{
    // Convertit la chaîne de caractères en nombre flottant
    float num = atof(input);

    // Vérifie si le nombre est entier
    if (num == (int)num)
    {
        int int_num = (int)num;

        // Vérification si le nombre de bits est suffisant pour représenter l'entier
        if (optionAffichage != 0 && optionAffichage < (int)(log2(abs(int_num)) + 1))
        {
            printf("Erreur : le nombre de bits spécifié est insuffisant pour représenter le nombre.\n");
            return;
        }

        // Affiche le préfixe binaire
        printf("0b ");

        // Vérifie si le nombre entier est négatif
        if (int_num < 0)
        {
            // Convertit l'entier en non-signé pour l'affichage en binaire
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
        // Si le nombre est à virgule flottante, affiche la partie entière et fractionnaire en binaire
        impressionDecimale(num);
    }

    // Passe à la ligne suivante après l'affichage
    printf("\n");
}

//**************************************************************                               
// Description : Fonction pour convertir et afficher un nombre 
// selon l'option choisie
// Paramètres d'entrée :
//   - int valBinaire
//**************************************************************
void conversionBinaire()
{
    char input[20];  // Déclaration d'un tableau de caractères pour stocker l'entrée de l'utilisateur
    int option;      // Déclaration d'un entier pour stocker l'option choisie

    // Demande à l'utilisateur de saisir une valeur décimale à convertir en binaire
    printf("\nSaisissez la valeur decimale a convertir en binaire\n\n");
    scanf("%s", input);  // Lit la chaîne de caractères saisie par l'utilisateur

    // Boucle pour vérifier que l'option choisie est valide
    do
    {
        printf("\nChoix de la representation binaire\n");
        printf("- 1 Pour afficher sur le nombre minimum de bits\n");
        printf("- 2 Pour afficher sur 8 bits\n");
        printf("- 3 Pour afficher sur 16 bits\n");
        printf("- 4 Pour afficher sur 32 bits\n\n");
        scanf("%d", &option);  // Lit l'option choisie par l'utilisateur

        // Vérifie si l'option est valide (entre 1 et 4)
        if (option < 1 || option > 4)
        {
            printf("\nLe numero entre n est pas correct (entre 1 et 4)\n\n");
        }
    } while (option < 1 || option > 4);  // Répète la demande tant que l'option n'est pas valide

    // Utilise un switch pour gérer les différentes options choisies
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
// Description : Prends la valeur calculé par le programme de trigo/bin 
// et l'enregistre sur un fichier .txt de log.
// Garde en mémoire le nombre de fois le le programme à fait une conversion 
// bin ou une oppération trigo
// Paramètres d'entrée : 
//   - choix (permet de savoir trigo ou bin)
//   - valeur (valeur calculé avec les fonctions de mes collègues)
//************************************************************** 

int fonction_sauvgarde(int choix, int valeur)
{
    // Déclarations des fonctions
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

    // Boucle permettant de sélectionner quel compteur sera incrémentée dans le fichier
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

    // Mettre à jour les compteurs au début du fichier
    mettre_a_jour_compteurs(filename, compteur_binaire, compteur_trigo);

    // Fermeture du fichier log
    fclose(log_file);
    return 0;
}
//**************************************************************                               
// Description : Recuperation de la valeur à inscrire dans le
// fichier de log de la fonction bin. 
// (Va être modifié à l'avenir car non conforme à la donnée).
//************************************************************** 
void fonction_binaire(FILE* log_file, int* compteur_binaire)
{
    int valeur;
    (*compteur_binaire)++; // Incrémentation du compteur execution du covertisseur binaire    
       

    // Création du message à ajouter au log
    char message[200];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);     //addition du temps local (PC)
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%d.%m.%Y - %H:%M", t); //Format de dates europe

    snprintf(message, sizeof(message), ".%d\n%s\nValeur entrée : %d\n", valeur, date_time, valeur);

    // Ajout du message au fichier log
    ajouter_log(log_file, message);

    printf("Compteur utilisation fonction binaire : %d\n", *compteur_binaire);
}
//**************************************************************                               
// Description : Recuperation de la valeur à inscrire dans le
// fichier de log de la fonction trigo. 
// (Va être modifié à l'avenir car non conforme à la donnée).
//************************************************************** 
void fonction_trigo(FILE* log_file, int* compteur_trigo)
{
    int valeur;
    (*compteur_trigo)++; // Incrémentation du compteur trigo


    // Création du message à ajouter au log
    char message[200];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%d.%m.%Y - %H:%M", t);

    snprintf(message, sizeof(message), "%d\n%s\nRésultat de l'opération : %d\n", valeur, date_time, valeur);

    // Ajout du message au fichier log
    ajouter_log(log_file, message);

    printf("Compteur utilisation fonction trigo : %d\n", *compteur_trigo);
}
//**************************************************************                               
// Description : écriture des données calculées dans le fichier
//************************************************************** 
void ajouter_log(FILE* log_file, const char* message)
{
    // Écriture du message dans le fichier log
    fprintf(log_file, "%s", message);
    // Assure que les données sont écrites immédiatement
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

    // Allocation de mémoire pour le contenu du fichier
    char* contenu = malloc(taille_fichier + 1);
    if (contenu == NULL)
    {
        perror("Erreur d'allocation de mémoire");
        fclose(log_file);
        exit(EXIT_FAILURE);
    }

    // Lecture du contenu du fichier
    fread(contenu, 1, taille_fichier, log_file);
    contenu[taille_fichier] = '\0';
    fclose(log_file);

    // Réécrire les compteurs et le reste du contenu dans le fichier
    log_file = fopen(filename, "w");
    if (log_file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier log");
        free(contenu);
        exit(EXIT_FAILURE);
    }
    // Écriture des compteurs au début du fichier
    fprintf(log_file, "Compteur binaire : %d\nCompteur trigo : %d\n", compteur_binaire, compteur_trigo);
    // Écriture du reste du contenu
    fprintf(log_file, "%s", contenu);

    // Libération de la mémoire allouée
    free(contenu);
    fclose(log_file);
}
//**************************************************************                               
// Description : Lecture du fichier de sauvgarde pour le nombre
// de fonctions executées. Initialisation à 0 si le fichier 
// n'exsiste pas. 
//************************************************************** 
void lire_compteurs(const char* filename, int* compteur_binaire, int* compteur_trigo)
{
    // Ouverture du fichier en mode lecture
    FILE* log_file = fopen(filename, "r");
    if (log_file == NULL)
    {
        // Si le fichier n'existe pas, initialiser les compteurs à 0
        *compteur_binaire = 0;
        *compteur_trigo = 0;
        return;
    }

    // Lecture des compteurs à partir du fichier
    if (fscanf(log_file, "Compteur binaire : %d\nCompteur trigo : %d\n", compteur_binaire, compteur_trigo) != 2)
    {
        // Si la lecture échoue, initialiser les compteurs à 0
        *compteur_binaire = 0;
        *compteur_trigo = 0;
    }

    // Fermeture du fichier
    fclose(log_file);
}
#endif 

#ifndef Fonction_JEREMIE
//**************************************************************                               
// Description : Converti une valeur entière ou réele décimale 
// de l'utilisateur et la convertir en binaire et l'affiche dans la console
// Paramètres d'entrée :
//   - valeur décimale 
//************************************************************** 
void fonction_trigonometrique(double abscisse, double oppose, double hypotenuse, int choixUtilisateurCote, int choixUtilisateurAngle)
{
    // Définition structure
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

    // Définition onion
    typedef union
    {
        int    angleAlphaDegres;
        double angleAlphaRad;
    } AngleAlpha;

    // Déclaration variables
    double  sinus, cosinus, tangente;
    int     angleAlphaDegre;
    double  angleAlphaRad;

    if (choixUtilisateurCote == 1)                                          // Abscisse et côté opposé connus
    {
        hypotenuse = sqrt(abscisse * abscisse + oppose * oppose);       // Calcul de l'hypoténuse avec Pythagore
        printf("L'hypotenuse est : %.2lf\n", hypotenuse);
    }
    else if (choixUtilisateurCote == 2)                                     // Abscisse et hypothénuse connus
    {
        oppose = sqrt(hypotenuse * hypotenuse - abscisse * abscisse);   // Calcul de l'opposé avec Pythagore
        printf("Le cote oppose est : %.2lf\n", oppose);
    }
    else if (choixUtilisateurCote == 3)                                     // Côté opposé et hypothénuse connus 
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
        /* Calcul de l'angle Alpha en degrés */
        angleAlphaDegre = atan(oppose / abscisse) * (180.0 / M_PI);

        /* Calcul du sinus, cosinus et tangente de l'angle Alpha */
        sinus = sin(angleAlphaDegre * (M_PI / 180.0));
        cosinus = cos(angleAlphaDegre * (M_PI / 180.0));
        tangente = tan(angleAlphaDegre * (M_PI / 180.0));

        /* Affichage des valeurs calculées précédemment */
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

        /* Affichage des valeurs calculées précédemment */
        printf("L'angle alpha est : %.2lf radians\n", angleAlphaRad);
        printf("Le sinus(alpha) est : %.2lf\n", sinus);
        printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
        printf("La tangente(alpha) est : %.2lf\n", tangente);
    }
}
#endif 














