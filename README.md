# Jeu de Nim

Un jeu de Nim dans le terminal, en C, contre l'ordinateur.

## Règles
Un pion part de la case (1, 1) d'une grille `nlig × ncol` (5 à 30). À chaque tour, on le déplace de 1 ou 2 cases vers la droite ou vers le bas. Le joueur qui atteint le puits `(nlig, ncol)` gagne.

L'ordinateur joue selon 4 niveaux (1 : hasard → 4 : stratégie optimale par calcul des *nimbers*).

## Compiler et lancer
```bash
gcc -Wall -o JeuDeNim JeuDeNim.c
./JeuDeNim
```
Fonctionne sous Linux et macOS (couleurs ANSI et emojis dans le terminal).

## Contenu
| Fichier | Rôle |
|---|---|
| `JeuDeNim.c` | Programme complet |
| `DOCUMENTATION.md` | Description détaillée des fonctions et de la stratégie |

## Auteur
Ahmet BASBUNAR
