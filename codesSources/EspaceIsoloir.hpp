
/*
    Fait par AGANZE LWABOSHI Moise 
*/

#ifndef ESPACEISOLOIR_HPP
#define ESPACEISOLOIR_HPP
#include "Isoloir.hpp"
#include "TableVote.hpp"
#include <queue>

namespace elections {

    /* classe Espace d'Isoloir : un Espace d'Isoloir est constitué d'Isoloirs
    */
    class EspaceIsoloir{
        public :
                /*
                  Rôle : constructeur
                  coût : linéaire en nb d'Isoloir
                */
                EspaceIsoloir(Isoloir*is);
                /* 
                  Rôle : cherche un isoloir libre
                  coût : Dans le pire des cas linéaire en nombre d'Isoloir
                */
                Isoloir* libre();
                /* 
                  Rôle : cherche un isoloir occupé
                  coût : Dans le pire des cas linéaire en nombre d'Isoloir
                */
                bool TestIsoloirOccupe();
                /* 
                  Rôle : mets à jour le temps dans les isoloir occupés
                  coût : linéaire en nombre d'Isoloir
                */
                void decrDIs_Occupe();
                /* 
                  Rôle : faire sortir d'un isoloir
                  coût : constant
                */
                Electeur* faire_sortirIsoloir( Isoloir* it  );
                /* 
                  Rôle : faire sortir des isoloirs si durée = 0 
                  coût : linéaire en nombre d'Isoloir
                */
                void faire_SortirDans_IsoloirOccupe(std::queue<Electeur*>& file) ;

                /* 
                  Rôle : faire entrer dans des isoloirs
                  coût : constant
                */
                void faire_entrerIsoloir(std::queue<Electeur*>& file );

                /* 
                  Rôle : choisir dans des isoloirs
                  coût : linéaire en nombre d'Isoloir
                */
                void choisirDansIsoloir(std::queue<Electeur*>& file_tVote , TableVote* tbV);

                /* 
                  Rôle : destructeur de la classe
                  coût : linéaire en nombre d'Isoloir
                */
                ~EspaceIsoloir();

        private : 
                static int nb_isoloir ;
                std :: unordered_map< int, Isoloir*> iso_ ;


    };
}
#endif
