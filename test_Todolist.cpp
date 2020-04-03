#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Todolist.h"
using namespace std;
 
int main()
{
    vector<Tache> tab;
    Tache Task1(1, "A beautiful mind", "Biographie de Nash");
    Tache Task2(2, "Bohemian rhapsody", "Biographie de Queen", "010420", "020420", "Ouverte", 10, "Urgente");
    tab.push_back(Task1);
    Todolist Todo1(1, "Films à voir", tab);
    Todo1.ajouterTache(Task2);
    Todo1.retirerTache("A beautiful mind");
    Todo1.ajouterCommentaire_("Bohemian rhapsody", "Certains éléments du film sont inexacts");
    Todo1.ajouterSousTache_("Bohemian rhapsody", "Acheter du pop corn");
    Todo1.changerStatut_("Bohemian rhapsody", "En progression");
    Todo1.afficherTache("Urgente");
    Todo1.sauvegardeTodo();

    return 0;
}
