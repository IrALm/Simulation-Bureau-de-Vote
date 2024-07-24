
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef DECHARGE_HPP
#define DECHARGE_HPP

#include "Electeur.hpp"
#include "Salle.hpp"
#include "Election.hpp"
#include "BulletinVote.hpp"
#include <queue>


namespace elections {

   
    /* classe Decharge
       Une Table de Décharge est une salle d'un Bureau de Vote qui a comme attribut :
       - les attributs de l'object Salle
       - Une liste des Bulletins  
    */

    class Decharge : public Salle {

        /* Méthodes */
                
        public  : 

           /* 
              Rôle : constructeur de la classe
              Préconditions : nb_electeur > 0 , duree > 0 et el != nullptr
              Entrées : 2 entiers nb_electeur et duree et un pointeur vers Election el
              Sortie : les attributs ont été initialisés
              Coût : linéaire en taille de la listeCandidat         
           */

            Decharge ( int nb_electeur , int duree ,  Election*  el );

            /*
              Rôle : Affiche le  nombre de bulletins de vote attribués à chaque candidat
              Préconditions : Aucune
              Entrées : Aucune
              Sortie : affichage
              Coût : linéaire en taille de la liste_bulletin          
           */

            void affiche_bulletin( Election* el )const ;

            /* 
              Rôle : permet de prendre le bulletin d'un candidat
              Préconditions : pers != nullptr
              Entrées : un pointeur vers Electeur pers
              Sortie : taille de la liste_choix de l'électeur est >=2
              Coût : linéaire en nb_alea où nb_alea est un nombre entre 2 et taille ( liste_bulletin)        
           */

            void choisir_bulletin(Electeur *pers ,Election* elect ) ;


            /* 
              Rôle : affiche les bulletins de Vote que l'élécteur a pris
              Préconditions : pers != nullptr
              Entrées : un pointeur ver Electeur
              Sortie : affichage
              Coût : linéaire en la taille de la liste des choix de l'électeur         
           */

            void affiche_choix(Electeur *pers) ;

            /* 
              Rôle : permet de faire sortir de la decharge
              Entrées : une file en modif
              Coût : constant        
           */
            void faire_sortirDecharge(std::queue<Electeur*>& file);

            /* 
              Rôle : permet de faire entrer de la decharge
              Entrées : une file en modif
              Coût : constant        
           */

            void faire_entrerDecharge(std::queue<Electeur*>& file);

            /* 
              Rôle : permet de faire son coix dans la decharge
              Entrées : un pointeur vers Election
              Coût : linéaire ne taille de la liste choix de l'électeur        
           */ 

            void choisirDansDecharge(Election*elect_);

            /* 
              Rôle : renvoie un entier comptis entre 2 et la taille de liste_bulletin
              Préconditions : b > a
              Entrées :aucune
              Sortie : renvoie un entier
              Cout :  constant      
           */

            int nb_alea(int a , int b) ;

            /* 
              Rôle : renvoie un réel entre 0 et 1
              Entrées :aucune
              Sortie : renvoie un réel
              Cout :  constant      
           */

            double prendreBulletinblanc() ;


            /*
              Rôle : Destructeur de la classe 
              Préconditions : les élements de la liste_bulletin doivent avoir été alloués dynamiquement
              Entrées : Aucune entrée
              Sortie : libère la mémoire allouée dynamiquement
              Coût : O(n)         
           */

            ~Decharge();
            
        private :
            struct BulletinCandidat{
               BulletinVote* bv ;
               int qte ;
               BulletinCandidat( BulletinVote* b , int q) : bv(b), qte(q){}
            };
            std::unordered_map< int , BulletinCandidat*> liste_bulletin ;
            static double Pb ;// probabilité de prendre un bulletin blanc


    } ;
}
#endif
