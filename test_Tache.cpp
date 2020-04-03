#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tache.h"
using namespace std;

int main() 
{
    Tache task1(12, "Faire le projet de C++", "Evaluation qui comptera pour ma note finale !", "290320", "010420", "En progression");
    task1.ajouterCommentaire("Il s'agirait de terminer à l'heure");
    task1.changerStatut("Ouverte");
    task1.ajouterSousTache("créer la classe Tache");
    task1.ajouterSousTache("tester la classe Tache");
    task1.ajouterCommentaire("ne pas oublier de dormir");
    task1.sauvegarde();
    return 0;
}