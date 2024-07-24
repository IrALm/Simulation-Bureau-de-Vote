
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#include "BulletinVote.hpp"

namespace elections {

    /* classe BulletinVote
       constructeur 
       coût : constant
    */

    BulletinVote::BulletinVote(  Candidat* pers , const std::string& t )
                : candidat(pers), type(t){
    }

    /* accesseur
       coût : constant 
    */

    Candidat* BulletinVote::get_candidat() const { 
        return candidat ;
    }

    /* accesseur
       coût : constant 
    */

    std::string BulletinVote::typeBulletin() const{ 
        return type ;
    }

    /* classe BullettinBlanc 
       constructeur 
       coût : constant
    */

    BulletinBlanc::BulletinBlanc()
                 : BulletinVote(nullptr , " BLANC "){
    }

    /* classe BulletinNul 
       constructeur 
       coût : constant
    */

    BulletinNul::BulletinNul(Candidat* pers , const std::string& terme_inter)
               : BulletinVote( pers , " NUL "),terme_interdit(terme_inter){      
    } 


}
