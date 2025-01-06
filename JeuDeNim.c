/*
///////////////////////////////////////////////////////////////
//                                                           //
//    /////   /////   /////         /|     ///////    /////  //
//   ||      ||   ||  ||           /||     ||   ||   //  //  //
//    ////   ||///||  /////         ||     ||   ||      //   //
//       ||  ||   ||  ||            ||     ||   ||    //     //
//   //////  ||   ||  /////  /////  ||  @  ///////  //////   //
//                                                           //
///////////////////////////////////////////////////////////////

  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  ||                                Jeu de Nim - Ahmet BASBUNAR - 2024-2025                                            ||
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  || Voici la Liste des fonctions pour le jeu du Nim:                                                                   ||
  ||                                                                                                                    ||
  || < Lire_Entier >             - Permet de lire un entier et de le valider entre deux bornes.                         ||
  || < Parametres >              - Permet de lire les paramètres du jeu.                                                ||
  || < Voisines >                - Construit la liste des cases voisines d'une case donnée.                             ||
  || < Hasard >                  - Génère un déplacement au hasard.                                                     ||
  || < Nimber >                  - Calcule le nimber d'une case donnée.                                                 ||
  || < Coup_Joueur >             - Permet au joueur humain de choisir une destination parmi les voisines possibles.     ||
  || < Coup_Ordi_Hasard >        - Permet à l'ordinateur de choisir un coup au hasard.                                  ||
  || < Coup_Ordi_Gagnant >       - Permet à l'ordinateur de jouer un coup gagnant.                                      ||
  || < Affiche_Grille >          - Affiche la grille de jeu avec des bordures.                                          ||
  || < main >                    - Assemble l’ensemble et exécute la partie.                                            ||
  ||                                                                                                                    ||
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  ======================================================================================================
  ||  Couleurs ANSI Utilisées dans le jeu du Nim :                                                    ||
  ||                                                                                                  ||
  || < \033[31m - Rouge >        - Utilisé pour les messages d'erreur                                 ||
  || < \033[32m - Vert >         - Utilisé pour les messages de succès                                ||
  || < \033[33m - Jaune >        - Utilisé pour les messages de prompt                                ||
  || < \033[34m - Bleu >         - Utilisé pour les titres et séparations                             ||
  || < \033[35m - Magenta >      - Utilisé pour les choix du joueur                                   ||
  || < \033[36m - Cyan >         - Utilisé pour les messages spécifiques (créateur, choix du joueur)  ||
  || < \033[0m  - Reset >        - Reset les couleurs au défaut du terminal                           ||
  ======================================================================================================

  ======================
  || symboles :       ||
  ||   -> pion  : ♟   ||
  ||   -> puits : 🚩  ||
  ||   -> fin   : 🔴  ||
  ||   -> case  : -   ||
  ======================

  |||||||||||||||||||||||||||||||||||||||||
  ||||        Prévisualisation :       ||||
  |||||||||||||||||||||||||||||||||||||||||

  =========================================
  || A. Grille de Jeu (5x5) :            ||
  =========================================

          1   2   3   4   5              1   2   3   4   5              1   2   3   4   5
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+
      1 | ♟ | - | - | - | - |        1 | - | - | - | - | - |        1 | - | - | - | - | - |
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+
      2 | - | - | - | - | - |        2 | - | - | - | - | - |        2 | - | - | - | - | - |
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+
      3 | - | - | - | - | - |        3 | - | - | - | - | ♟ |        3 | - | - | - | - | - |
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+
      4 | - | - | - | - | - |        4 | - | - | - | - | - |        4 | - | - | - | - | - |
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+
      5 | - | - | - | - | 🚩|        5 | - | - | - | - | 🚩 |        5 | - | - | - | - | 🔴|
        +---+---+---+---+---+          +---+---+---+---+---+          +---+---+---+---+---+

  =========================================
  || B.   Tableau des Nimbers (5x5) :    ||
  =========================================

          1   2   3   4   5
        +---+---+---+---+---+
      1 | 0 | 1 | 1 | 0 | 1 |
        +---+---+---+---+---+
      2 | 1 | 0 | 1 | 1 | 0 |
        +---+---+---+---+---+
      3 | 1 | 1 | 0 | 1 | 1 |
        +---+---+---+---+---+
      4 | 0 | 1 | 1 | 0 | 1 |
        +---+---+---+---+---+
      5 | 1 | 0 | 1 | 1 | 0 |
        +---+---+---+---+---+

  ||   - Description :
  ||     - Chaque case du tableau représente le nimber de la case correspondante dans la grille de jeu.
  ||     - Un nimber de `0` indique une position perdante, si le prochaine coup est joué par l'ordinateur.
  ||     - Un nimber de `1` indique une position gagnante, si le prochaine coup est joué par le joueur.

/////////////////////////////////////////////////////////
//                                                     //
//  Le Projet a été ajouté dans un repertoire GitHub.  //
//                                                     //
//      https://github.com/ahmetbsbnr/jeu-de-nim       //
//                                                     //
/////////////////////////////////////////////////////////
*/

