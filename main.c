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
