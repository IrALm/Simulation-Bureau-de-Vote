
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#include "Candidat.hpp"

namespace elections{


    /* constructeur
       coût : constant O(1)
    */
    Candidat::Candidat(const std::string& nom, const std::string& prenom, int id , int spol , int numero )
            : Personne( nom , prenom , id , spol), num(numero), voix(0){

    }

    /* accesseur
       coût : constant O(1)
    */
    int Candidat::get_num() const {
        return num ;
    }

    /* accesseur
       coût : constant O(1)
    */

    int Candidat::voix_() const{
        return voix ;
    }

    /*
        coût : constant O(1)
    */

    void Candidat::incrVoix_( int v){
         voix = voix + v  ;
    }

    /*
        coût : constant O(1)
    */

    std::ostream& operator<<(std::ostream& os, const Candidat& psn)
    {
        os << psn.nom() << " " << psn.prenom() << " " << psn.spol();
        return os;
    }
}
