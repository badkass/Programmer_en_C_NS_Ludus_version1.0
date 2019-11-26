#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define OK 1


int menu();
void jeu();


void initCode(char *codeSecret);
void analyserCombinaison(char *comb, char *rep, char *resultat);
int main ()
{
int continuer = 1, choix = 0;
while (continuer) // Boucle permettant de choisir ce que l'on veut faire dans le programme
{
    choix = menu();
    switch (choix)
    {
        case 1:
            jeu();//lancement du jeu
        break;

        case 2:
            // Quitter
            continuer = 0;
        break;

        default: //si le joueur rentre autre chose que 1 ou 2
            printf("Choix incorrect\n" );
    }

}
return 0;
}

int menu()
{
         int choix = 0;

         system("cls" ); // Nettoyer la console
         printf("      MENU      \n\n" );
         printf("1 : Jouer\n" );
         printf("2 : Quitter\n\n" );
         printf("Que voulez vous faire ?\n\n" );
         scanf("%d", &choix);

         return choix;
}


    void verifierCombi(char *comb, char *rep, char *resultat) //Permet de tester la combinaison entrée par le joueur pour voir si elle est sous la bonne forme, a savoir 4 nombres
    {
    char rep1[4];
    int a;
    for(a=0;a<4;a++)
    {
     rep1[a]=tolower(rep[a]);
     }

    int controle[4] = {0,0,0,0};//sert à vérifier s'il n'y a pas un N à cette position
    int j=0;
    int i;
         for( i = 0;i<4;i++)//Sert à détecter les chiffres bien placés
         {
             if (rep1[i]==comb[i])
             {
              resultat[j] = 'B';
              j++;
              controle[i] = OK;
             }
            else

            for(i = 0;i<4;i++)//Sert à détecter les chiffres mal placés
            {
                 if(controle[i]!=OK)
                 {
                       int k;
                       for(k=0;k<4;k++)
                       {
                               if (rep1[k]==comb[i] && controle[i]!=OK)
                               {
                                resultat[j]= 'N';
                                j++;
                                controle[i] = OK;
                               }

                       }
                 }
         }


  }
    int k;
   for(i = 0;i<4;i++)//Sert à détecter les chiffres non presents dans le code secret
    {
        if (rep1[k]!=comb[i] && controle[i]!=OK)
        {
            resultat[j]='O';
            j++;
        }

    }

}
void initCode(char *codeSecret)
{
int i;
srand (time(NULL));
// initialiser le code secret avec un choix aléatoire de 4 chiffres
for (i = 0; i < 4 ; i++)
{
 switch (rand() % 6)
 {
  case 0: codeSecret[i] = '0'; break;
  case 1: codeSecret[i] = '1'; break;
  case 2: codeSecret[i] = '2'; break;
  case 3: codeSecret[i] = '3'; break;
  case 4: codeSecret[i] = '4'; break;
  case 5: codeSecret[i] = '5'; break;
  case 6: codeSecret[i] = '6'; break;
  case 7: codeSecret[i] = '7'; break;
  case 8: codeSecret[i] = '8'; break;
  case 9: codeSecret[i] = '9'; break;
 }
}
}

    void jeu() //fonction pour le gameplay
    {
        int essais=0,choix=0, ligne=9,continuer=1,verif=0,a;
        char tab[12][8]={ //initialisation du tableau
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46},
                            {42,42,42,42,46,46,46,46}
                        };
        char comb[5];
        initCode(comb);
                system("cls" );

            // mécanique du jeu
            char rep[5]={'\0'};
            while (essais <= 12)//nombre d'essai maximum
            {
                char resultat[4]={46,46,46,46};
                int i, j, t, test=0, L=1, verif=0; // L : numéroter la ligne du tableau à partir de 12.

                int a,b; // variable pour la vérification des combinaisons
                system("cls" );

                printf("\nChiffres disponibles : \n" );
                printf("----------------------------------------\n" );
                printf("- 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 -\n" );
                printf("B = chiffre en bonne position - N = chiffre en mauvaise position - O = chiffre inexistant dans le code secret\n");
                printf("----------------------------------------\n\n" );


                // affichage du tableau
                for (i=0;i<=11;i++)
                {
                    printf ("[%3d]-[",L);
                    for (j=0;j<=7;j++)
                    {
                        printf ("(%c)",tab[i][j]);
                    }
                    printf (" ]\n" );
                    L++;
                }


                // Entrer une combinaison
                while (verif != 4)
                {
                    verif=0;
                    printf("\n\n Essai numero %d: \n",essais);
                    scanf("%s",&rep);
                    fflush(stdin);

                    // vérification de la combinaison entrée
                    for (a=0;a<=3;a++)
                    {
                        if (rep[a]=='0' || rep[a]=='1' || rep[a]=='2' || rep[a]=='3' || rep[a]=='4' ||
                            rep[a]=='5' || rep[a]=='6' || rep[a]=='7' || rep[a]=='8' || rep[a]=='9' )//toutes les possibilité de chiffres que l'utilisateur peut rentrer
                        {
                            verif++;
                        }
                        else
                        {
                            verif--;
                        }
                    }
                    if (verif !=4)
                    {
                        printf("\nCombinaison impossible. Recommencez !" ); //si l'utilisateur rentre moins de 4 chiffres, il y aura ce message,
                        //si l'utilisateur rentre plus de 4 chiffres, le programme prendra en compte uniquement les 4 premiers chiffres
                    }
                }


                verifierCombi(comb,rep,resultat);


                tab[essais][0]=rep[0];
                tab[essais][1]=rep[1];
                tab[essais][2]=rep[2];
                tab[essais][3]=rep[3];
                tab[essais][4]=resultat[0];
                tab[essais][5]=resultat[1];
                tab[essais][6]=resultat[2];
                tab[essais][7]=resultat[3];

              if (resultat[0]=='B' && resultat[1]=='B' && resultat[2]=='B' && resultat[3]=='B')// Si 4 'B' alors le joueur a trouvé le code secret
                {
                   essais=99;
                                     }
                else{
                     essais++;
                }
    }



            // Jeu terminé
            if (essais == 99) // si essais == 99, alors le joueurs a trouvé la combinaison
            {
                printf("Jeu termine" );
                printf("\n\n  FELICITATIONS\n" );
                printf("\n VOUS AVEZ TROUVE LA BONNE COMBINAISON !\n" );
                printf("Entrez 0 pour revenir au menu principal ou 1 pour rejouer : " );
                scanf ("%d",&choix);
            }
            else
            {
                system("cls" );
                printf("GAME OVER !" );
                printf("Entrez 0 pour revenir au menu principal ou 1 pour rejouer : " );
                scanf ("%d",&choix);
            }

        if (choix == 0)
        {
            menu();
        }
        else
        {
            jeu();
        }

}
