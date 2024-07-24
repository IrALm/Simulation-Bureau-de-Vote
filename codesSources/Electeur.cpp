
#include "Electeur.hpp"
#include "BulletinVote.hpp"
#include <vector>
namespace elections{

    /* Constructeur de la classe Electeur 
       coût : constant 
    */

    Electeur::Electeur(const std::string& nom, const std::string& prenom,int id , int spol )
            : Personne( nom , prenom , id , spol),duree_vote(0),choix(nullptr),Avoter(false){
    }

    /*  Ecriture sur un flux de sortie 
        coût : constant 
    */

    std::ostream& operator<<(std::ostream& os, const Electeur& psn) {
        os << psn.nom() << " " << psn.prenom() << " (" << psn.id() << ")";
        return os;
    }

    /* Incrémenter la durée d'un electeur dans une salle ( decharge , isoloir ou Tvote)
       coût : constant
    */

    void Electeur::incr_d( int t)
    {
        duree_vote = duree_vote + t ;
    }

    /* Decrémenter la durée d'un electeur dans une salle ( decharge , isoloir ou Tvote)
       coût : constant
    */

    void Electeur::decr_d(int t)
    {
         duree_vote = duree_vote - t ;
    }

    /* Pour vérifier si la durée  de l'électeur
       dans une salle == 0 pour ensuite le faire sortir de la salle
       coût : constant
    */

    bool Electeur::cmpdr() const{ 
        return duree_vote <= 0 ;
    
    }

    /* renvoie la taille de la liste des choix 
       coût : constant
    */
    int Electeur::taille()const{
        return liste_choix.size() ;
    }

    /* accesseur : retourne durée de l'électeur dans une salle 
       coût : constant
    */
    int Electeur::get_dure() const{ 
        return duree_vote ;
    }
    
    /* permet à l'électeur de faire un choix
       coût : constant 
    */

    void Electeur::faire_choix(BulletinVote* b ){
        choix = b ;
    }

    /* permet de retourne le nom et le prénom du candidat que l'électeur a choisi
       coût : constant
    */
    std::string Electeur::get_choix() const{
        return choix->get_candidat()->nom() + "  " + choix->get_candidat()->prenom() ;
    }

    /* permet de retourne le choix de l'électeur 
       coût : constant
    */

    BulletinVote* Electeur:: choix_() const{
        return choix ;
    }

    /* Retourne le type du Bulletin que l'électeur a choisi
       coût : constant
    */

    std::string Electeur::get_chType() const{
        return choix->typeBulletin();
    }

    /* Retourne le pointeur du candidat que l'électeur a choisi
       coût : constant
    */

    Personne * Electeur::candidat_choisi()const{
        return choix->get_candidat();
    }

    /*
        rôle : retourne le numéro du candidat choisi
        coût : constant
    */
    int Electeur::numeroCandidat() const{
        return choix->get_candidat()->get_num();
    }

    /* Retourne le booléen Avoter
       coût : constant
    */

    bool Electeur::Avoter_()const{
        return Avoter;
    }

    /* le booléen Avoter == true
       coût : constant
    */

    void Electeur::set_vote(){
        Avoter = true ;
    }


    /* accesseur : renvoie la liste des choix 
       coût : constant
    */
    
    std::vector<BulletinVote*> Electeur::get_liste_choix()  { 
        return liste_choix ;
    }

    /*
        rôle : affecter une liste des choix à l'électeur
        coût: constant O(1) 
    */
    void Electeur::affect_listechoix( std::vector<BulletinVote*> Bulletin){
        liste_choix = Bulletin ;
    }
}