#include "fonctions.c"

int main() {

    // Menu de selection de la partie du projet
    char choixSousPartie[1];
    struct Logement a;

        printf("A quelle question de ce sujet voulez vous acceder ?\n");
        scanf("%s",choixSousPartie);
        while (choixSousPartie[0] != 'a' && choixSousPartie[0] != 'b' && choixSousPartie[0] != 'c' && choixSousPartie[0] != 'd' && choixSousPartie[0] != 'e') {
            printf("Erreur : veuillez choisir une lettre en a,b,c,d et e.\n");
            scanf("%s",choixSousPartie);
        }
        
        switch (*choixSousPartie)
        {

        case 'a':
            printf("Vous avez choisi la question a.\n");
            p1qa();
            break;
        case 'b':
            printf("Vous avez choisi la question b.\n");
            p1qb();
            break;
        case 'c':
            printf("Vous avez choisi la question c.\n");
            p1qc();
            break;
        case 'd':
            printf("Vous avez choisi la question d.\n");
            p1qd();
            break;
        }
    return 0;
}

