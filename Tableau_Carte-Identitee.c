#define TAILLENOM 100
#define TAILLEPRENOM 100
#define TAILLEADRESSE 255
#define TAILLEECP 10
#define TAILLEVILLE 100
#define TAILLECONTINUE 100


//Les tableaux

int main()
{
    /*int nTabInteger[TAILLE];
    float fitTabFloat[TAILLE];
    double dblTabDouble(TAILLE];
    cTabCar[nI]='\()'; //'\()' caractere de fin de la chaine */

//TD carte identitée

    static int nID=0;
    char cNom[TAILLENOM];
    char cPrenom[TAILLEPRENOM];
    char cAdresse[TAILLEADRESSE];
    char cCP[TAILLEECP];
    char cVille[TAILLEVILLE];


    const char FinDeSaisie='o';
    char cContinue[TAILLECONTINUE];

    do(


        pritnf("Programme Carte identite\n");
        printf("Saisir Nom\n");
        fgets(cNOM,TAILLENOM, stdin);
        fflush(sdtin);
        printf("Saisir Prenom\n");
        fgets(cPrenom,TAILLEPRENOM, stdin);
        fflush(sdtin);
        printf("Saisir Adresse\n");
        fgets(cAdresse,TAILLEADRESSE, stdin);
        fflush(sdtin);
        printf("Saisir Code postal\n");
        fgets(cCP,TAILLECP, stdin);
        scanf("%5s",cCP);
        fflush(sdtin);
        printf("Saisir Ville\n");
        fgets(cVille,TAILLEVILLE, stdin);
        ++nID;

        //Affichage

        printf("Id : %d\n", nID);
        printf("Nom : %d\n", cNom);
        printf("Prenom : %d\n", cPrenom);
        printf("Adresse : %d\n", cAdresse);
        printf("CP : %d\n", cCP);
        printf("Ville : %d\n", cVille);

        do(
            printf("Saisir une autre carte o/n ?\n");
            scanf("%s",cContinue);
            fflush(stdin);
        )while(strcmp(cContinue,"o")&& strcmp(cContinue,"n"));


        )while(cContinue[0]==cFinDeSaisi);




        return 0;
}



