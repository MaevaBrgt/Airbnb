#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//Structures
struct Logement {
    int number;
    int accomodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;

    float distances[7917][1]; //7918 tableaux de la forme [distance, prix du logement considéré]
};

//Fonctions
char * ligneCSV(int N);
struct Logement initialiserLogement(struct Logement L);
void afficherLogement(struct Logement L);
int splitCSV(char * ligne, int n);
struct Logement remplirLogement(struct Logement L, int n);
float pow2(float nombre, float puissance);
int distance(struct Logement m, struct Logement n);
int distanceCrit(struct Logement m, struct Logement n, int crit);
struct Logement distanceALL(struct Logement a);
struct Logement distanceCritALL(struct Logement a,int crit);
struct Logement distanceCritALLqa(struct Logement a,int crit);
int afficherDistances(struct Logement a);
int afficherPrix(struct Logement a);
int afficherTabDistancesPrix(struct Logement a);
struct Logement triDistance(struct Logement a);
struct Logement randomiserLigne(struct Logement a);
int moyenneK(struct Logement a, int k);
int p1qa();
int p1qb();
int p1qc();
int p1qd();