//////////////////////////////////
////    Debut du programme    ////
//////////////////////////////////

//////////////////////////////////
////      Bibliothèques :    /////
//////////////////////////////////

//                                                     ||  Bibliothèques :

#include <stdio.h>                                    //|  standard pour les entrées/sorties
#include <stdlib.h>                                   //|  standard pour les fonctions utilitaires
#include <time.h>                                     //|  pour les fonctions liées au temps
#include <string.h>                                   //|  pour la manipulation des chaînes de caractères
#include <ctype.h>                                    //|  pour les fonctions de traitement de caractères

#define VMIN 5                                        //| Nombre minimum et maximum
#define VMAX 30                                       //|   de lignes/colonnes

//////////////////////////////////
//// 1. Déclarations de types ////
//////////////////////////////////

typedef struct {                                ///////| Structure représentant une case de la grille : (lig, col)
    int lig;                                         //| Ligne
    int col;                                         //| Colonne
} T_Case;                                            //| Stocke les coordonnées ligne/colonne

typedef struct {                                     //| Structure, T_Tab_Case,
    T_Case tab[4];                                   //| Tableau de 4 cases voisines
    int nb;                                          //| Nombre de voisins
} T_Tab_Case;                                   ///////| Tableau de cases voisines

/////////////////////////////////////////////
//// 2. Lecture et vérification d'entier ////
/////////////////////////////////////////////

//                                                                       || Fonction "Lire_Entier",lit une chaîne de caractères et la convertit en entier ||

int Lire_Entier(const char* message, int min, int max) {                                                   //////////|
    char buffer[100];                                                                                              //| defini une chaîne de caractères de taille 100
    int valeur;                                                                                                    //| Initialisation variable pour stocker | la valeur lue
    char* finptr;                                                                                                  //| Pointeur | stockage de la position de la fin de la conversion
//                                                                                                                 //|
    while (1) {                                                                                                    //| Boucle infinie
        printf("%s", message);                                                                                     //| --> Affiche le message (ex: "nombre de lignes : ")
//                                                                                                                 //|
//                                                                                                                 //| Lire une ligne d'entrée :
//                                                                                                                 //|
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {                                                        //| Si la lecture a échoué (fin de saisie, ex: Ctrl-D)
printf("\n\033[31m==> Fin de saisie, arrêt du jeu.\033[0m\n");                                                       //| --> Affiche un message, en rouge
            exit(0);                                                                                               //| On quitte proprement (sinon boucle infinie)
        }                                                                                                          //|
//                                                                                                                 //|
        size_t len = strlen(buffer);                                                                               //| Obtenir la longueur de la chaîne :
//                                                                                                                 //|
        if (len > 0 && buffer[len - 1] == '\n') {                                                                  //| Si la chaîne finit par un caractère de nouvelle ligne
            buffer[len - 1] = '\0';                                                                                //| --> On supprime le caractère de nouvelle ligne
        }                                                                                                          //|
//                                                                                                                 //|
//                                                                                                                 //|
        int estEspaceSeulement = 1;                                                                                //| Variable pour savoir si la chaîne est composée uniquement de espaces
        for (size_t i = 0; i < strlen(buffer); i++) {                                                              //| Parcourt la chaîne de caractères
            if (!isspace((unsigned char)buffer[i])) {                                                              //| Si le caractère n'est pas un espace
                estEspaceSeulement = 0;                                                                            //| --> La chaîne n'est pas composée uniquement de espaces
                break;                                                                                             //|
            }                                                                                                      //|
        }                                                                                                          //|
//                                                                                                                 //|
        if (strlen(buffer) == 0 || estEspaceSeulement) {                                                           //| Si la chaîne est vide ou composée uniquement de espaces
printf("\033[31m==> Entrée vide ou contenant uniquement des espaces. Veuillez entrer un entier.\033[0m\n");        //| --> Affiche un message d'erreur
            continue;                                                                                              //|
        }                                                                                                          //|
//                                                                                                                 //|
//                                                                                                                 //|
        valeur = (int)strtol(buffer, &finptr, 10);                                                                 //| Conversion de la chaîne de caractères en entier
//                                                                                                                 //|
//                                                                                                                 //|
        if (*finptr != '\0') {                                                                                     //| Si la chaîne contient des caractères supplémentaires
    printf("\033[31mEntrée invalide. Veuillez entrer un entier sans caractères supplémentaires.\033[0m\n");        //| --> Affiche un message d'erreur
            continue;                                                                                              //|
        }                                                                                                          //|
//                                                                                                                 //|
//                                                                                                                 //|
        if (valeur < min || valeur > max) {                                                                        //| Si la valeur n'est pas comprise entre min et max
printf("\033[31mLes valeurs doivent être comprises entre [%d et %d]. Veuillez réessayer.\033[0m\n", min, max);     //| --> Affiche un message d'erreur
            continue;                                                                                              //|
        }                                                                                                          //|
//                                                                                                                 //|
//                                                                                                                 //|
        return valeur;                                                                                             //|
    }                                                                                                              //|
}                                                                                                            ////////|

