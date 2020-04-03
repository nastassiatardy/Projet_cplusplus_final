#include "Todolist.h"

using namespace std;

Todolist::Todolist(){}

Todolist::Todolist(int monId, string monTitre, vector<Tache> myTasks)
{
    m_idTodo = monId;
    m_titreTodo = monTitre;
    m_taches = myTasks;
    m_nbTaches = myTasks.size();
}

Todolist::~Todolist() 
{
    // vide car on n'utilise pas de pointeur
}

void Todolist::sauvegardeTodo() const
{
    string const nomFichier("Todolist_" + to_string(m_idTodo) + ".txt");
    ofstream monFlux(nomFichier.c_str());
    if (monFlux)
    {
        monFlux << "SAUVEGARDE DE LA TODOLIST " << m_idTodo << endl;
        monFlux << " " << endl;
        monFlux << "Nombre de tâches : " << m_nbTaches << endl;
        monFlux << "Liste des tâches : " << endl;
        if (m_taches.size() > 0)
        {
            for (int i(0); i < m_taches.size(); i++)
            {
                monFlux << "    Tâche " << m_taches[i].getId() << " : " << m_taches[i].getTitre() << endl;
            }
        }
        else
        {
            monFlux << "    Il n'y a encore aucune tâche."<<endl;
        }
    }

    // sauvegarde des tâches de la todolist
    for (int i(0); i < m_nbTaches; i++)
    {
        m_taches[i].sauvegarde();
    }
}

void Todolist::ajouterTache(Tache myTask)
{
    m_taches.push_back(myTask);
    m_nbTaches += 1;
}

void Todolist::retirerTache(string monTitre)
{
    if (m_nbTaches > 0)
    {
        for (int i(0); i < m_nbTaches; i++)
        {
            if (m_taches[i].getTitre()==monTitre)
            {
                m_taches.erase(m_taches.begin() + i);
                m_nbTaches -= 1;
                break;
            }
        }
    }
}

void Todolist::ajouterCommentaire_(string monTitre, string monCommentaire)
{
    bool y(false);
    for (int i(0); i<m_nbTaches; i++)
    {
        if (m_taches[i].getTitre()==monTitre)
        {
            m_taches[i].ajouterCommentaire(monCommentaire);
            y = true;
            break;
        }
    }
    if (not y)
    {
        cout << "Une erreur s'est produite. Le commentaire n'a pas pu être ajouté." << endl;
        cout << "Vérifiez le titre de la tâche." << endl;
    }
}

void Todolist::ajouterSousTache_(string monTitre, string maSousTache)
{
    bool y(false);
    for (int i(0); i<m_nbTaches; i++)
    {
        if (m_taches[i].getTitre()==monTitre)
        {
            m_taches[i].ajouterSousTache(maSousTache);
            y = true;
            break;
        }
    }
    if (not y)
    {
        cout << "Une erreur s'est produite. La sous-tâche n'a pas pu être ajoutée." << endl;
        cout << "Vérifiez le titre de la tâche." << endl;
    }
}

void Todolist::changerStatut_(string monTitre, string monStatut)
{
    bool y(false);
    for (int i(0); i<m_nbTaches; i++)
    {
        if (m_taches[i].getTitre()==monTitre)
        {
            m_taches[i].changerStatut(monStatut);
            y = true;
            break;
        }
    }
    if (not y)
    {
        cout << "Une erreur s'est produite. Le statut n'a pas pu être modifié." << endl;
        cout << "Vérifiez le titre de la tâche." << endl;
    }
}

void Todolist::afficherTache(string maPriorite) const
{
    cout << "Voici la liste des tâches de priorité : " << maPriorite << endl;
    for (int i(0); i < m_nbTaches; i++)
    {
        if (m_taches[i].getPriorite()==maPriorite)
        {
            cout << m_taches[i].getTitre() << endl;
        }
    }
}