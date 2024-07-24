
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef SALLE_HPP
#define SALLE_HPP
#include "Electeur.hpp"
namespace elections {

    /* classe salle 
       Une salle d'un bureau de Vote contient une durée , un etat (libre ou occupé) ainsi qu'un pointeur vers un Electeur
    */

class Salle {

        public : 
                /*
                  Rôle : constructeur de la classe  
                  Préconditions : duree > 0
                  Entrées : int duree
                  Sortie : les attributs ont été initialisés
                  Coût : constant         
                */

                Salle ( int duree );

                /*
                  Rôle : permet de faire entrer un électeur dans la salle
                  Préconditions :pers != nullptr
                  Entrées : un pointeur vers Electeur pers
                  Sortie : l'attribut pers_ != nullptr et etat = false ( occupé )
                  Coût : constant          
                */

                void entrer( Electeur*  pers);

                /* 
                  Rôle : permet de faire sortir un électeur dans la salle
                  Préconditions : pers != nullptr 
                  Entrées :un pointeur vers Electeur pers
                  Sortie : renvoie un pointeur vers Electeur
                  Coût : constant          
                */

                Electeur * sortir ( Electeur *pers );

                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie la durée
                  Coût : constant          
                */

                int get_duree() const ;

                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie l'état de la salle
                  Coût : constant          
                */

                bool get_etat() const ;

                /*
                  Rôle : accesseur
                  Préconditions : aucune
                  Entrées : aucune
                  Sortie : renvoie pers
                  Coût : constant          
                */

                Electeur* get_pers() const ; 

                /*
                  Rôle : decrémente le temps de l'électeur dans la salle 
                  Préconditions : t == 1
                  Entrées : int t
                  Sortie : temps decremnté
                  Coût : constant          
                */

                void decr_dPers(int t);

        private : 
                int duree_ ;  
                Electeur *pers_ ;
                bool etat ; 
    } ;

}

#endif
