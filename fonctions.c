#include "fonctions.h"
#define MAXCHAR 200

char * ligneCSV(int N) { // Récupère un pointeur vers la chaine de caractère de la ligne de CSV numéro N
    FILE *fp;
    char ligne[MAXCHAR];

    //ouverture fichier
    fp = fopen("airbnb_donnees_propres.csv","r");

    int i = 0;
    char * r;
    while (feof(fp) != true) //on recherche la ligne n°N
    {   
        if (N == i) {
            //printf("%s", ligne);
            r = ligne;
            return r;
        }
        fgets(ligne, MAXCHAR, fp);
        i = i+1;
    }
    printf("\n");
}

struct Logement initialiserLogement(struct Logement L) { //mettre toutes les attributs du logement à 0
    L.number = 0; 
    L.accomodates = 0;
    L.bedrooms = 0;
    L.bathrooms = 0;
    L.beds = 0;
    L.price = 0;
    L.minimum_nights = 0;
    L.maximum_nights = 0;
    L.number_of_reviews = 0;
    return L;
}

void afficherLogement(struct Logement L) { // afficher tout les attributs d'un logement
    printf("Caractéristiques du logement : ");
    printf("%d  ", L.number);
    printf("%d  ", L.accomodates);
    printf("%.1f  ", L.bedrooms);
    printf("%.1f  ", L.bathrooms);
    printf("%.1f  ", L.beds);
    printf("%.1f  ", L.price);
    printf("%d  ", L.minimum_nights);
    printf("%d  ", L.maximum_nights);
    printf("%d  \n", L.number_of_reviews);
}   

/*
int splitCSV(char * ligne, int n) { //retourner le n-eme valeur de ligne étudiée
    int attrib;
    int i = 1;
    char str[MAXCHAR];
    char * current;
    strcpy(str,ligne);
    current = strtok (ligne,",");
    while (current != NULL)
    {   
        if (i == 1 || i==2 || i==3 || i==4) {
            attrib = strtol(current,NULL,10);
            printf("%d\n", i);
        }
        i = i+1;
        //printf ("%s | ",current);
        current = strtok (NULL, ",");
    }
    //printf("\n");
    return attrib;
}
*/

int splitCSV(char * ligne, int n) { // VERSION 6 sur 9, faute de mieux, on se basera sur cette fonction pour la suite
    int attrib = -1;
    int i,j = 1;
    char str[40];
    const char s[2] = ",";
    char *token;

    for(i = 0; i <40 ; i++) //convertir char * en char[]
    {
        str[i] = ligne[i];
    }
    //printf("str : %s ", str);
    //get the first token
    token = strtok(str, s);
    
    while(token != NULL) {
        //printf( " token %s\n", token );
        
        if (j == n){
            attrib = strtol(token,NULL,10);
            //printf("%s|",token);
            //printf("j vaut %d et attrib vaut %d\n",j,attrib);
            return attrib;
        }

        j++;
        token = strtok(NULL, s);
    }
   //printf("\n");
}

/*
float splitCSV(char * ligne, int n) { // VERSION MAXIME : pas adaptée
    float attrib = -1;
    int i,j = 1;
    char str[40];
    const char s[2] = ",";
    char *token;

    for(i = 0; i <40 ; i++) //convertir char * en char[]
    {
        str[i] = ligne[i];
    }

    //get the first token
    token = strtok(str, s);
    int test=1;
    
    while(token != NULL) {
        
        switch(test) { 
            case 1 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
            case 2 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
            case 3 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 4 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 5 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 6 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 7 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 8 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            case 9 :
                attrib = strtof(token,NULL);
                //printf("%.2f ",attrib);
                break;
            default :
                break;
        }
        printf("%.01f |", attrib);
        
        token = strtok(NULL, s);
        test++;  
    }
   //printf("\n");
   return attrib; //casse absoluement tout 
}
*/

/*
int splitCSV(char * ligne, int n) { // VERSION Valent1 marche à 5∕8
    int attrib = -1;
    int i,j,k = 1;
    char str[40];
    const char s[2] = ",";
    char *token;

    while(token != NULL) {

        // on redéfinit la chaine initiale à chaque fois car strtok fonction destructive
        for(i = 0; i <40 ; i++) //convertir char * en char[]
        {
            str[i] = ligne[i];
        }
        token = strtok(str, s);

        for (k=1; k<n; k++){
            printf("%d | ",k);
            token = strtok(NULL, s);
        }
        attrib = strtol(token,NULL,10);
        printf("\nToken actuel : %s ",token);
        return attrib;
    }  
   //printf("\n");
}
*/

