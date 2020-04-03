#include "Tache.h"

using namespace std;

Tache::Tache()
{
    m_id = 0;
    m_titre = "Ma nouvelle tâche";
    m_description = "";
    m_dateCreation = "000000";
    m_dateCloture = "000000";
    m_statut = "";
    m_pourcentage = 0;
    m_priorite = "";
    m_commentaires = "";
    m_sousTaches = "";
}

Tache::Tache(int monId, string monTitre, string maDescription, string maDateCreation, string maDateCloture, string monStatut, double monPourcentage, string maPriorite, string mesCommentaires, string mesSousTaches)
{
    m_id = monId;
    m_titre = monTitre;
    m_description = maDescription;
    m_dateCreation = maDateCreation;
    m_dateCloture = maDateCloture;
    m_statut = monStatut;
    m_pourcentage = monPourcentage;
    m_priorite = maPriorite;
    m_commentaires = mesCommentaires;
    m_sousTaches = mesSousTaches;
}

Tache::~Tache() 
{
    // vide car on n'utilise pas de pointeur
}

void Tache::sauvegarde() const
{
    // on sauvegarde les informations liées à la tâche dans un nouveau fichier
    // le fichier sera stocké dans le répertoire courant

    string const nomFichier("Tâche_" + to_string(m_id) + ".txt");
    ofstream monFlux(nomFichier.c_str());

    if (monFlux)
    {
        monFlux << "SAUVEGARDE DE LA TACHE " << m_id << endl;
        monFlux << " " << endl;
        monFlux << "Identifiant : " << m_id << endl;
        monFlux << "Titre : " << m_titre << endl;
        monFlux << "Description : " << m_description << endl;
        monFlux << "Date de création : " << m_dateCreation << endl;
        monFlux << "Date de clôture : " << m_dateCloture << endl;
        monFlux << "Statut : " << m_statut << endl;
        monFlux << "Pourcentage d'avancement : " << m_pourcentage << " %" << endl;
        monFlux << "Priorité : " << m_priorite << endl;
        monFlux << "Commentaires : " << m_commentaires << endl;
        monFlux << "Sous-tâches nécessaires à l'exécution de la tâche courante : " << m_sousTaches << endl;
        monFlux << " " << endl;
        monFlux << "Cette tâche a été réalisée avec l'application MySuperTodo." << endl;
    }
    else
    {
        cout << "ERREUR : impossible d'ouvrir le fichier." << endl;
    }
}

void Tache::ajouterCommentaire(string monCommentaire)
{
    if (m_commentaires != "")
    {
        m_commentaires += (", " + monCommentaire);
    }
    else
    {
        m_commentaires += monCommentaire;
    }
    
}

void Tache::ajouterSousTache(std::string maSousTache)
{
    if (m_sousTaches != "")
    {
        m_sousTaches += (", " + maSousTache);
    }
    else
    {
        m_sousTaches += maSousTache;
    }
}

void Tache::changerStatut(string monStatut)
{
    m_statut = monStatut;
}

void Tache::afficherTacheId(std::string maPriorite) const
{
    if (m_priorite == maPriorite)
    {
        cout << m_id << endl;
    }
}

string Tache::getTitre() const
{
    return m_titre;
}

int Tache::getId() const
{
    return m_id;
}

string Tache::getPriorite() const
{
    return m_priorite;
}