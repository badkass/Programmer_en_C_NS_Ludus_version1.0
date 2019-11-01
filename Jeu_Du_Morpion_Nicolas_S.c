#include <stdio.h>

// Signes des joueurs
const char signe1='X';
const char signe2='O';

//Fonctions
void initGrille(char grille[3][3]);
void printGrille(char grille[3][3]);
void initJoueur(char joueur[2][50], char signe[2]);
int checkGame(char grille[3][3]);
char fillGrille(int currentPlayer, char grille[3][3], char joueur[2][50], char signe[2]);

//Fonction principale
int main()
{
	//Déclaration
    char grille[3][3];
	char joueur[2][50]; //numéro du joueur et son nom
	char signe[2]; //signe1 et signe2
	int currentPlayer; //0 = joueur1 / 1 = joueur2
	int tour; //Compteur du nombre de tour

	//Initialisation
	currentPlayer=0; //Le joueur 1 commence
	tour=0;//Le nombre de tour est initialisé à 0
    initGrille(grille);
    initJoueur(joueur, signe);
	printf("\n");

	//Traitement
	do {
		tour++;
		if (tour==10) //On sort de la boucle si toutes les cases sont remplies
		{
			break;
		}
		printGrille(grille);
		fillGrille(currentPlayer, grille, joueur, signe); //Remplissage de la grille
		if(currentPlayer==0)
		{
			currentPlayer=1;
		}
		else if(currentPlayer==1)
		{
			currentPlayer=0;
		}
		checkGame(grille); //Verifie si un joueur a gagné
	    printf("\n");
	} while((checkGame(grille)!=1)&&(checkGame(grille)!=2));

	//Conclusion
	printGrille(grille); //Affiche la grille finale
	if ((checkGame(grille)==1)||(checkGame(grille)==2)) //si un joueur gagne
	{
		printf("La partie est finie, %s gagne. Appuyer sur Entrer.\n", joueur[checkGame(grille)-1]);
	}
	else if (checkGame(grille)==3) //si il y à égalité
	{
		printf("La partie est finie, personne ne gagne. Appuyer sur Entrer.\n");
	}
    return 0;
}

//Initialisation de la grille
void initGrille(char grille[3][3])
{
	int i;  // Lignes
	int j;  // Colonnes
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			grille[i][j]='_';
		}
	}
}

//Affichage de la grille
void printGrille(char grille[3][3])
{
	int i;  // Lignes
	int j;  // Colonnes
	printf("  1 2 3 \n");
	for(i=0; i<3; i++)
	{
		printf("%i ", i+1);
	    for(j=0; j<3; j++)
	    {
			printf("%c ", grille[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
}

//Initialisation des joueurs
void initJoueur(char joueur[2][50], char signe[2])
{

	printf("Le joueur 1 va commencer la partie.\n");
    printf("Joueur 1, veuillez entrez votre nom :\n");
    scanf("%s",&joueur[0][0]);
    signe[0]=signe1;
    while(getchar()!='\n');

    printf("Joueur 2, veuillez entrez votre nom :\n");
    scanf("%s",&joueur[1][0]);
    signe[1]=signe2;
    while(getchar()!='\n');

    printf("Joueur 1 est %s et joue avec %c \n", joueur[0], signe[0]);
    printf("Joueur 2 est %s et joue avec %c \n", joueur[1], signe[1]);
}

//Vérification de l'avancement de la partie et de la victoire
int checkGame(char grille[3][3])
{
	int i;  // Lignes
	int j;  // Colonnes
	int verifResult;

	//Verification pour une égalité en fin de partie
	verifResult=3;

	//Vérification des résultat du signe 1
	if( ((grille[0][0]==signe1)&&(grille[0][1]==signe1)&&(grille[0][2]==signe1))/*correspond à la ligne 1*/||
	((grille[1][0]==signe1)&&(grille[1][1]==signe1)&&(grille[1][2]==signe1))/*correspond à la ligne 2*/||
	((grille[2][0]==signe1)&&(grille[2][1]==signe1)&&(grille[2][2]==signe1))/*correspond à la ligne 3*/||
	((grille[0][0]==signe1)&&(grille[1][0]==signe1)&&(grille[2][0]==signe1))/*correspond à la colonne 1*/||
	((grille[0][1]==signe1)&&(grille[1][1]==signe1)&&(grille[2][1]==signe1))/*correspond à la colonne 2*/||
	((grille[0][2]==signe1)&&(grille[1][2]==signe1)&&(grille[2][2]==signe1))/*correspond à la colonne 3*/||
	((grille[0][0]==signe1)&&(grille[1][1]==signe1)&&(grille[2][2]==signe1))/*correspond à la diagonale 1*/||
	((grille[0][2]==signe1)&&(grille[1][1]==signe1)&&(grille[2][0]==signe1))/*correspond à la diagonale 2*/)
	{
		verifResult=1;
	}

	//Vérification des résultats pour le signe 2
	if( ((grille[0][0]==signe2)&&(grille[0][1]==signe2)&&(grille[0][2]==signe2))/*correspond à la ligne 1*/||
	((grille[1][0]==signe2)&&(grille[1][1]==signe2)&&(grille[1][2]==signe2))/*correspond à la ligne 2*/||
	((grille[2][0]==signe2)&&(grille[2][1]==signe2)&&(grille[2][2]==signe2))/*correspond à la ligne 3*/||
	((grille[0][0]==signe2)&&(grille[1][0]==signe2)&&(grille[2][0]==signe2))/*correspond à la colonne 1*/||
	((grille[0][1]==signe2)&&(grille[1][1]==signe2)&&(grille[2][1]==signe2))/*correspond à la colonne 2*/||
	((grille[0][2]==signe2)&&(grille[1][2]==signe2)&&(grille[2][2]==signe2))/*correspond à la colonne 3*/||
	((grille[0][0]==signe2)&&(grille[1][1]==signe2)&&(grille[2][2]==signe2))/*correspond à la diagonale 1*/||
	((grille[0][2]==signe2)&&(grille[1][1]==signe2)&&(grille[2][0]==signe2))/*correspond à la diagonale 2*/)
	{
	    verifResult=2;
	}

	return verifResult;
}

//Remplissage de la grille
char fillGrille(int currentPlayer, char grille[3][3], char joueur[2][50], char signe[2])
{
    int colonne;
	int ligne;
    printf("%s, veuillez saisir la colonne et la ligne.\n", joueur[currentPlayer]);
	do {
		do{
			scanf("%d",&colonne);
			if (colonne<1 || colonne>3)
			{
				printf("Valeur incorrect. Veuillez rentrer une autre valeur de colonne (valeur entre 1 et 3).\n");
			}
		} while(colonne<1 || colonne>3);

		do{
			scanf("%d",&ligne);
			if (ligne<1 || ligne>3)
			{
				printf("Valeur incorrect. Veuillez rentrer une autre valeur de ligne (valeur entre 1 et 3).\n");
			}
		} while(ligne<1 || ligne>3);

		if(grille[ligne-1][colonne-1]!='_')
		{
			printf("La case est occupee. Veuillez rentrer une autre valeur de colonne et de ligne.\n");
		}
	} while(grille[ligne-1][colonne-1]!='_');
	grille[ligne-1][colonne-1]=signe[currentPlayer];
}