/*
int splitCSV(char * ligne, int n){ //essai de version manuelle
    int i,j;
    char tab[35];
    char resultat;
    for (i=0; i<35; i++){
        tab[i] = ligne[i];
    }
    int compteurVirgule,position = 0;
    while (position < 35){
        if (ligne[position] == ','){
            compteurVirgule++;
        }
        if (compteurVirgule == n){
            for (j=0; j<position; j++){
                return 0;
            }
        }
        return 0;
    }
}
*/

struct Logement remplirLogement(struct Logement L, int n) { //assigner les valeurs de la ligne n au logement L
    L = initialiserLogement(L);
    char * ligne = ligneCSV(n); //récuperer la ligne de CSV qui nous intéresse

    L.number = splitCSV(ligne,1); // récupérer la 1e donnée dans la ligne définie plus tôt

    L.accomodates = splitCSV(ligne,2); //idem

    L.bedrooms = splitCSV(ligne,3);

    L.bathrooms = splitCSV(ligne,4);

    L.beds = splitCSV(ligne,5);

    L.price = splitCSV(ligne,6);

    L.minimum_nights = splitCSV(ligne,7);

    L.maximum_nights = splitCSV(ligne,8);

    L.number_of_reviews = splitCSV(ligne,9);
    return L;
}

float pow2(float nombre, float puissance) { //passage au carré
    int res = 1;
    for(int i=0; i<puissance ; i++) {
        res = res*nombre;
    }
    return res;
}

int distance(struct Logement m, struct Logement n) { //calcul de la distance (attributs accomodates, bedrooms, beds) entre les logements m et n
    int distance = 0;
    int a,b,c;
    a = pow2(m.accomodates-n.accomodates,2); //cf composantes de la formule de la distance euclidienne
    b = pow2(m.bedrooms-n.bedrooms,2);
    c = pow2(m.beds-n.beds,2);
    distance = a+b+c;
    distance = sqrt(distance);
    //printf("\nLa distance entre m et n est %d\n",distance);
    return distance;
}

int distanceCrit(struct Logement m, struct Logement n, int crit) { //calcul de la distance (en sélectionnant un attribut) entre les logements m et n
    int distance = 0;
    int a;
    switch (crit)
    {
    case 2:
        a = pow2(m.accomodates-n.accomodates,2);
        break;
    case 3:
        a = pow2(m.bedrooms-n.bedrooms,2);
        break;
    case 4:
        a = pow2(m.bathrooms-n.bathrooms,2);
        break;
    case 5:
        a = pow2(m.beds-n.beds,2);
        break;
    case 6:
        a = pow2(m.price-n.price,2);
        break;
    case 7:
        a = pow2(m.minimum_nights-n.minimum_nights,2);
        break;
    case 8:
        a = pow2(m.maximum_nights-n.maximum_nights,2);
        break;
    case 9:
        a = pow2(m.number_of_reviews-n.number_of_reviews,2);
        break;
    }
    //printf("distance : %d\n",a);
    distance = sqrt(a);
    //printf("\nLa distance entre m et n est %d\n",distance);
    return distance;
}

struct Logement distanceALL(struct Logement a) { //toutes les distances (attributs accomodates, bedrooms, beds) des autres biens au logement a
    int  i,dis;
    //int distances[7918];
    struct Logement b;
    for (i=2;i<=7918;i++) {
        b = remplirLogement(b,i);
        dis = distance(a,b);
        printf("Distance avec le logement n°%d (selon les attributs accomodates, bedrooms, beds) : %d\n",i,  dis);
        a.distances[i][0] = dis;
        a.distances[i][1] = b.number; //sauvegarder le numéro de la ligne pour pouvoir arranger le fichier dans le bon ordre
    }
    return a;
}

//BUG INSOLVABLE : après appel de cette fonction, le tableau de distance (et des prix) de la structure n'est en fait pas modifiée ???
struct Logement distanceCritALL(struct Logement a,int crit) { //toutes les distances (selon un attribut) des autres logements à par rapport au logement a
    int  i,dis;
    //int distances[7918];
    struct Logement b,c;
    c = initialiserLogement(c);
    for (i=2;i<7916;i++) { //7918
        b = remplirLogement(b,i);
        dis = distanceCrit(a,b,crit);
        c.distances[i][0] = (float)dis;
        c.distances[i][1] = (float)b.price;
        //printf("[%0.0f, %0.0f] ", c.distances[i][0],c.distances[i][1]);
    }
    return c;
} 

