	/* Auter: Jully Martins de Araujo 
	Cours: IFT 1810 Section B
	Trimestre: Hiver 2024
	But: TP2 - Les trois types de boucles 
	Dernier mise a jour: 2024/02/16 */
	
#include <stdio.h>

int main() {
    // Déclarations des 3 tableaux
    char poste[] = {'O', 'A', 'P', 'A', 'P', 'P', 'O', 'A'};
    int nbCafe[] = {5, 2, 3, 1, 4, 0, 2, 3};
    int age[] = {29, 18, 36, 24, 65, 43, 51, 22};
    int taille = sizeof(age) / sizeof(age[0]); // Taille des tableaux

    // Affichage du contenu des tableaux au début du programme
    printf("Voici le contenu de ces trois tableaux au debut\n");
    printf("indice    age       nbCafe poste\n");
    for (int i = 0; i < taille; i++) {
        printf("%3d)    %5d     %5d     ", i, age[i], nbCafe[i]);
        switch (poste[i]) {
            case 'A':
                printf("analyste\n");
                break;
            case 'P':
                printf("programmeur\n");
                break;
            case 'O':
                printf("operateur\n");
                break;
            default:
                printf("inconnu\n");
                break;
        }
    }

    // Compter et afficher le nombre de programmeurs
    int nbProgrammeurs = 0;
    for (int i = 0; i < taille; i++) {
        if (poste[i] == 'P') {
            nbProgrammeurs++;
        }
    }
    printf("\nNombre de programmeurs : %d\n", nbProgrammeurs);

    // Compter et afficher le nombre de secrétaires
    int nbSecretaires = 0;
    for (int i = 0; i < taille; i++) {
        if (poste[i] == 'S') {
            nbSecretaires++;
        }
    }
    printf("Nombre de secretaire : %d\n", nbSecretaires);

    // Déterminer et afficher la consommation minimale de café des opérateurs
    int minCafeOperateur = 999; // Initialisation avec une valeur arbitrairement grande
    for (int i = 0; i < taille; i++) {
        if (poste[i] == 'O' && nbCafe[i] < minCafeOperateur) {
            minCafeOperateur = nbCafe[i];
        }
    }
    printf("Consommation minimale de cafe des operateurs : %d\n", minCafeOperateur);

    // Déterminer et afficher l’âge maximal des programmeurs
    int ageMaxProgrammeur = -1; // Initialisation avec une valeur arbitrairement petite
    for (int i = 0; i < taille; i++) {
        if (poste[i] == 'P' && age[i] > ageMaxProgrammeur) {
            ageMaxProgrammeur = age[i];
        }
    }
    printf("Age maximal des programmeurs : %d\n", ageMaxProgrammeur);

    // Calculer et afficher la consommation moyenne de café des analystes
    int sommeCafeAnalyste = 0;
    int nbAnalystes = 0;
    for (int i = 0; i < taille; i++) {
        if (poste[i] == 'A') {
            sommeCafeAnalyste += nbCafe[i];
            nbAnalystes++;
        }
    }
    float moyenneCafeAnalyste = (float)sommeCafeAnalyste / nbAnalystes;
    printf("Consommation moyenne de cafe des analystes : %.2f\n", moyenneCafeAnalyste);

    // Calculer et afficher l’âge moyen de tous les employés
    int sommeAge = 0;
    for (int i = 0; i < taille; i++) {
        sommeAge += age[i];
    }
    float ageMoyen = (float)sommeAge / taille;
    printf("Age moyen de tous les employes : %.2f\n", ageMoyen);

    // Tri par sélection des âges
    for (int i = 0; i < taille - 1; i++) {
        int indexMin = i;
        for (int j = i + 1; j < taille; j++) {
            if (age[j] < age[indexMin]) {
                indexMin = j;
            }
        }
        // Échange des éléments
        int temp = age[indexMin];
        age[indexMin] = age[i];
        age[i] = temp;

        temp = nbCafe[indexMin];
        nbCafe[indexMin] = nbCafe[i];
        nbCafe[i] = temp;

        char tempChar = poste[indexMin];
        poste[indexMin] = poste[i];
        poste[i] = tempChar;
    }

    // Réaffichage des trois tableaux après le tri par sélection
    printf("\nVoici les tableaux apres le tri par selection selon les ages :\n");
    printf("indice    age       nbCafe poste\n");
    for (int i = 0; i < taille; i++) {
        printf("%3d)    %5d     %5d     ", i, age[i], nbCafe[i]);
        switch (poste[i]) {
            case 'A':
                printf("analyste\n");
                break;
            case 'P':
                printf("programmeur\n");
                break;
            case 'O':
                printf("operateur\n");
                break;
            default:
                printf("inconnu\n");
                break;
        }
    }

    return 0;
}

/* Éxecution
Voici le contenu de ces trois tableaux au debut
indice    age       nbCafe poste
  0)       29         5     operateur
  1)       18         2     analyste
  2)       36         3     programmeur
  3)       24         1     analyste
  4)       65         4     programmeur
  5)       43         0     programmeur
  6)       51         2     operateur
  7)       22         3     analyste

Nombre de programmeurs : 3
Nombre de secretaire : 0
Consommation minimale de cafe des operateurs : 2
Age maximal des programmeurs : 65
Consommation moyenne de cafe des analystes : 2.00
Age moyen de tous les employes : 36.00

Voici les tableaux apres le tri par selection selon les ages :
indice    age       nbCafe poste
  0)       18         2     analyste
  1)       22         3     analyste
  2)       24         1     analyste
  3)       29         5     operateur
  4)       36         3     programmeur
  5)       43         0     programmeur
  6)       51         2     operateur
  7)       65         4     programmeur

--------------------------------
*/