/////////////////////////////////////
//// 3. Paramètres de la partie  ////
/////////////////////////////////////

void Parametres(int* nlig, int* ncol, int* niveau, int* next) {//                                                       |||||| Saisie des paramètres du jeu |||||

    printf("\n==================================================================\n");                                   /////|
    printf("=================\033[34m Bienvenue dans le jeu du Nim ! \033[0m=================\n");                         //|
    printf("==================================================================\n");                                        //|
    printf("==================\033[34m Créateur : Ahmet BASBUNAR \033[0m=====================\n");                         //|
    printf("==================================================================\n");                                        //| Affiche un message de bienvenue
    printf("\033[36m=> Le but est d'atteindre le puits de la grille\033[0m\n");                                            //|   et explique le but du jeu
    printf("\033[36m=> en choisissant des cases voisines, et avec une certaine stratégie\033[0m\n");                       //|
    printf("==================================================================\n");                                        //|
    printf("\033[34m==> Veuillez saisir les Paramètres du jeu :\033[0m\n");                                                //|
    printf("==================================================================\n");                                     /////|
//
//                                                                                                                            //|  Saisie :
//                                                                                                                            //|
    *nlig = Lire_Entier("\033[32m==> Entrez le nombre de lignes ( entre 5 et 30 )   : \033[0m", VMIN, VMAX);            ////////| -> nombre de lignes avec les limites VMIN et VMAX
    printf("==================================================================\n");                                           //|          avec couleur
//                                                                                                                            //|
    *ncol = Lire_Entier("\033[32m==> Entrez le nombre de colonnes ( entre 5 et 30 )  : \033[0m", VMIN, VMAX);                 //| -> nombre de colonnes avec les limites VMIN et VMAX
    printf("==================================================================\n");                                           //|          avec couleur
//                                                                                                                            //|
    *niveau = Lire_Entier("\033[32m==> Choisissez un niveau de 1 à 4 : \033[0m", 1, 4);                                       //| -> niveau de difficulté (1 à 4)
    printf("==================================================================\n");                                           //|          avec couleur
//                                                                                                                            //|
    printf("----------------------\033[34m Qui commence le jeu ? \033[0m---------------------\n");                            //|
    printf("==================================================================\n");                                           //|
    *next = Lire_Entier("\033[32m==> Qui commence le jeu ? L’ordinateur (1) ou le joueur (2) : \033[0m", 1, 2);               //| -> Choix du premier joueur :
    printf("==================================================================\n");                                     ////////|   Ordinateur (1) ou Joueur (2)
}

////////////////////////////////
//// 4. Calcul des voisins  ////
////////////////////////////////

