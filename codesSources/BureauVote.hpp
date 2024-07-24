
/* 
  Fait le 10 avril par :
  AGANZE LWABOSHI Moise 
  
*/

#ifndef BUREAUVOTE_HPP
#define BUREAUVOTE_HPP

#include "EspaceIsoloir.hpp"
#include "Decharge.hpp"
#include "TableVote.hpp"

namespace elections {



    /* classe Bureauvote 
       Un bureau de vote comprend un numéro , 
       un président , une élection , une décharge,
       un espace d'isoloir et une table de Vote;
       Ainsi que des files d'attente.
       Il comprend aussi la liste électorale ainsi que 
       le temps Maximal pour faire entrer des électeurs dans le bureau
    */

    class BureauVote {

        public :
                /*
                  Rôle : constructeur de la classe  
                  Préconditions :
                  Entrées : vector<Personne*> vp , set des pointeurs vers Personne nb , 
                            Pointeur vers pers président du bureau
                            des entiers : numero du bureau , duree decharge , 
                            vote , isoloir , nombre d'électeur et T_max
                            
                  Sortie : les attributs ont été initialisés
                  Cout : lineaire en taille vp          
                */

                BureauVote(std:: vector<Personne*> vp , std::set<Personne* , Personne::CompAlpha>nb ,
                Personne* president ,int num , int duree_decharge , 
                int duree_isoloir, int duree_tVote , int nb_elect ,  int T_Max);
                
                /*
                  Rôle : fait entrer pers du bureau 
                  Entrées :pointeur vers electeur
                  Cout : constant      
                */

                void entrer_bureau(  Personne* pers ) ;

                /* 
                  Rôle : fait sortir pers du bureau
                  Préconditions : pers != nullptr
                  Entrées : pointeur vers electeur
                  Sortie : fait sortir pers dans le bureau
                  coût : constant
                */

                void  sortir_bureau(Electeur* pers);

                /*
                  Rôle : affiche un message d'ouverture  du bureau
                  Cout : constant         
                */

                void ouverture() const;

                /* 
                  Rôle : affiche un message de fermeture de l'entrée du bureau
                  Cout : constant         
                */

                void fermeture()const;

                /*
                  Rôle : affiche un message de fermeture du bureau
                  Cout : constant        
                */

                void fermee()const;

                /* 
                  Rôle : incremente t
                  Cout : constant         
                */

                void incremente_t();

                /* 
                  Rôle : méthode d'afficage
                  Cout : linéaire en taille de la liste électoral   
                */

                void aff_elect()const ;
                
                /* 
                  Rôle : acceseur 
                  Sortie : retourn pointeur vers decharge
                  Cout : constant          
                */

                Decharge* get_dech() const ;

                /*
                  Rôle : acceseur 
                  Sortie : retourn pointeur vers election
                  Cout : constant         
                */

                Election* get_elec() const ;

                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : revoie la liste electoral
                  Coût : constant        
                */

                std::set<Electeur*,Electeur::CompAlpha> get_liste_electeur() const ;

                /*
                  Rôle : Simule le processus de vote dans un bureau de vote
                  Préconditions : Aucune
                  Entrées : Vp :  vector des pointeurs vers personnes
                  Coût : lineaire en T_max ou en taille de vp        
                */

                void processus_vote(const std::vector<Personne*>& vp);

                /*
                  Rôle : fait évoluer la décharge ainsi que les autres pièces du bureau
                  Coût : dans le pire des cas linéaires en nombre isoloir      
                */
                void evoluerTableDecharge();

                /*
                  Rôle :fait évoluer la TableVote ainsi que les autres pièces du bureau
                  Entrées :pointeur vers Electeur
                  Coût :dans le pire des cas linéaires en nombre isoloir           
                */
                void evoluerTableVote(Electeur* tmp);

                /*
                  Rôle : mets à jour t ainsi que la durée des electeurs dans chaque pièce du bureau
                  Coût : dans le pire des cas linéaires en nombre isoloir        
                */
                void miseAjourTempsDiscret();

                /*
                  Rôle : affice le resultat de l'éléction
                  Coût :  quasi-linéaire en taille de la liste_voix        
                */

                void affichageResultat();

                /*
                  Rôle : Mets à jour les informations dans la Décharge 
                  Coût : dans le pire des cas linéaires en nombre isoloir          
                */
                void miseAjourDecharge();

                /*
                  Rôle : Mets à jour les informations dans l'Espace Isoloir
                  Coût : dans le pire des cas linéaires en nombre isoloir          
                */
                void miseAjourEspaceIsoloir();

                /*
                  Rôle : Mets à jour les informations dans la Table de vote
                  Coût : dans le pire des cas linéaires en nombre isoloir        
                */
                void miseAjourTableVote();

                /*
                  Rôle : Destructeur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : Tout ce qui a été alloué dynamiquement a été desaloué
                  Coût : Linéaire en taille de liste_electeur        
                */

                ~BureauVote() ; 

        private : 
                int numero_bureau ;
                Personne* president_bureau ;
                Election* elect_ ;
                Decharge* dech_ ;
                EspaceIsoloir* EspIso ;
                TableVote* tbV;
                std::set<Electeur*,Electeur::CompAlpha>liste_electeur;
                int T_MAX , t ; 
                std::queue< Electeur* > fileD_attente , file_isoloir , file_tVote  ;

    } ;
}
#endif
