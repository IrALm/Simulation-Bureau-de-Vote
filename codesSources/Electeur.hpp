
#ifndef ELECTEUR_HPP
#define ELECTEUR_HPP

#include "BulletinVote.hpp"
#include <vector>
namespace elections {

  /* Classe Electeur 
     un Electeur est une personne qui peut voter 
     Il a donc comme attribut, outre les attributs de personne :
     - une durée de vote , une liste des choix et un choix final 
  */

    class Electeur : public Personne{

            public : 
                /* 
                  Rôle : constructeur de la classe 
                  Préconditions : Aucune. Bien que les paramètres en entrées doivent être bien déclarés
                  Entrées : string nom , prenom , int id , spol
                  Sortie : les attributs sont initialisés
                  Coût : constant          
                */

                Electeur(const std::string& nom, const std::string& prenom, int id , int spol );

                /*
                  Rôle : Ecrire sur un flux de sortie
                  Préconditions : Aucune
                  Entrées : os : un flux de sortie , un Electeur psn 
                  Sortie : retourne le flux os donné en enntrée
                  Coût : constant         
                */

                friend std::ostream& operator<<(std::ostream& os, const Electeur& psn);

                /*
                  Rôle : incrémente la durée de l'électeur dans la Salle où il entre 
                  Préconditions : t > 0 et t == duree dans la salle concernée
                  Entrées : Aucune
                  Sortie : ajoute t à duree_vote
                  Coût : constant          
                */

                void incr_d(int t);

                /*
                  Rôle : decrémente la durée de l'électeur dans la Salle où il est  
                  Préconditions : t == 1
                  Entrées :Aucune
                  Sortie : diminue t à duree_vote
                  Coût : constant          
                */

                void decr_d(int t);

                /*
                  Rôle : retourne la taille de la liste des choix 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie un int qui est la taille recherchée
                  Coût : constant          
                */

                int taille() const ;

                /*
                  Rôle : permet à l'électeur de faire son choix 
                  Préconditions : b!= nullptr
                  Entrées : un pointeur vers BulletinVote b
                  Sortie : l'électeur a choisi le bulletin b
                  Coût : constant          
                */

                void faire_choix(BulletinVote* b );

                /* 
                  Rôle : Permet de vérifier si la durée de 'électeur dans une salle == 0
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie true si duree_vote == 0 , false sinon
                  Coût : constant          
                */

                bool cmpdr() const ;

                /* 
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : revoie liste des choix 
                  Coût : constant          
                */

                std::vector<BulletinVote*> get_liste_choix() ;

                /* 
                  Rôle : renvoie le nom et le prénom du choix fait par l'électeur
                  Préconditions : Aucune
                  Entrées :Aucune
                  Sortie : renvoie le nom et le prénom du choix fait par l'électeur 
                  Coût : constant          
                */

                std::string get_choix() const ;

                /* 
                  Rôle : renvoie le choix fait par l'électeur
                  Préconditions : Aucune
                  Entrées :Aucune
                  Sortie : renvoie le choix fait par l'électeur 
                  Coût : constant          
                */

                BulletinVote* choix_() const ;

                /* 
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : retourne le pointeur vers le candidat choisi par l'électeur
                  Coût : constant          
                */

                Personne * candidat_choisi()const ;

                /* 
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : retourne le booléen  Avoter 
                  Coût : constant          
                */

                bool Avoter_()const ;

                /* 
                  Rôle : Avoter  recoit true
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : Avoter = vrai 
                  Coût : constant          
                */

                void set_vote() ;

                /*
                  Rôle : retourne le type de bulletin que l'électeur a choisi 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie un string
                  Coût : constant          
                */

                std::string get_chType() const ;

                /* 
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie la durée de l'électeur dans une salle
                  Coût : constant          
                */

                int get_dure() const ;

                /*
                  rôle : retourne le numéro du candidat choisi
                  coût : constant
                */

                int numeroCandidat() const ;

                /*
                  rôle : affecter une liste des choix à l'électeur
                  coût: constant O(1) 
                */

                void affect_listechoix( std::vector<BulletinVote*> Bulletin);


        /* Attributs */
          
        private : 
                int duree_vote ;
                BulletinVote* choix ;
                bool Avoter;        
                std::vector<BulletinVote*> liste_choix;

    };
}
#endif