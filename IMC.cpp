/* 
	
	But: Générer un IMC à partir du poids et de la taille
	Dernier mise a jour: 2024/02/06
*/

#include <stdio.h>
#include <ctype.h>

int main () {

char reponse;
	
	do{
		// Déclaration des variables 
		float poids; // Le pois est en kg
		float taille; // La taille est en metre	
		float imc; 
		
		// Saisie de données tapées au clavier 
		printf("Tapez le poids : ");
		scanf("%f", &poids);
		printf("Tapez la taille : ");
		scanf("%f", &taille);
		
		// À calculer
		imc = poids / (taille * taille);	
		
		//Affichage de ces informations 
		printf("poids: %.1f, taille: %.2f, imc: %.1f\n", poids, taille, imc);
		 
		// L'interpretation des résultats du imc
	 	if(imc<18.5)
	 		printf("MAIGREUR, RISQUE ELEVE A ACCRU\n");
	 	else if (imc<25)
	 		printf("POIDS NORMAL, RISQUE FAIBLE\n");
	 	else if(imc<30)
	 		printf("EMBONPOINT, RISQUE ELEVE\n");
	 	else if(imc>30)
	 		printf("OBESITE, RISQUE TRES ELEVE\n");
	 	
		// Demander à l'utilisateur s'il veut refaire l'action
		printf("Voulez-vous entrer les informations d'un autre patient ? (O/N) :\n ");
		scanf(" %c", &reponse); 
	} while (toupper(reponse) == 'O');  // Continuer le loop si la response est 'O' ou 'o'
	return 0;
}

/*Execution
Tapez le poids : 51
Tapez la taille : 1.98
poids: 51.0, taille: 1.98, imc: 13.0
MAIGREUR, RISQUE ELEVE A ACCRU
Voulez-vous entrer les informations d'un autre patient ? (O/N) :
 o
Tapez le poids : 69.4
Tapez la taille : 1.63
poids: 69.4, taille: 1.63, imc: 26.1
EMBONPOINT, RISQUE ELEVE
Voulez-vous entrer les informations d'un autre patient ? (O/N) :
 O
Tapez le poids : 60
Tapez la taille : 1.65
poids: 60.0, taille: 1.65, imc: 22.0
POIDS NORMAL, RISQUE FAIBLE
Voulez-vous entrer les informations d'un autre patient ? (O/N) :
 o
Tapez le poids : 100
Tapez la taille : 1.72
poids: 100.0, taille: 1.72, imc: 33.8
OBESITE, RISQUE TRES ELEVE
Voulez-vous entrer les informations d'un autre patient ? (O/N) :
*/
