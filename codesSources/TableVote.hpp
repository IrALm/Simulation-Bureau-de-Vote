

/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef TABLEVOTE_HPP
#define TABLEVOTE_HPP

#include "Candidat.hpp"
#include "Electeur.hpp"
#include "Election.hpp"
#include "Salle.hpp"
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

namespace elections {
/* classe tablevote 
   Une table de Vote est une salle du Bureau de vote qui contient une liste d'emargement
   c'est l'endroit où un électeur confirme son vote et emarge sur la liste d'emargent
   Les votes y sont aussi comptabilisés... 
*/

class TableVote : public Salle {

        public : 
                /* 
                  Rôle : constructeur de la classe 
                  Préconditions : el != nullptr
                  Entrées : int duree , unordored_set nb , vector<Personne*> vp et Election* el
                  Sortie : les attributs ont été initialisés
                  Coût : Linéaire en taille de Vp        
                */

                TableVote(int duree ,std::set<Personne* , Personne::CompAlpha>nb, const std::vector<Personne*>& vp , Election* el );
                
                /* 
                  Rôle : permet à l'electeur de confirmer son vote
                  Préconditions : el != nullptr
                  Entrées : Electeur* el
                  Sortie : Le vote a été confirmé
                  Coût : constant         
                */

                void voter(Electeur *el , Election* elect);

                /*
                  Rôle : permet à l'électeur de signer dans la liste d'Emargement 
                  Préconditions :
                  Entrées :el != nullptr
                  Sortie : l'électeur signe
                  Coût : constant          
                */

                void signer(Electeur *el);

                /*
                  Rôle : permet d'afficher les voix de chaque Candidat ainsi que leur pourcentage 
                  Préconditions : aucune
                  Entrées : aucune
                  Sortie :affichage
                  Coût : quasi-linéaire en taille de la liste_voix         
                */
                void affVoixCandidat(Election* el);

                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées :Aucune
                  Sortie : renvoie le nombre des bulletins nuls qui ont été confirmés comme choix
                  Cout : constant         
                */

                int get_nbNul()const ;

                /*
                  Rôle : accesseur
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie le nombre des bulletins blancs qui ont été confirmés comme choix 
                  Cout : constant         
                */

                int get_nbBlanc()const ;

                /*
                  Rôle : accesseur 
                  Préconditions : Aucune
                  Entrées : Aucune
                  Sortie : renvoie nombre des électeur ayant sugné la liste d'emargemnt
                  Cout : constant          
                */
                
                int get_nbPpr()const ;

                /*
                  Rôle : faire sortir un electeur de la table d Vote
                  coût : constant
                */
                Electeur* faire_sortirTvote();

                 /*
                  Rôle : faire entrer un electeur de la table d Vote
                  coût : constant
                */
                void faire_entrerTvote(std::queue<Electeur*>& file);

                 /*
                  Rôle : permet de choisir au niveau  de la table d Vote
                  coût : constant
                */

                void choisirDansVote(Election* elect);

                /*
                  Rôle : permet de tester si un électeur a dejà voter 
                  Préconditions : id_el >=0
                  Entrées : int id_el
                  Sortie : renvoie true ou false
                  Cout : constant          
                */

                bool TestVote( int id_el );

                /* 
                  ces 3 Méthodes me permettent de faire le tri pour afficher
                  les résultats des candidats dans l'ordre décroissant
                  i.e du candidat avec le plus des voix au candidats avec les moins des voix
                  les coûts ont été detaillé dans le fichier .cpp
                  et les algo ont été vu en TD 
                */
                void echanger(int a , int b );
                int partition(int d , int f);
                void tri_rapide( int d , int f) ;

                /*
                  Rôle : Destructeur de la classe  
                  Préconditions : les élements doivent avoir été alloués dynamiquement
                  Entrées : Aucune
                  Sortie : libère la mémoire allouée dynamiquement
                  Cout : Linéaire en taille de liste_emargement        
                */

                ~TableVote();
        private : 

                /* Je definie une structure Emargement qui aura deux champs :
                   l'identifiant de l'électeur et un booléen  
                */

                struct Emargement {
                    int id ; // identifiant de l'élécteur ...
                    bool signe ; // vrai si il a signé , faux sinon ... 
                    Emargement ( int i , bool s) : id(i) , signe(s){}
                };

                /* Je définis une autre structure qui va me permettre
                   de comptabiliser le nombre des voix de chaque candidat
                   A chaque candidat est associé un nombre des voix 
                */
                struct Voix{
                  int indice , voix ;
                };

                
                Voix*liste ;// compte le nombre des voix et me permttra de les trier pour les afficher par ordre décroissant
                std ::unordered_map< int,Emargement*> liste_emargement ; // liste contenant les identifiants des electeurs: avec cette structure : insertion constant et test constant
                int nb_nul , nb_blanc , nbPpr; // pour comptabiliser le nombre des vots nuls , votes blancs ainsi que le nombre des électeurs ayant emargés. 
} ;
}
#endif
