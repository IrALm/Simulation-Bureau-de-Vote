
/*
    Fait par AGANZE LWABOSHI Moise et Robin NTWARI
*/

#include "Decharge.hpp"
#include "BulletinVote.hpp"
#include <cstddef>
#include <random>
#include <cmath>
#include <algorithm>

namespace elections {

    /* Constructeur de la classe Décharge 
       Complexité temporelle : linéaire en taille de la listeCandidat 
    */
    Decharge::Decharge(int nb_el, int duree, Election* el)
            : Salle(duree) {

        /* ensuite je remplie la liste des Bulletins de vote en fonction 
           de chaque candidat et chaque candidat aura nb_el bulletins de Vote
           où nb_el = nombre d'électeurs inscrits dans le bureau de vote + 
           un lot des bulletins blancs ( nb_el bulletins blancs)
        */
        auto tmp = el->get_listecandidat();
        for( auto it : tmp ){
            auto bv = new BulletinVote( it.second , " NORMAL ");
            auto bvc = new BulletinCandidat( bv , nb_el);
            int cle = bvc->bv->get_candidat()->get_num();
            liste_bulletin.insert({ cle , bvc});
        }
        auto bv = new BulletinVote( nullptr , " BLANC ");
        auto bvb = new BulletinCandidat( bv , nb_el);
        int cle = el->getNbCandidat() + 1 ;
        liste_bulletin.insert({ cle , bvb});
    }

    /* Methode d'affichage du nombre de bulletins de vote attribués à chaque candidat
       Complexité temporelle : linéaire en taille de la listeCandidat  
    */
    void Decharge::affiche_bulletin(Election* el) const {

        auto tmp = el->get_listecandidat();
        std::cout << std::endl << " PREPARATION DECHARGE " << std::endl;
        for (auto it : liste_bulletin) {
            if( it.second->bv->get_candidat() != nullptr){
                std::cout << it.second->bv->get_candidat()->nom() << " " << it.second->bv->get_candidat()->prenom() << " : " << it.second->qte << " bulletins" << std::endl;
            }
        }
    }

    /* Méthode qui me renvoit un nombre aléatoire entre 2 et la taille de liste_bulletin
       coût temporel : constant 
       précondition : b > a 
    */
    int Decharge::nb_alea( int a , int b) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(a , b);
        return dis(gen);
    }

    
    /* 
        Rôle : renvoie un réel entre 0 et 1
        Entrées :aucune
        Sortie : renvoie un réel
        Cout :  constant      
    */

    double Decharge::prendreBulletinblanc(){
        // Créer un générateur de nombres aléatoires
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribution uniforme entre 0 et 1

        // Générer un nombre aléatoire entre 0 et 1
        double resultat = dis(gen);
        return resultat ;
    } 

     /* Méthde permettant de prendre le bulletin d'un candidat
       coût temporel : linéaire en taille de la liste des Candidats
    */
    void Decharge::choisir_bulletin(Electeur* pers, Election* elect) {

        int nb = nb_alea(2, elect->getNbCandidat());
        int i = 1 ;
        int minNum = 0 ;
        int maxNum = elect->getNbCandidat() - 1 ;
        auto copie = liste_bulletin;
        std::vector<BulletinVote*> Bulletin ;
        while ( (i <= nb) || ( (int)Bulletin.size() < nb )){
            int tmp = nb_alea(minNum, maxNum);
            auto it = copie.find(tmp);
            if( it != copie.end()){
                Bulletin.push_back(it->second->bv);
                it->second->qte -- ;
                copie.erase(it);
                
            }
            i++;
        }
        double blanc = prendreBulletinblanc();
        if( blanc < Pb ){
            auto it = liste_bulletin.find(elect->getNbCandidat() + 1 );
            if( it != liste_bulletin.end()){
                Bulletin.push_back(it->second->bv);
                it->second->qte -- ;
            }
        }
        pers->affect_listechoix(Bulletin);

    }

    /* 
      coût : linéaire en taille de la liste des bulletins( <= taille de la liste Candidat)
    */

    void Decharge::affiche_choix(Electeur* pers) {
        auto liste = pers->get_liste_choix();
        int i = 0;
        for (auto it : liste) {
            if (it->get_candidat() == nullptr) {
                std::cout << std::endl << "   " << pers->id() + 1 << " prend " << " Blanc ";
            } else {
                    std::cout << std::endl << "   " << pers->id() + 1 << " prend " << it->get_candidat()->nom() << "  " << it->get_candidat()->prenom();
            }
            i++;
        }
    }

    /* Méthode : permet de faire entrer un électeur  dans la décharge 
       coût : constant
    */
    void Decharge::faire_entrerDecharge(std::queue<Electeur*>& fileD_attente) {
        if (!fileD_attente.empty()) {
            if (get_pers() == nullptr) {
                std::cout << std::endl << " DECHARGE " << std::endl;
                entrer(fileD_attente.front()); // coût : constant
                fileD_attente.pop();

            }
        }

    }

    /* 8 ème Méthode : permet de faire sortir un électeur de la decharge et ajuste les 
       différentes files en conséquences 
       coût : constant
    */

    void Decharge::faire_sortirDecharge(std::queue<Electeur*>& file_isoloir) {
        if (get_pers() != nullptr && get_pers()->get_liste_choix().size() > 0) {
            if (get_pers()->cmpdr())
                std::cout << std::endl << " DECHARGE " << std::endl;
            auto el = sortir(get_pers());
            if (el != nullptr) {
                file_isoloir.push(el);
            }
        }
    }

    /* Méthode : permet de choisir les bulletins de Vote au niveau de la décharge
       Selon les exigences du sujet : un électeur doit choisir au moins 2 candidats différents plus
       un bulletin blanc avec une certaine probabilité ...
       coût : linéaire en taille de la  liste des choix de l'électeur( <= taille de la liste des Candidats)
    */

    void Decharge::choisirDansDecharge(Election* elect_) {

        if (get_pers() != nullptr) {

            if (get_pers()->get_dure() <= 1 && get_pers()->get_liste_choix().size() == 0) {

                std::cout << std::endl << " DECHARGE " << std::endl;
                choisir_bulletin(get_pers(), elect_); // coût : linéaire en nb_alea
                affiche_choix(get_pers());//coût : linéaire en taille de la  liste des choix de l'électeur
                std::cout << std::endl;

            }
        }
    }

    /* Destructeur de la classe Décharge 
       Complexité temporelle : O(n) 
    */
    Decharge::~Decharge() {
        for( auto it : liste_bulletin){
            delete it.second;
        }
    }
} // namespace elections
