---# il ne faut jamais incluire un fichier.h dams le fichier.cpp avant les #include <.....>
ÉVITER LES PROBLÈMES D’INCLUSIONS MULTIPLES
D’INTERFACES  
solution

---#ifndef AH
#define AH 0
... contenu normal de l’interface
#endif
*********************************************