void Voisines(T_Case position, int nlig, int ncol, T_Tab_Case* vois) {                 //////| Fonction qui construit la liste des cases voisines d'une case à partir du position :
    vois->nb = 0;                                                                          //| Initialisation : nombre de voisins trouvés = 0
//                                                                                         //|
//                                                                                         //| Verification et ajout d'une case:
//                                                                                         //|
    if (position.col + 1 <= ncol) {                                                        //| si case est dans la grille
        vois->tab[vois->nb].lig = position.lig;                                            //| ligne reste inchangée
        vois->tab[vois->nb].col = position.col + 1;                                        //| -> Colonne décalée de +1
        vois->nb++;                                                                        //| -> Incrémente le compteur de voisins  de +1
    }                                                                                      //|
//                                                                                         //|
    if (position.col + 2 <= ncol) {                                                        //| si  case est dans la grille
        vois->tab[vois->nb].lig = position.lig;                                            //| ligne reste inchangée
        vois->tab[vois->nb].col = position.col + 2;                                        //| -> Colonne décalée de +2
        vois->nb++;                                                                        //| -> Incrémente le compteur de voisins  de +1
    }                                                                                      //|
//                                                                                         //|
    if (position.lig + 1 <= nlig) {                                                        //| si la case est dans la grille
        vois->tab[vois->nb].lig = position.lig + 1;                                        //| -> Ligne décalée de +1
        vois->tab[vois->nb].col = position.col;                                            //| Colonne reste inchangée
        vois->nb++;                                                                        //| -> Incrémente le compteur de voisins  de +1
    }                                                                                      //|
//                                                                                         //|
//                                                                                         //|
    if (position.lig + 2 <= nlig) {                                                        //| si la case est dans la grille
        vois->tab[vois->nb].lig = position.lig + 2;                                        //| -> Ligne décalée de +2
        vois->tab[vois->nb].col = position.col;                                            //| Colonne reste inchangée
        vois->nb++;                                                                        //| -> Incrémente le compteur de voisins  de +1
    }                                                                                      //|
}                                                                                      //////|

////////////////////////////////////////
//// 5. Calcul du nimber d'une case ////
////////////////////////////////////////

//                                                                                        ||||| Calcul des nimbers ||||||
//                                                                          //////|
static int nimber[VMAX+1][VMAX+1];                                              //| Tableau global pour | stockage des nimbers
//                                                                              //|
void CalculNimbers(int nlig, int ncol) {                                        //| Fonction pour construire les nimbers de toutes les cases :
//                                                                              //|
    for (int i = 1; i <= nlig; i++) {                                           //| Pour chaque ligne
        for (int j = 1; j <= ncol; j++) {                                       //| Pour chaque colonne
            nimber[i][j] = -1;                                                  //| --> Nimber=-1, Non calculé
        }                                                                       //|
    }                                                                           //|
    for (int col = ncol; col >= 1; col--) {                                     //| Pour chaque colonne, de droite à gauche
        for (int lig = nlig; lig >= 1; lig--) {                                 //| Pour chaque ligne de bas en haut
            if (lig == nlig && col == ncol) {                                   //| - Si (lig, col) est le coin inferieur droit
                nimber[lig][col] = 0;                                           //|   --> Nimber=0, Puits
            } else {                                                            //| -Sinon
                T_Case cCour = {lig, col};                                      //|  -Case courante
                T_Tab_Case v;                                                   //|  -Tableau de voisins
                Voisines(cCour, nlig, ncol, &v);                                //|  -Construit la liste des voisines
                int toutesV1 = 1;                                               //|  -Initialisation : si toutes les voisines ont nimber=1, alors nimber=0
//                                                                              //|
                for (int k = 0; k < v.nb; k++) {                                //|  -Pour chaque voisine
                    int nl = v.tab[k].lig;                                      //|  -int nl = Ligne de la voisine
                    int nc = v.tab[k].col;                                      //|  -int nc = Colonne de la voisine
                    if (nimber[nl][nc] == 0) {                                  //|  - Si la voisine a nimber=0
                        toutesV1 = 0;                                           //|      --> Toutes les voisines n'ont pas nimber=1
                        break;                                                  //|
                    }                                                           //|
                }                                                               //|
                nimber[lig][col] = toutesV1 ? 0 : 1;                            //|  -Nimber=0 si toutes les voisines ont nimber=1, sinon nimber=1
            }                                                                   //|
        }                                                                       //|
    }                                                                           //|
}                                                                          ///////|

