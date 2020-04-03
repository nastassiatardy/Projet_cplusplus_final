#ifndef DEF_TODOLIST
#define DEF_TODOLIST

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tache.h"

class Todolist
{
    public:

    Todolist();
    Todolist(int monId, std::string monTitre, std::vector<Tache> myTasks);
    ~Todolist();
    void sauvegardeTodo() const;
    void ajouterTache(Tache myTask);
    void retirerTache(std::string monTitre);
    void ajouterCommentaire_(std::string monTitre, std::string monCommentaire);
    void ajouterSousTache_(std::string monTitre, std::string maSousTache);
    void changerStatut_(std::string monTitre, std::string monStatut);
    void afficherTache(std::string maPriorite) const;

    protected:

    int m_idTodo;
    std::string m_titreTodo;
    std::vector<Tache> m_taches;
    int m_nbTaches;

};

#endif