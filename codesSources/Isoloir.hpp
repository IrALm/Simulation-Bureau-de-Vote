
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP
#include "Salle.hpp"
#include "Election.hpp"
#include "BulletinVote.hpp"

namespace elections {

    /* classe isoloir 
       Un Isoloir est une salle du Bureau de Vote 
       Il contient un numéro , une durée , un état ( occupé ou non ) et un Electeur ( si occupé , on lui passe ses informations)
    */

    class Isoloir : public Salle {

            /* Méthodes */

            public : 
                /*
                  Rôle : constructeur de la classe  
                  Préconditions : Aucune
                  Entrées : 2 entiers : durée et numéro 
                  Sortie : les attributs on été initialisés
                  Cout : constant        
                */

                Isoloir( int duree , int i );

                /*
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie le numérp de l'isoloir
                  Cout : constant        
                */

                int get_num() const ;


                /* 
                  Rôle : permet à l'électeur de confirmer son choix
                  Préconditions : el != nullptr
                  Entrées : Electeur* el , Election* elect , double Pn
                  Sortie : le choix a été fait
                  Cout :  linéaire en taille de la liste des choix de l'electeur       
                */

                void verif_final(Electeur* el );

                /*
                  Rôle : rendre un bulletin nul
                  coût constant
                */

                double rendreBulletinNul();

                /*
                  Rôle : affiche le choix de l'électeur 
                  Préconditions : el != nullptr
                  Entrées : Un pointeur vers Electeur el
                  Sortie : affichage 
                  Cout : constant        
                */

                void aff_vote( Electeur*el) const ;
                
        private :
                int num_isl;
                static double Pn ; // Probabilité de rendre un BulletinNul
    } ;
}
#endif