//                                                                              //|
int NimberCase(int lig, int col) {                                              //| Une fonction pour lire le nimber d'une case :
    return nimber[lig][col];                                                    //| où la fonction retourne le nimber de la case (lig, col)
}                                                                               //|    grace a la fonction "CalculNimbers"

//////////////////////////////////////////////
//// 6. Affichage de la grille en texte   ////
//////////////////////////////////////////////

void Affiche_Bordure(int ncol);                                                       //| Fonction pour afficher la bordure verticale

void Affiche_Grille(T_Case position, int nlig, int ncol) {                            //| Fonction pour afficher la grille en texte :
    printf("\n   ");
    for (int j = 1; j <= ncol; j++) {                                               ///////|
        printf("\033[34m %2d \033[0m", j);                                               //|  Affichage des numéros de colonnes
    }                                                                               ///////|          en bleu
    printf("\n");

    Affiche_Bordure(ncol);                                                               //| On affiche la bordure verticale

//                                                                        //| Affiche chaque ligne de la grille avec les bordures verticales :
    for (int i = 1; i <= nlig; i++) {                                                             //| Pour chaque ligne
        printf("\033[34m%2d\033[0m |", i);                                                        //| Numéro de ligne en bleu

        for (int j = 1; j <= ncol; j++) {                                                         //| Affichage de chaque cellule de la ligne :

            if (i == position.lig && j == position.col && i == nlig && j == ncol) {            /////|   Si la case correspond à la position du pion et au puits
                printf(" \033[38;5;208m🔴\033[0m |");                                             //|    --> Affichage l'emoji du puits
            }                                                                                  /////|

            else if (i == position.lig && j == position.col) {                                 /////|   Si la case correspond à la position du pion
                printf(" \033[38;5;208m♟\033[0m |");                                              //|    --> Affichage de l'emoji du pion
            }                                                                                  /////|

            else if (i == nlig && j == ncol) {                                                 /////|   Si la case correspond au puits
                printf(" 🚩|");                                                                   //|    --> Affichage de l'emoji du puits
            }                                                                                  /////|

            else {                                                                             /////|   Si la case n'est ni la position du pion ni le puits
                printf(" - |");                                                                   //|    --> Affichage un tiret
            }                                                                                  /////|
        }
        printf("\n");

        Affiche_Bordure(ncol);                                          // Affichage des bordures verticales
    }
    printf("\n");
}

void Affiche_Bordure(int ncol) {                            /////|
    printf("   +");                                            //|
    for (int j = 1; j <= ncol; j++) {                          //|
        printf("---+");                                        //|        Personalisation des bordures de la grille
    }                                                          //|
    printf("\n");                                              //|
}                                                           /////|

////////////////////////////////////////////////
//// 7. Coups de l'ordinateur et du joueur  ////
////////////////////////////////////////////////

//                                                                              /////////|
void Coup_Joueur(T_Case* position, int nlig, int ncol) {                               //| Fonction pour jouer un coup :
    T_Tab_Case v;                                                                      //| Tableau de cases voisines
    Voisines(*position, nlig, ncol, &v);                                               //| Construit la liste des voisins
//                                                                                     //|
    printf("\033[33mA toi de jouer ! Choisis ta destination :\033[0m\n");              //| Jaune
    for (int i = 0; i < v.nb; i++) {                                                   //| Parcourt la liste des voisins
        printf("\033[35m%d:(%d,%d)\033[0m\n", i+1, v.tab[i].lig, v.tab[i].col);        //| Magenta avec nouvelle ligne
        if (i < v.nb - 1) {                                                            //| Ajoute une ligne de séparation sauf après la dernière option
            printf("---------\n");                                                     //| Ligne de délimitation
        }                                                                              //|
    }                                                                                  //|
    printf("---> ");                                                                   //| Affiche le prompt
//                                                                                     //|
    int choix;                                                                         //| Choix du joueur
    while (1) {                                                                        //| Boucle infinie
        choix = Lire_Entier("", 1, v.nb);                                              //| Passe une chaîne vide car le prompt est déjà affiché
        if (choix >= 1 && choix <= v.nb) {                                             //| Si le choix est valide
            *position = v.tab[choix-1];                                                //| Mettre a jour la position du joueur
            break;                                                                     //| Sortir de la boucle
        } else {                                                                       //|
//                                                                                     //| Ce cas ne devrait pas arriver grâce à la fonction "Lire_Entier", mais on l'ajoute par sécurité
printf("\033[31mErreur ! Veuillez choisir une option valide.\033[0m\n---> ");          //| Message de resaisir, en rouge
        }                                                                              //|
    }                                                                                  //|
}                                                                              //////////|

