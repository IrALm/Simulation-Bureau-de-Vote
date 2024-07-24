
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#include "Election.hpp"

namespace elections{

    /* Constructeur de la classe
       coût : linéaire en taille de nb
    */

    Election::Election( const std::string& nom , const std::set<Personne*, Personne::CompAlpha>& nb ,  const std::vector<Personne*>& vp)
            :nom_election( nom ){
            int i = 0 ;
            for(auto it : nb ){
                Candidat * cd = new Candidat( it->nom() , it->prenom() , it->id() , it->spol() , i);
                liste_candidat.insert({i,cd});
                i++ ;
            }
    }

    /* 2 accesseurs : le premier retourne le nom de l'élection 
                      et le second le nombre des candidats
       coût : constant  
    */

    std::string Election::nom_elect()const { 
        return nom_election ;
    }
    int Election::getNbCandidat()const{
        return nb_Candidat;
    }

    /* Permet d'afficher les informations rélatves à une élection 
       Coût : linéaire en taille de liste_candidat
    */

    void Election::affiche() const {

        std::cout << std::endl << std::endl << "Election  " << nom_election << std::endl ;
        for( auto it : liste_candidat){

            std::cout << "Candidat n° " << it.first << " : " << *it.second << std::endl ;
        }
    }

    /* accesseur : retourne la liste des candidats
       coût : constant  
    */
    
    std::unordered_map<int , Candidat*>  Election::get_listecandidat() const{ return liste_candidat;}

    /* 
        Déstructeur de la classe
        coût : O(n) où n est la taille de la liste des candidats
    */
    
    Election::~Election(){
        for( auto it : liste_candidat)
            delete it.second ;
    }
    
}
