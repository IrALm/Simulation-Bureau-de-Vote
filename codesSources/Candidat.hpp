
/*
    Fait par AGANZE LWABOSHI Moise et Robin NTWARI
*/


#ifndef CANDIDAT_HPP
#define CANDIDAT_HPP
#include "Personne.hpp"
namespace elections {

    class Candidat : public Personne{

        public :

            /* constructeur
                coût : O(1)
            */
            Candidat(const std::string& nom, const std::string& prenom, int id , int spol , int numero );

            /* accesseur
               coût : O(1)
            */

            int get_num() const ;

            /* accesseur
               coût : O(1)
            */
            int voix_() const ;

            /*
                Rôle : incrémente le nombre des voix du candidat
                coût : O(1)
            */
            void incrVoix_( int v);

            /*
                rôle : permet d'écrire sur un flux de sortie
                coût : constant O(1)
            */
            friend std::ostream& operator<<(std::ostream& os, const Candidat& psn);
            
        private :
                int num ;
                int voix ;

    };
}
#endif