

#ifndef BULLETINVOTE_HPP
#define BULLETINVOTE_HPP

#include "Candidat.hpp"

namespace elections {
  
    /* classe BulletinVote 
       Un  bulletin de Vote contient comme information :
       - Le Candidat qui lui est associé
       - ainsi que le type du Bulletin 
         * On peut avoir 3 types de Bulletins : normal , blanc et nul 
    */

    class BulletinVote {

        /* Méthodes */

        public :

                /*  Rôle : constructeur
                    Preconditions : les paramètres en entrée doivent être correctement déclarés  
                    entree : Personne* pers , string t
                    sortie : les attributs ont été initialisés 
                    cout : constant 
                */

                BulletinVote(  Candidat* pers , const std::string& t );

                /*  Rôle : accesseur 
                    preconditions : Aucune
                    entree : Aucune
                    sortie : renvoie le pointeur vers candidat 
                    cout : constant 
                */

                Candidat* get_candidat() const ;

                /*  Rôle : accesseur 
                    preconditions : Aucune
                    entree : Aucune
                    sortie : renvoie le type de bulletin  
                    cout : constant 
                */

                std::string typeBulletin() const ;


        /* Attributs */

        private :
                Candidat *candidat ;
                std::string type ;
    } ;

    /* classe BullettinBlanc 
       hérite de BulltinVote
    */

    class BulletinBlanc : public BulletinVote{

        public : 
                /*  Rôle : constructeur
                    Preconditon : Aucune
                    entree : Aucune
                    sortie : les attributs ont été initialisés
                    cout : constant
                */
                BulletinBlanc();
    } ;

    /* classe BulletinNul
       hérite de BulltinVote 
    */

    class BulletinNul : public BulletinVote {

        public : 
                /*  Rôle : constructeur
                    Preconditions : les paramètres en entrée doivent être correctement déclarés  
                    entree : Personne* pers , string terme_inter
                    sortie : les attributs ont été initialisés
                    cout : constant 
                */

                BulletinNul( Candidat* pers , const std::string& terme_inter);
        private :
                std::string terme_interdit;
    };
}

#endif