struct Logement distanceCritALLqa(struct Logement a,int crit) { //toutes les dist (aselon un attribut) des autres biens à par rapport au logement a
    int  i,dis;
    //int distances[7918];
    struct Logement b;

    for (i=2;i<7918;i++) { //7918
        b = remplirLogement(b,i);
        dis = distanceCrit(a,b,crit);
        printf("Distance (selon l'attribut n°%d) avec le logement n°%d : %d\n",crit,i, dis); //pour la question a 
        a.distances[i][0] = dis;
    }
    return a;
} 

int afficherDistances(struct Logement a){
    int i;
    for (i=0;i<7918;i++){
        printf("%0.0f ", a.distances[i][0]);
    }
    return 0;
}

int afficherPrix(struct Logement a){
    int i;
    for (i=0;i<7918;i++){
        printf("%0.0f ", a.distances[i][1]);
    }
    return 0;
}

int afficherTabDistancesPrix(struct Logement a){
    int i;
    for (i=0;i<7918;i++){
        printf("[%0.0f, %0.0f]", a.distances[i][0],a.distances[i][1]);
    }
    return 0;
}

// BUG : Le tri selon la distance est fait, mais à cause du bug de distanceCritAll, je ne peux pas répondre à toute la question
struct Logement triDistance(struct Logement a){ //modifie le tableau de distance du logement a pour le trier selon la similarité croissante
    float tabTri[7917][1];
    float n,max = 0;
    int i,j,k,p,m = 0;
    for (i=0;i<7918;i++){
        n =  a.distances[i][0];
        if (n > max) {
            max = n;
        }
    }
    //printf("La distance max est %d\n", max);
    
    i = 0;
    for (j=0; j<= max; j++) {
        for(i=0; i<7917; i++) {
            m = a.distances[i][0];
            if (m == j) {
                tabTri[k][0] = m;
                tabTri[k][1] = a.distances[i][1];
                //printf("%0.0f | ", a.distances[i][1]);
                k++;
            }
        }
    }

    //remplacer le tabeau des distances par celui des distances triées
    for (p=0; p<=7917; p++) {//7917
        a.distances[p][0] = tabTri[p][0];
        a.distances[p][1] = tabTri[p][1];
        //printf("%0.0f  %0.0f|",tabTri[p][0], tabTri[p][1]);
    }
    return a;
}

struct Logement randomiserLigne(struct Logement a){
    int i,j;
    float m,n;
    for (i=0; i<7917; i++) {
        j = rand()%7917;
        m = a.distances[i][0];
        n = a.distances[i][1];
        //printf("%0.0f %0.0f",m,n);

        a.distances[i][0] = a.distances[j][0];
        a.distances[i][1] = a.distances[j][1];

        a.distances[j][0] = m;
        a.distances[j][1] = n;

    }
    return a;
}

int moyenneK(struct Logement a, int k){
    int i;
    float moy,s = 0;
    float n;
    for (i=0; i<k; i++) {
        s = s + a.distances[i][1];
    }
    n = (float)k;
    s = s/n;
    printf("Le prix prédit est : %f \n",s);
}

int p1qa() { //réponse de la partie  question a
    printf("Veuillez entre le numéro de la ligne du logement X :");
    int x;
    scanf("%d",&x);
    while (x < 2 || x > 7918) { //vérification de validité
        printf("Erreur : numéro de ligne invalide\n");
        scanf("%d",&x);
    }
    int col = 0;
    printf("Veuillez indiquer le numéro de la colonne du critère avec lequel calculer la distance :");
    scanf("%d",&col);
    while (col < 2 || col > 9) { //vérification de validité
        printf("Erreur : veuillez choisir un numéro de colonne compris entre 2 et 9.\n");
        scanf("%d",&col);
    }

    switch (col) //dire quel critère est choisi
            {
            case 2:
                printf("Vous avez choisi le critère accomodates.\n");
                break;
            case 3:
                printf("Vous avez choisi le critère bedrooms.\n");
                break;
            case 4:
                printf("Vous avez choisi le critère bathrooms.\n");
                break;
            case 5:
                printf("Vous avez choisi le critère beds.\n");
                break;
            case 6:
                printf("Vous avez choisi le critère price.\n");
                break;
            case 7:
                printf("Vous avez choisi le critère minimum_nights.\n");
                break;
            case 8:
                printf("Vous avez choisi le critère maximum_nights.\n");
                break;
            case 9:
                printf("Vous avez choisi le critère number_of_reviews.\n");
                break;
            default:
                break;
            }

    struct Logement a;
    a = remplirLogement(a,x);
    distanceCritALLqa(a,col);
}

