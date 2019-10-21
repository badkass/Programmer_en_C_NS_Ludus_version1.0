#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5

//Exemple de programme en C

int main()
{

    int i;
    float x;
    float racx;

    printf("Bonjour\n");

    printf("je vais vous calcuer %d racines carrées\n,NFOIS");

    for(i=0;i<NFOIS;i++)
        {
            printf("Donnez un nombre : ");
            scanf("%f",&x);
            if(x<0.0)
                printf("Le nombre %f ne possède pas de racine carrée\n,x");
            else
            {
                racx=sqrt(x);
                printf("Le nombre %f a pour racine carré : %f\n",x,racx);
            }
        }

printf("Travail terminé - Au revoir");

return 0;

}

/*void main() {

int i;
    float x;
    float racx;

    printf("Bonjour\n");

    printf("je vais vous calcuer %d racines carrées\n,NFOIS");

    for(i=0;i<NFOIS;i++)
        {
            printf("Donnez un nombre : ");
            scanf("%f",&x);
            if(x<0.0)
                printf("Le nombre %f ne possède pas de racine carrée\n,x");
            else
            {
                racx=sqrt(x);
                printf("Le nombre %f a pour racine carré : %f\n",x,racx);
            }
        }

printf("Travail terminé - Au revoir");


}*/

/*la compilation consiste a traduire le programme source en executable; en fesant appel a un compilateur

en language C, compte tenue de l'existance dun pré procésseur, cette opération de compilation comporte 2 étapes, la premiere est....
ce dernier execute simplement les directive qui le concerne, elle commence toujours par le caractère dieze, il produit un programme source en language C

la compilation est proprement dit : la traduction du language texte fourni par le pré procésseur en language machine, le résultat de la compilation porte le nom du menu.o
l'édition de lien, le module object n'est pas directement exécutable, il lui manque au moins les différent module coorespondant au fonction prédéfini utilisé par le programmme.
C'est effectivement le role de l'éditeur de lien que d'aller chercher dans la bibliotheque, les modules objet nécéssaires. exécutable : un ensemble autonome d'instruction language machine.
*/
/*Les types de bases en language c :

integer :  short int a;//short
            int b;
            long int c; //long

cela va définir la taille en octet de l'encodage choisjt

    printf("Taille de a : %d", sizeof(a));*/



    #define TAILLE 10


int main() {


    int a=0,b=0,c=0,d=0;

        //Condition

    if(a==b) {
        printf("Ils sont egaux\n");
        } else {
        printf("Ils sont different\n");
        }

    //Condition avec l'opérateur logiques

    if((a==b) && (a==c)) {

        printf("Ils sont tous egaux\n");
        } else {
            printf("Ils sont different\n");
        }



    if((a==b) || (a==c)) {

        printf("Ils sont tous egaux\n");
        } else {
            printf("Ils sont different\n");
        }

        if((a==b) || (a==c)) {

        printf("Ils sont tous egaux\n");
        } else if ((a==c) && (a!=d)) {
            printf("Ils sont different\n");
        }

    //Boucle

    int i=0;

    for(i=0;i<TAILLE;i+=1) {
        printf("Hello world\n");
    }


    //TQ

    i=0;
    while(i<TAILLE) {

        printf("Hello world\n");
        i++;
    }

    //Faire TQ

    i=0;
    do {
        printf("Hello world\n");
        i++;
    }while(i<TAILLE);

    //Cas alternatif de la condition

    int choix=1;

    printf("Veuillez entrer votre choix\n");
    scanf(choix) {
        case 0:printf("Quitter\n");break;
        case 1:printf("Calculer\n");break;
        case 2:printf("Jouer\n");break;
        default :printf("default\n");break;

    }

        //test ? instructions

        a==b? printf("Egaux"): printf("Different");


}









