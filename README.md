# Airbnb
Intitulé : Prédire le prix d’une habitation qu’on veut mettre en  location dans la plateforme Airbnb  
(Projet de Programmation Procédurale ING 1 GI GM 2022-2023)  
__Groupe : BOURGOGNE Matthieu et BRIGITTE Maëva__
 
## Objectif
L'objectif de ce projet est d'implémenter en langage C l'algorithme des K plus proches voisins pour prédire le prix d'un logement X qu'on veut mettre en location.  
  
Pour cela, nous nous baserons sur les attributs de chaque logement et utiliserons la distance euclidienne et une base de donnée de logements, fournie en CSV.  
  
Dans un premier temps, la création d'une structure Logement, incluant les différents champs correspondant aux attributs, permet de calculer les distances de similarité, selon un attribut donné, entre le logement X et chacun des autres.  
  
Nous procédons ensuite au mélange des lignes du fichier CSV, qui correspondent chacune à un logement, avant de les trier par distance de similarité croissante.  

Il ne reste alors plus qu'à sélectionner les K premiers logements après le tri et calculer la moyenne des prix pour ces K logements. Le prix trouvé est le prix prédit pour le logement X.

Nous pouvons finalement entrainer d'autres modèles en prenant en compte d'autres et/ou plus d'attributs.   
  
## Compilation
Une fois dans le dossier du projet, le terminal vous permet d'exécuter les commandes suivantes :  
* make airbnb : compile le projet une première fois et l'excécute
* make run : exécute le projet
* make clean : nettoie le projet  