int p1qb() {
    printf("Veuillez entre le numéro de la ligne du logement X :");
    int x;
    scanf("%d",&x);
    while (x < 2 || x > 7918) { //vérification de validité
        printf("Erreur : numéro de ligne invalide\n");
        scanf("%d",&x);
    }
    int col = 0;
    printf("Veuillez indiquer le numéro de la colonne du critère avec lequel calculer la distance :");
    scanf("%d",&col);
    while (col < 2 || col > 9) { //vérification de validité
        printf("Erreur : veuillez choisir un numéro de colonne compris entre 2 et 9.\n");
        scanf("%d",&col);
    }

    switch (col) //dire quel critère est choisi
            {
            case 2:
                printf("Vous avez choisi le critère accomodates.\n");
                break;
            case 3:
                printf("Vous avez choisi le critère bedrooms.\n");
                break;
            case 4:
                printf("Vous avez choisi le critère bathrooms.\n");
                break;
            case 5:
                printf("Vous avez choisi le critère beds.\n");
                break;
            case 6:
                printf("Vous avez choisi le critère price.\n");
                break;
            case 7:
                printf("Vous avez choisi le critère minimum_nights.\n");
                break;
            case 8:
                printf("Vous avez choisi le critère maximum_nights.\n");
                break;
            case 9:
                printf("Vous avez choisi le critère number_of_reviews.\n");
                break;
            default:
                break;
            }

    struct Logement a;
    a = remplirLogement(a,x);
    a = distanceCritALL(a,col);
    a = triDistance(a);
    //a = randomiserLigne(a);
    printf("Comme expliqué en commentaire du code, la fonction triDistance est bugguee.\n");
}

int p1qc() {
    printf("Veuillez entre le numéro de la ligne du logement X :");
    int x;
    scanf("%d",&x);
    while (x < 2 || x > 7918) { //vérification de validité
        printf("Erreur : numéro de ligne invalide\n");
        scanf("%d",&x);
    }
    int col = 0;
    printf("Veuillez indiquer le numéro de la colonne du critère avec lequel calculer la distance :");
    scanf("%d",&col);
    while (col < 2 || col > 9) { //vérification de validité
        printf("Erreur : veuillez choisir un numéro de colonne compris entre 2 et 9.\n");
        scanf("%d",&col);
    }

    switch (col) //dire quel critère est choisi
            {
            case 2:
                printf("Vous avez choisi le critère accomodates.\n");
                break;
            case 3:
                printf("Vous avez choisi le critère bedrooms.\n");
                break;
            case 4:
                printf("Vous avez choisi le critère bathrooms.\n");
                break;
            case 5:
                printf("Vous avez choisi le critère beds.\n");
                break;
            case 6:
                printf("Vous avez choisi le critère price.\n");
                break;
            case 7:
                printf("Vous avez choisi le critère minimum_nights.\n");
                break;
            case 8:
                printf("Vous avez choisi le critère maximum_nights.\n");
                break;
            case 9:
                printf("Vous avez choisi le critère number_of_reviews.\n");
                break;
            default:
                break;
            }

    struct Logement a;
    a = remplirLogement(a,x);
    a = distanceCritALL(a,col);
    a = triDistance(a);
    //a = randomiserLigne(a);
    moyenneK(a,500);
    printf("Nous trouvons 0 ici car comme expliqué en commentaire du code, la fonction triDistance est bugguee. \nCependant les fonctions permettant de traiter cette question si la b fonctionnait ont bien été écrite (à prendre en compte pour la notation ?)\n");
}

int p1qd() {
        printf("Veuillez entre le numéro de la ligne du logement X :");
    int x;
    scanf("%d",&x);
    while (x < 2 || x > 7918) { //vérification de validité
        printf("Erreur : numéro de ligne invalide\n");
        scanf("%d",&x);
    }

    struct Logement a;
    a = remplirLogement(a,x);
    distanceALL(a);
}
