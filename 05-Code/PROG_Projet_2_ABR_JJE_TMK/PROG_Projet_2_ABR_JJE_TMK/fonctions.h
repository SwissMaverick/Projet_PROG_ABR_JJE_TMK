//------------------------------------------------------------------------------------------------//
// Auteur 				: ABR || JJE || TMK 
// Nom du projet 		: Projet 2 
// Nom du fichier 		: Fonctions.h
// Date de cr�ation 	: 06.06.2024
// Date de modification : 06.06.2024
//------------------------------------------------------------------------------------------------// 



//D�finition des constantes
 

//Prototypes des fonctions
//Alan
int gestionMenu(void);
void conversionBianire(void);
void fonction_trigonometrique(void);
void fonction_sauvgarde(int choix,double valeur);
//Thomas
void fonction_binaire(FILE* log_file, int* compteur_binaire, double valeur);
void fonction_trigo(FILE* log_file, int* compteur_trigo);
void ajouter_log(FILE* log_file, const char* message);
void mettre_a_jour_compteurs(const char* filename, int compteur_binaire, int compteur_trigo);
void lire_compteurs(const char* filename, int* compteur_binaire, int* compteur_trigo);
//J�remie