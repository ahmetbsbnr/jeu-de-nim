# 📘 Documentation du Jeu de Nim

> Auteur : **Ahmet BASBUNAR**  
> Date : **Janvier 2025**

---

## 📌 Aperçu

Ce projet est une implémentation du **jeu du Nim** en langage C. Il propose une expérience utilisateur enrichie grâce à :

- Une interface console avec couleurs ANSI et emojis
- Un algorithme de stratégie basé sur les **nimbers**
- Quatre niveaux de difficulté progressifs

---

## 🧠 Fonctions Principales

| Fonction                  | Rôle                                                                 
|--------------------------|----------------------------------------------------------------------
| `Lire_Entier`            | Lire un entier entre deux bornes                                    
| `Parametres`             | Lire et initialiser les paramètres du jeu                           
| `Voisines`               | Générer la liste des cases voisines d'une case                      
| `Hasard`                 | Générer un déplacement aléatoire                                     
| `Nimber`                 | Calculer le nimber d’une case                                        
| `Coup_Joueur`            | Permet au joueur de choisir un déplacement                          
| `Coup_Ordi_Hasard`       | Coup aléatoire pour l’ordinateur                                     
| `Coup_Ordi_Gagnant`      | Coup optimal selon la stratégie gagnante                            
| `Affiche_Grille`         | Affichage de la grille de jeu                                       
| `main`                   | Lancement et orchestration du jeu                                   

---

## ⚙️ Niveaux de Difficulté

| Niveau  | Description                                                                 
|---------|-----------------------------------------------------------------------------
| 1       | L'ordinateur joue toujours au hasard                                        
| 2       | 2/3 hasard, 1/3 stratégie                                                    
| 3       | 2/3 stratégie, 1/3 hasard                                                    
| 4       | L'ordinateur joue toujours de manière optimale                              

---

## 🎨 Interface et Esthétique

### Couleurs ANSI utilisées

| Couleur ANSI     | Utilisation                             
|------------------|------------------------------------------
| `\033[31m`       | Rouge – Messages d'erreur               
| `\033[32m`       | Vert – Messages de succès               
| `\033[33m`       | Jaune – Prompts utilisateur             
| `\033[34m`       | Bleu – Titres                           
| `\033[35m`       | Magenta – Choix du joueur              
| `\033[36m`       | Cyan – Messages système/infos créateur  
| `\033[0m`        | Reset – Réinitialisation des couleurs   

### Symboles utilisés

| Symbole | Signification          
|---------|------------------------
| ♟       | Pion                   
| 🚩      | Puits (objectif final) 
| 🔴      | Fin de partie          
| `-`     | Case vide              

---

## 🧪 Avertissements

- ⚠️ **Le programme peut contenir des bugs non détectés.**
- ⚙️ **Certaines fonctions peuvent être optimisées** pour améliorer les performances.
- Le programme est documenté, mais des commentaires supplémentaires peuvent être ajoutés pour un usage plus collaboratif.

---

## 🧾 Visualisation

### Exemple de grille initiale (5x5) :

```
1   2   3   4   5
+---+---+---+---+---+
| ♟ | - | - | - | - |
+---+---+---+---+---+
| - | - | - | - | - |
+---+---+---+---+---+
| - | - | - | - | - |
+---+---+---+---+---+
| - | - | - | - | - |
+---+---+---+---+---+
| - | - | - | - | 🚩|
+---+---+---+---+---+
```

### Tableau des nimbers correspondant :

```
1   2   3   4   5
+---+---+---+---+---+
| 0 | 1 | 1 | 0 | 1 |
+---+---+---+---+---+
| 1 | 0 | 1 | 1 | 0 |
+---+---+---+---+---+
| 1 | 1 | 0 | 1 | 1 |
+---+---+---+---+---+
| 0 | 1 | 1 | 0 | 1 |
+---+---+---+---+---+
| 1 | 0 | 1 | 1 | 0 |
+---+---+---+---+---+
```

---

## 🔗 Dépôt GitHub

Retrouvez le projet complet sur GitHub :  
📎 [https://github.com/ahmetbsbnr/jeu-de-nim](https://github.com/ahmetbsbnr/jeu-de-nim)