int Hasard(int min, int max) {                                                    //| Initialise la fonction Hasard pour choisir un coup au hasard
    return rand() % (max - min + 1) + min;                                        //| renvoie un entier au hasard entre min et max inclus
}

//                                                                        //////////| Fonction pour choisir un coup au hasard :
void Coup_Ordi_Hasard(T_Case* position, int nlig, int ncol) {                     //|
    T_Tab_Case v;                                                                 //| Tableau de voisins
    Voisines(*position, nlig, ncol, &v);                                          //| Construit la liste des voisins
    if (v.nb == 0) {                                                              //| Si aucun voisin, ne fait rien
        return;                                                                   //|
    }                                                                             //|
    int r = Hasard(1, v.nb);                                                      //| Choisit un coup au hasard (1 à v.nb)
    *position = v.tab[r - 1];                                                     //| Déplace le pion
    printf("\033[36mL'ordinateur joue et place le pion en (%d,%d)\033[0m\n",      //| Affiche où l'ordinateur s'est déplacé en cyan
           position->lig, position->col);                                         //| Affiche la position du pion
}                                                                         //////////|

//                                                                        //////////| Fonction pour choisir un coup gagnant :
void Coup_Ordi_Gagnant(T_Case* position, int nlig, int ncol) {                    //|
    T_Tab_Case v;                                                                 //| Tableau de voisins
    Voisines(*position, nlig, ncol, &v);                                          //| Construit la liste des voisins
//                                                                                //|
    for (int i = 0; i < v.nb; i++) {                                              //| Parcourt la liste des voisins
        int n = NimberCase(v.tab[i].lig, v.tab[i].col);                           //|  -Obtient le nimber de la case voisine
        if (n == 0) {                                                             //|  -Si le nimber est 0
            *position = v.tab[i];                                                 //|     -->Déplace le pion vers cette case
printf("\033[36mL'ordinateur joue et place le pion en (%d,%d)\033[0m\n",          //| Affiche le déplacement
                position->lig, position->col);                                    //|
            return;                                                               //|
        }                                                                         //|
    }                                                                             //|
    Coup_Ordi_Hasard(position, nlig, ncol);                                       //| Appelle la fonction de coup aléatoire
}                                                                         //////////|

///////////////////////////////////////
//// 8. Fonction principale (main) ////
///////////////////////////////////////

