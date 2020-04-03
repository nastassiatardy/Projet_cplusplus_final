#ifndef DEF_TACHE
#define DEF_TACHE

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Tache
{
    public:

    Tache();
    // Surcharge du constructeur. On affecte certaines valeurs par défaut.
    Tache(int monId, std::string monTitre, std::string maDescription = "None", std::string maDateCreation = "000000", std::string maDateCloture = "000000", std::string monStatut = "None", double monPourcentage = 0, std::string maPriorite = "None", std::string mesCommentaires = "", std::string mesSousTaches = "");
    ~Tache();
    void sauvegarde() const; //écrit dans un fichier la définition de la tache
    void ajouterCommentaire(std::string monCommentaire);
    void ajouterSousTache(std::string maSousTache);
    void changerStatut(std::string monStatut);
    //changer le pourcentage d'avancement en fonction de la priorité de la tache ? 
    void afficherTacheId(std::string maPriorite) const;
    std::string getTitre() const;
    int getId() const;
    std::string getPriorite() const;


    protected:

    int m_id;
    std::string m_titre;
    std::string m_description;
    std::string m_dateCreation;
    std::string m_dateCloture;
    std::string m_statut;
    double m_pourcentage;
    std::string m_priorite;
    std::string m_commentaires; //c'est une chaîne de caractères qui correspond aux commentaires stockés
    std::string m_sousTaches; //c'est une chaîne de caractères qui correspond aux sous-taches
                              // nécessaires à l'exécution de la tâche courante

};

#endif