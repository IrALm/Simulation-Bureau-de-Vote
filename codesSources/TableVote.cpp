

/*
    Fait par AGANZE LWABOSHI Moise 
*/

#include "TableVote.hpp"
#include "Candidat.hpp"
#include <cstddef>

namespace elections {

    /* Constructeur 
       coût : Linéaire en taille de Vp  
    */
    TableVote::TableVote(int duree, std::set<Personne*, Personne::CompAlpha> nb, const std::vector<Personne*>& vp, Election* el)
        : Salle(duree), nb_nul(0), nb_blanc(0), nbPpr(0) {

        // je recupère la liste des candidats 
        auto tmp = el->get_listecandidat();

        // je remplie la liste d'emargement 
        for (const auto& it : vp) {
            auto itr = nb.find(it);
            if (itr == nb.end()) {
                Emargement* emrg = new Emargement(it->id(), false);
                liste_emargement.insert({it->id() , emrg});
            }
        }

        /* je remplie la liste des voix des candidats , initialement chauqe candidat a 0 voix */
        liste = new Voix[tmp.size()];
        for (size_t i = 0; i < tmp.size(); i++) {
            liste[i] = { (int)i , 0 };
        }
    }

    /* Méthode permettant à l'electeur de confirmer son vote 
       coût : constant 
    */
    void TableVote::voter(Electeur* el , Election* elect) {

        if (el->get_chType() == " BLANC ") {
            nb_blanc++;
            el->set_vote();
        }
        else {
            if (el->get_chType() == " NUL ") {
                nb_nul++;
                el->set_vote();
            }
            else {
                int tmp = el->numeroCandidat();
                auto listeC = elect->get_listecandidat();
                auto itr = listeC.find(tmp);
                if( itr != listeC.end()){
                    itr->second->incrVoix_(1);
                    liste[tmp].voix++;
                    el->set_vote();
                } 
                
            }
        }
        std::cout << std::endl << "  " << el->id() + 1 << " Vote " << std::endl;
    }

    /* méthode permettant de tester si un électeur a dejà voter
       cette méthode sera utile pour la méthode entrer_bureau dans la classe Bureau vote
       coût : constant 
    */
    bool TableVote::TestVote(int id_el) {
        auto it = liste_emargement.find(id_el);
        if (it != liste_emargement.end()) {
            if (it->second->signe == true) {
                std::cout << std::endl << " !!! Vous avez déjà Voter !!! " << std::endl;
                return false;
            }
            else
                return true;
        }
        else {
            std::cout << std::endl << " !!! Vous ne faites pas partie des electeurs de ce Bureau !!! " << std::endl;
            return false;
        }

    }

    /* Méthode permettant à l'électeur de signer dans la liste d'Emargement
       coût : constant 
    */
    void TableVote::signer(Electeur* el) {

        auto it = liste_emargement.find(el->id());
        if (it != liste_emargement.end()) {
            it->second->signe = true;
            nbPpr++;
        }


    }

    /* Les 3 Méthodes ci-dessous sont des accesseurs 
       coût : constant 
    */
    int TableVote::get_nbNul() const {
        return nb_nul;
    }
    int TableVote::get_nbBlanc() const {
        return nb_blanc;
    }
    int TableVote::get_nbPpr() const {
        return nbPpr;
    }

    /*
      coût : constant 
    */
    void TableVote::echanger(int a, int b) {
        Voix tmp = liste[a];
        liste[a] = liste[b];
        liste[b] = tmp;
    }

    /* 
      coût : linéaire en f-d
    */
    int TableVote::partition(int d, int f) {
        int i = d;
        echanger(d, i);
        int pivot = d;
        int val = liste[d].voix;
        for (i = d + 1; i <= f; i++) {
            if (liste[i].voix >= val) {
                pivot = pivot + 1;
                echanger(i, pivot);
            }
        }
        echanger(d, pivot);
        return pivot;
    }

    /*
      coût : quasi-linéaire ( O(nlogn))
    */
    void TableVote::tri_rapide(int d, int f) {
        if (d < f) {
            int pi = partition(d, f);
            tri_rapide(d, pi - 1);
            tri_rapide(pi + 1, f);
        }
    }

    /*
      coût : O(nlog(n))
    */
    void TableVote::affVoixCandidat(Election* el) {
        auto tmp = el->get_listecandidat();
        int f = tmp.size();
        tri_rapide(0, f - 1);
        for( size_t i = 0 ; i < tmp.size(); i++){
            auto itr = tmp.find(liste[i].indice) ;
            if( itr != tmp.end()){
                std::cout<< std::endl << "    " << itr->second->nom() << " " << itr->second->prenom() << " : " << itr->second->voix_()
                        << " ( " << ((float)itr->second->voix_() / nbPpr) * 100 << " %) " ;
            }
        }
        
    }

    /* Méthode : permet de faire entrer un électeur dans la Table de Vote
       coût : constant
    */
    void TableVote::faire_entrerTvote(std::queue<Electeur*>& file_tVote) {
        if (!file_tVote.empty()) {
            if (get_pers() == nullptr) {
                std::cout << std::endl << " VOTE" << std::endl;
                entrer(file_tVote.front());
                file_tVote.pop();

            }
        }
    }
    /* Méthode : Permet de faire sortir un electeur dans une Table de Vote 
       coût : constant
    */

    Electeur* TableVote::faire_sortirTvote() {
        Electeur* el = nullptr;
        if (get_pers() != nullptr && get_pers()->Avoter_()) {
            if (get_pers()->cmpdr())
                std::cout << std::endl << " VOTE" << std::endl;
            el = sortir(get_pers());
            return el;
        }
        else return el;

    }

    /* Methode : permet de Confirmer son vote au niveau de la Table de Vote  et 
       de signer la liste d'emargemnt
       coût : constant  
    */

    void TableVote::choisirDansVote(Election* elect) {
        if (get_pers() != nullptr) {
            if (get_pers()->get_dure() <= 1 && !get_pers()->Avoter_()) {
                std::cout << std::endl << " VOTE" << std::endl;
                voter(get_pers(), elect); //coût : constant
                signer(get_pers()); //coût : constant
                std::cout << std::endl;
            }
        }
    }

    /* Destructeur 
       coût : Linéaire en taille de liste_emargement 
    */
    TableVote::~TableVote() {

        for (auto it : liste_emargement)
            delete it.second;
        delete[] liste;
    }
} // namespace elections
