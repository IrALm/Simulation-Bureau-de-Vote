
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef ELECTION_HPP
#define ELECTION_HPP
#include <unordered_map>
#include <vector>
#include "Candidat.hpp"
#include <set>

namespace elections{

  /* classe Election
     Une élection a un nom et est constitué par des candidats   
  */

class Election {

        /* Méthodes */

        public : 
                /*
                  Rôle : constructeur de la classe 
                  Préconditions : Aucune mis à part que les paramètres en entrés sont bien declarés
                  Entrées : string nom , unordored_set<int> nb , vector<Personne*>vp
                  Sortie : les attributs ont été initialisés
                  Coût : linéaire en taille de nb( contient les indices des candidats )       
                */

                Election( const std::string& nom , const std::set<Personne*, Personne::CompAlpha>& nb ,  const std::vector<Personne*>& vp );

                /*
                  Rôle : affiche les informations rélatives à une élection  
                  Préconditions : Aucune
                  Entrées :Aucune
                  Sortie : affichage 
                  Cout : linéaire en taille de liste_candidat        
                */

                void affiche() const ;

                /* 
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : retourne le nom de l'élection
                  Coût : constant          
                */

                std::string nom_elect()const ;

              
                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : retourne la liste des candidats
                  Coût : constant       
                */

                std::unordered_map<int , Candidat*> get_listecandidat() const ;
                
                /*
                   rôle : accesseur 
                   retourne le nombre des candidats
                   coût : O(1)
                */
                int getNbCandidat()const;
                /* 
                  Déstructeur de la classe
                  coût : O(n) où n est la taille de la liste des candidats
                */

                ~Election();
        /* Attributs */
        
        private : 
                std::string nom_election;
                static int nb_Candidat ;
                std::unordered_map< int , Candidat*> liste_candidat ;
                
};

}
#endif