int main(void){                                                             //| Fonction principale du programme ( main )
    srand((unsigned int)time(NULL));                                        //| Initialisation du hasard

    int nlig, ncol, niveau, next;                                           //| Paramètres du jeu
    Parametres(&nlig, &ncol, &niveau, &next);                               //| Saisie des paramètres du jeu

    CalculNimbers(nlig, ncol);                                              //| Appel de la fonction "Calcul des nimbers"

    T_Case position;                                                        //| Position du pion :
    position.lig = 1;                                                       //| Position  du pion : ligne 1, colonne 1
    position.col = 1;                                                       //|

printf("==================================================================\n");                    //|
printf("======================\033[36m La partie COMMENCE ! \033[0m======================\n");     //| Message de commencement du jeu
printf("==================================================================\n");                    //|
printf("====================\033[36m Que le meilleur gagne ! \033[0m===================== !\n");   //|
printf("==================================================================\n");                    //|

    Affiche_Grille(position, nlig, ncol);                                     // Affichage initial de la grille //

    int fini = 0;                                                               //| Initialisation de la variable pour la fin de la partie
    int joueurActuel = next;                                                    //| Initialisation de la variable pour le joueur actuel (1=ordinateur, 2=joueur)

    while (!fini) {                                                      /////////| Boucle de jeu tant que la partie n'est pas finie
        if (joueurActuel == 2) {                                                //| Si le joueur actuel est le joueur
            Coup_Joueur(&position, nlig, ncol);                                 //|      -> fonction "Coup_Joueur", pour jouer un coup
        } else {                                                                //| Sinon
            double r = rand() / (double)RAND_MAX;                               //|      -> Initialisation du nombre aléatoire
//                                                                              //| Application des probabilités selon le niveau choisi :
            switch(niveau) {                                                    //|
                case 1:                                                         //| -- Niveau 1 : toujours hasard --
                    Coup_Ordi_Hasard(&position, nlig, ncol);                    //|      -> fonction "Coup_Ordi_Hasard", jouer un coup au hasard
                    break;                                                      //|
                case 2:                                                         //| -- Niveau 2 : 2/3 hasard, 1/3 gagnant --
                    if (r < 2.0/3.0) {                                          //| Si le nombre aléatoire est inférieur à 2/3
                        Coup_Ordi_Hasard(&position, nlig, ncol);                //|      -> fonction "Coup_Ordi_Hasard", pour jouer un coup au hasard
                    } else {                                                    //| Sinon
                        Coup_Ordi_Gagnant(&position, nlig, ncol);               //|      -> fonction "Coup_Ordi_Gagnant", pour jouer un coup gagnant
                    }                                                           //|
                    break;                                                      //|
                case 3:                                                         //| -- Niveau 3 : 1/3 hasard, 2/3 gagnant --
                    if (r < 1.0/3.0) {                                          //| Si nombre aléatoire est inférieur à 1/3
                        Coup_Ordi_Hasard(&position, nlig, ncol);                //|      -> fonction "Coup_Ordi_Hasard", jouer un coup au hasard
                    } else {                                                    //| Sinon
                        Coup_Ordi_Gagnant(&position, nlig, ncol);               //|      -> fonction "Coup_Ordi_Gagnant", jouer un coup gagnant
                    }                                                           //|
                    break;                                                      //|
                case 4:                                                         //|
                default:                                                        //| -- Niveau 4 : toujours gagnant --
                Coup_Ordi_Gagnant(&position, nlig, ncol);                       //|      -> fonction "Coup_Ordi_Gagnant", jouer un coup gagnant
                    break;                                               /////////|
            }
        }

        Affiche_Grille(position, nlig, ncol);                                   //| Affichage de la grille après le mouvement

        if (position.lig == nlig && position.col == ncol) {                  /////| ON verifie, Si le pion est arrivé au puits
            fini = 1;                                                           //|
            break;                                                          //////| Sortir de la boucle
        }

        if (joueurActuel == 1) {                                              ////| si l'ordinateur a joué ( joueurActuel == 1)
            joueurActuel = 2;                                                   //|   -> Passe au joueur suivant, ( joueurActuel = 2 )
        } else {                                                                //| Sinon
            joueurActuel = 1;                                                 ////|   -> Passe au joueur suivant, ( joueurActuel = 1 )
        }
    }

//                                        || Affichage final des messages de fin de partie ||
    if (joueurActuel == 1) {                                                                        ///////|  Si le joueur actuel est l'ordinateur
//                                                                                                       //|
        printf("===================================================================\n");                 //|
        printf("===================== La partie est TERMINEE ! ====================\n");                 //|   -> Message de fin de partie
        printf("===================================================================\n");                 //|       en Rouge
        printf("\033[31m=== L'ordinateur a gagné. C'est une défaite pour toi, Dommage ! ===\033[0m\n");    //|
        printf("===================================================================\n");                 //|
        printf("===================== Ressaye une autre fois ! ====================\n");                 //|
        printf("===================================================================\n");                 //|
//                                                                                                       //|
    } else {                                                                                             //|   Sinon (joueurActuel == 2)
//                                                                                                       //|
        printf("====================================================================\n");                //|
        printf("===================== La partie est TERMINEE ! =====================\n");                //|   -> Message de fin de partie
        printf("====================================================================\n");                //|       en Vert
        printf("\033[32m== 👏 Bravo 👏. Tu as réussi à gagner le jeu contre l'ordinateur ==\033[0m\n");  //|
        printf("====================================================================\n");                //|
    }                                                                                               ///////|
    return 0;
}                                                                                                        //| Fin de la fonction principale
//                                                                                                       //| et Fin du programme
