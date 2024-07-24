
/*
    Fait par AGANZE LWABOSHI Moise et Robin NTWARI
*/

#include "Isoloir.hpp"
#include "BulletinVote.hpp"
#include "Election.hpp"
#include <cstddef>
#include <random>
#include <cmath>
#include <algorithm>
#include <vector>

namespace elections {

    /* Constructeur de la classe
       coût temporel : constant
    */
    Isoloir::Isoloir(int duree, int i)
             :Salle(duree), num_isl(i) {
    }

    /* acceseur retournant le numéro de l'isoloir 
       coût : constant
    */
    int Isoloir::get_num() const { 
        return num_isl;
    }

    /* vérifie si res est compris entre [ -3 , 0 ] ou [ 0 , 3 ]
       coût temporel : constant
    */
    bool verif(int res) {
        return (res <= 3);
    }

    

    double Isoloir::rendreBulletinNul(){
        // Créer un générateur de nombres aléatoires
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribution uniforme entre 0 et 1

        // Générer un nombre aléatoire entre 0 et 1
        double resultat = dis(gen);
        return resultat ;
    } 

    /* Méthode pour faire une vérification final du choix de l'électeur 
       On sait qu'il a une probabilité de 15 % de rendre un bulletin nul
       Du coup, il faut tester cette probabilité
       Coût temporel : O(n) où n est la taille de la liste_choix de l'électeur
    */
    void Isoloir::verif_final(Electeur* el) {
            
            BulletinVote* bv = nullptr;
            BulletinVote* bvb = nullptr;
            double nul = rendreBulletinNul();
            if ( nul < Pn ){
                auto bn = new BulletinNul( el->get_liste_choix()[1]->get_candidat() , "***");
                el->faire_choix(bn);
            }
            else{
                int min = 4 ;
                for( auto it : el->get_liste_choix()){
                    if( it->get_candidat() != nullptr){
                        int di = std::abs(el->spol() - it->get_candidat()->spol());
                        if( verif(di)){
                            if( di < min ){
                                min = di ;
                                bv = it ;
                            }
                        }
                    } else{ bvb = it ;}
                }
            }
            if( bv != nullptr){
                el->faire_choix(bv);
            }
            else{
                if( bvb != nullptr){
                    el->faire_choix(bvb);
                }
                else{
                    auto bn = new BulletinNul( el->get_liste_choix()[1]->get_candidat() , "****");
                    el->faire_choix(bn);
                }
            }
        
    }

    /* Méthode d'affichage du choix dans l'isoloir
       coût temporel : constant  
    */
    void Isoloir::aff_vote(Electeur* el) const {
        auto msg = el->get_chType();
        
        if (msg != " BLANC " && msg != " NUL ") {
            std::cout << std::endl << "  " << el->id() + 1 << " choisi  " << el->get_choix();
        } else if (msg == " NUL ") {
            std::cout << std::endl << "  " << el->id() + 1 << " choisi  " << el->get_chType();
        } else {
            std::cout << std::endl << "  " << el->id() + 1 << " choisi  " << el->get_chType();
        }
    }

} // namespace elections
