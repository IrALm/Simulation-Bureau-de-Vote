
/*
    Fait par AGANZE LWABOSHI Moise et Robin NTWARI
*/

#include "Salle.hpp"
#include "Electeur.hpp"
namespace elections{

    /* Constructeur de la classe 
       coût : constant
    */
    Salle::Salle(int duree)
         : duree_(duree) , pers_(nullptr) , etat(true){
    }

    /* permet de faire entrer une personne dans une salle
       coût : constant
    */

    void Salle::entrer(Electeur* pers){
        if( pers_ == nullptr){
            pers_ = pers ;
            pers_->incr_d(duree_);
            etat = false ; // occupé
            std::cout<< std::endl <<"   " << pers->id()+1 << " entre " << std::endl ;
        }
    }

    /* permet de faire sortir une personne dans une salle
       coût : constant
    */

    Electeur * Salle::sortir(Electeur* pers ){
        if( pers == nullptr)
            return nullptr;
        else{
            if( pers->cmpdr()){
                pers_ = nullptr ;
                etat = true ; // libre
                std::cout <<"  " << pers->id()+1 << " sort " << std::endl ; 
                return pers ;
            }
            else{
                return nullptr ;
            }
        }
    }

    /* decrémente la durée de l'élécteur dans la salle
       coût : constant
    */

    void Salle::decr_dPers(int t){
        if( pers_ != nullptr)
            pers_->decr_d(t);
    }
    /* 
      Les 3 méthodes ci dessous sont des accesseurs 
      coût : constant 
    */
    int Salle::get_duree() const{ 
        return duree_ ;
    }

    bool Salle::get_etat() const{ 
        return etat ;
    }

    Electeur* Salle::get_pers() const{ 
        return pers_ ;
    } 
}
