/*
    Fait par AGANZE LWABOSHI Moise et Robin NTWARI
*/

#include "EspaceIsoloir.hpp"
#include "Electeur.hpp"
#include "Election.hpp"
#include <algorithm>

namespace elections {

    /*
      constructeur
      coût : linéaire en nb_isoloir
    */
    EspaceIsoloir::EspaceIsoloir(Isoloir* is) {
        int i = 1;

        /* Création des Isoloirs du Bureau */
        for (auto it = 1; i <= nb_isoloir; it++) {
            auto t = new Isoloir(is->get_duree(), i);
            iso_.insert({i , t});
            i++;
        }
    }

    /* Méthode :  me renvoie un Isoloir Vide 
       coût : Dans le pire des cas linéaire en nombre d'Isoloir
    */
    Isoloir* EspaceIsoloir::libre() {

        for( auto it : iso_){
            if( it.second->get_pers() == nullptr ){
                return it.second ;
            }
        }
        return nullptr;
    }

    /* Méthode : renvoie un booléén permettant de savoir s'il y a un électeur 
       dans un isoloir : elle sera utile dans la boucle principale 
       coût : Dans le pire des cas linéaire en nombre d'Isoloir 
    */
    bool EspaceIsoloir::TestIsoloirOccupe() {

        for( auto it : iso_){
            if( it.second->get_pers() != nullptr ){
                return true ;
            }
        }
        return false;
    }

    /* Méthode : décremente le temps de l'électeur se trouvant dans l'isoloir en 
       fonction de l'ncrémentation du temps discret
       coût : linéaire en taille de iso_
    */
    void EspaceIsoloir::decrDIs_Occupe() {
        for (const auto it : iso_) {
            if (it.second->get_pers() != nullptr && it.second->get_pers()->get_dure() > 0)
                it.second->decr_dPers(1);
        }
    }

    /* Méthode : Permet de faire sortir un electeur dans un isoloir
       coût : constant
    */
    Electeur* EspaceIsoloir::faire_sortirIsoloir(Isoloir* it) {
        auto el = it->sortir(it->get_pers());
        return el;
    }

    /* Méthode : recherche les Isoloirs qui sont occupés et fait sortir les 
       electeurs qui s'y trouvent en fonction de leur durée et ajuste les différentes files concernées
       coût : linéaire en nombre d'isoloir
    */
    void EspaceIsoloir::faire_SortirDans_IsoloirOccupe(std::queue<Electeur*>& file_tVote) {
        for (const auto& it : iso_) {
            if (it.second->get_pers() != nullptr && it.second->get_pers()->choix_() != nullptr) {
                auto res = faire_sortirIsoloir(it.second);
                if (res != nullptr) {
                    file_tVote.push(res);
                }
            }
        }
    }

    /* Méthode : permet de faire entrer un électeur dans un isoloir vide 
       coût : constant
    */
    void EspaceIsoloir::faire_entrerIsoloir(std::queue<Electeur*>& file_isoloir) {

        auto is = libre();
        if (is != nullptr) {
            if (!file_isoloir.empty()) {
                if (is->get_pers() == nullptr) {
                    std::cout << std::endl << " ISOLOIR" << std::endl;
                    is->entrer(file_isoloir.front());
                    file_isoloir.pop(); // coût : constant
                }
            }

        }
    }
    /*  Methode : permet de faire son choix au niveau de l'isoloir
        coût : O(n) où n est le nbre d'Isoloir
    */
    void EspaceIsoloir::choisirDansIsoloir(std::queue<Electeur*>& file_tVote, TableVote* tbV) {
        for (const auto& is : iso_) {
            if (is.second->get_pers() != nullptr) {
                if (is.second->get_pers()->get_dure() <= 0 && is.second->get_pers()->choix_() == nullptr) {
                    std::cout << std::endl << " ISOLOIR" << std::endl;
                    is.second->verif_final(is.second->get_pers()); //coût : linéaire en taille de la liste des choix de l'électeur
                    is.second->aff_vote(is.second->get_pers()); //coût : constant
                    std::cout << std::endl;
                    faire_SortirDans_IsoloirOccupe(file_tVote);
                    tbV->faire_entrerTvote(file_tVote);
                }
            }
        }

    }

    /* destructeur de la classe
       coût : linéaire en nb isoloir
    */
    EspaceIsoloir::~EspaceIsoloir() {
        for (auto& it : iso_) {
            delete  it.second;
        }
    }
} // namespace elections
