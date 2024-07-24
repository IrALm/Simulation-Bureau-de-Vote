
/* 
  Fait par AGANZE LWABOSHI Moise 
*/

#include "BureauVote.hpp"
#include "Electeur.hpp"

namespace elections {

    /* Constructeur de la classe 
       coût : linéaire en taille de vp 
    */

    BureauVote::BureauVote(std::vector<Personne*> vp, std::set<Personne*, Personne::CompAlpha> nb,
                           Personne* president, int num, int duree_decharge,
                           int duree_isoloir, int duree_tVote, int nb_elect
                           , int T_Max)
        : numero_bureau(num), president_bureau(president), T_MAX(T_Max), t(0) {

        elect_ = new Election(" Euro 2024 ", nb, vp);
        dech_ = new Decharge(nb_elect, duree_decharge, elect_); // Coût: linéaire en taille de la listeCandidat
        Isoloir* is = new Isoloir(duree_isoloir, 0); // coût: constant
        EspIso = new EspaceIsoloir(is);
        tbV = new TableVote(duree_tVote, nb, vp, elect_); // coût : Linéaire en taille de Vp + taille de liste Candidat
        
        /* Remplissage de la liste d'élécteurs */

        for (const auto& it : vp) {
            auto itr = nb.find(it);
            if (itr == nb.end()) {
                auto electeur = new Electeur(it->nom(), it->prenom(), it->id(), it->spol());
                liste_electeur.insert(electeur);
            }
        }
    }

    /* accesseur
       coût : constant
    */

    std::set<Electeur*, Electeur::CompAlpha> BureauVote::get_liste_electeur() const {
        return liste_electeur;
    }

    /* Deux accesseurs : le premier renvoie un pointeur vers la décharge 
       coût : constant
    */

    Decharge* BureauVote::get_dech() const {
        return dech_;
    }

    /* Le deuxième un pointeur vers l'éléction 
       coût : constant
    */

    Election* BureauVote::get_elec() const {
        return elect_;
    }

    /* Méthode d'affichage de l'Ouvertur du Bureau 
       coût : constant
    */

    void BureauVote::ouverture() const {
        std::cout << std::endl << " OUVERTURE BUREAU  " << std::endl;
        std::cout << std::endl << " T_MAX = " << T_MAX;
    }

    /* Méthodes d'affichage de la fermeture de l'entrée du Bureau 
       coût : constant
    */

    void BureauVote::fermeture() const {
        if (t >= T_MAX) {
            std::cout << std::endl << std::endl << " FERMETURE ENTREE  " << std::endl << std::endl;
        }
    }

    /* Méthode d'affichage de la fermeture du Bureau 
       coût : constant
    */

    void BureauVote::fermee() const {
        std::cout << std::endl << std::endl << " FERMETURE BUREAU  n°: " << numero_bureau << std::endl << std::endl;
    }

    /* Méthode d'affichage de la liste électorale 
       coût : linéaire en taille de la liste électoral 
    */

    void BureauVote::aff_elect() const {
        std::cout << std::endl << " BUREAU n° : " << numero_bureau
            << std::endl << " LISTE ELECTORALE " << std::endl;
        for (const auto& it : liste_electeur) {
            std::cout << *it << std::endl;
        }
    }

    /***********************  SIMULATION PROCESSUS DE VOTE  *******************************

      1 ère Méthode : incrémente le temps discret de 1  et l'affiche 
       coût : constant
    */

    void BureauVote::incremente_t() {
        t++;
        std::cout << std::endl << " T = " << t;
    }

    /* 2 ième Méthode : mets à jour le temps discret ainsi que le temps de chaque élécteur
       dans la pièce où il se trouve 
       coût : linéaire en nombre d'isoloir
    */

    void BureauVote::miseAjourTempsDiscret() {
        incremente_t();
        dech_->decr_dPers(1);
        EspIso->decrDIs_Occupe(); // coût :linéaire en nombre isoloir 
        tbV->decr_dPers(1);
    }

    /*
      coût : Dans le pire des cas linéaire en taille de la liste des choix de l'électeur
    */
    void BureauVote::miseAjourDecharge() {
        incremente_t(); // coût : constant
        EspIso->decrDIs_Occupe(); //coût : linéaire en taille de iso_
        tbV->decr_dPers(1); // coût : constant
        auto verif = file_tVote.size();
        EspIso->choisirDansIsoloir(file_tVote, tbV); //coût : linéaire en taille de la liste des choix
        if (verif < file_tVote.size()) {
            miseAjourTableVote();
        }
        tbV->choisirDansVote(elect_); //coût : constant
    }

    /* 
      coût : Dans le pire des cas linéaire en taille de la liste des choix de l'électeur
    */
    void BureauVote::miseAjourEspaceIsoloir() {
        incremente_t(); // coût : constant
        dech_->decr_dPers(1); // coût : constant
        EspIso->decrDIs_Occupe();//coût : linéaire en nombre d'Isoloir
        tbV->decr_dPers(1); // coût : constant
        dech_->choisirDansDecharge(elect_); //coût : linéaire en taille de la  liste des choix de l'électeur
        auto verif = file_tVote.size();
        EspIso->choisirDansIsoloir(file_tVote, tbV); //coût : Dans le pire des cas Quadratique en taille de la liste des choix
        if (verif < file_tVote.size()) {
            miseAjourTableVote();
        }
        tbV->choisirDansVote(elect_); //coût : constant
    }

    /*
      coût : Dans le pire des cas linéaire en taille de la liste des choix de l'électeur
    */
    void BureauVote::miseAjourTableVote() {
        incremente_t(); // coût : constant
        dech_->decr_dPers(1); // coût : constant
        EspIso->decrDIs_Occupe(); // coût : linéaire en taille de iso_
        dech_->choisirDansDecharge(elect_); // coût : linéaire en taille de la  liste des choix de l'électeur
        auto verif = file_tVote.size();
        EspIso->choisirDansIsoloir(file_tVote, tbV); //coût : linéaire en taille de la liste des choix de l'électeur
        if (verif < file_tVote.size()) {
            miseAjourTableVote();
        }

    }
    /* Méthode : permet de faire entrer une personne dans le bureau

       elle fonctionne comme suit : 
       - Transforme la Personne en électeur
       - ensuite sur base de son identifiant , verifie s'il appartient à la liste 
         electorale des electeurs inscrits dans le bureau
         le test se fait à partir de la liste d'emargement :
         - Premièrement , verifie si l'id de la personne est dans la liste d'emargement:
         complexité temporelle : constante ( O(1) ) car la liste d'emargement est ensemble 
         non ordonné ( implémenté par une table de hachage)
         -Deuxièmement, si l'electeur est dans la liste , on vérifie s'il a signé ou pas.
          s'il a signé ce qu'il a déjà voté et là , il ne pourra plus entrer dans le bureau
          s'il n'a pas signé , ce qu'il n'a pas encore voté et là il peut entrer dans le bureau
        coût : constant
    */

    void BureauVote::entrer_bureau(Personne* pers) {
        auto tmp = new Electeur(pers->nom(), pers->prenom(), pers->id(), pers->spol());
        int id_el = tmp->id();
        bool test = tbV->TestVote(id_el); //coût : constant
        if (test) {
            fileD_attente.push(tmp);
            std::cout << std::endl << " ENTREE " << std::endl << "   " << tmp->id() + 1 << "  entre  " << std::endl;
        }
    }

    /* Méthode : permet de faire sortir un élécteur ayant fini de voter
       coût : constant  
    */

    void BureauVote::sortir_bureau(Electeur* pers) {
        std::cout << std::endl << " SORTIE " << std::endl << "  " << "   " << pers->id() + 1 << "  sort " << std::endl;
    }
    /* Méthode : permet de faire evoluer la Decharge 
       coût :  Dans le pire des cas linéaire en taille de la  liste des choix de l'électeur
    */

    void BureauVote::evoluerTableDecharge() {
        if (dech_->get_pers() != nullptr) {
            dech_->choisirDansDecharge(elect_); //coût : linéaire en taille de la  liste des choix de l'électeur
            if (dech_->get_pers()->get_dure() <= 0) {
                dech_->faire_sortirDecharge(file_isoloir);
                EspIso->faire_entrerIsoloir(file_isoloir);
                miseAjourEspaceIsoloir();
                dech_->faire_entrerDecharge(fileD_attente);
                miseAjourDecharge();
            }
        }
        else {
            dech_->faire_entrerDecharge(fileD_attente);
            miseAjourDecharge();
        }
    }

    /* Méthode : permet de faire evoluer la Table de Vote 
       coût : Dans le pire des cas linéaire en taille de la liste des choix de l'électeur
    */

    void BureauVote::evoluerTableVote(Electeur* tmp) {
        if (tbV->get_pers() != nullptr) {
            tbV->choisirDansVote(elect_); //coût : constant
            if (tbV->get_pers()->get_dure() <= 0) {
                tmp = tbV->faire_sortirTvote();
                if (tmp != nullptr)
                    sortir_bureau(tmp);
            }
        }
        else {
            tbV->faire_entrerTvote(file_tVote);
            miseAjourTableVote(); //coût : Dans le pire des cas linéaire en taille de la liste des choix de l'électeur
        }
    }

    /* Méthode : permet de simuler toutes les entrées et les sorties ainsi que 
       les votes et les mises à jour du temps discret
       Stratégie : s'il ya moins de deux personnes dans la file d'attente, 
       on fait entrer des électeurs dans le bureau 
       coût : linéaire en T_max ou taille(vp)
    */

    void BureauVote::processus_vote(const std::vector<Personne*>& vp) {

        /* Déclaration des quelques variables utiles pour l'élaboration
           de cette méthode ...
        */
        size_t i = 0;
        Electeur* tmp = nullptr;

        /* Debut */

        ouverture(); // ouverture du bureau 
        incremente_t(); // incrémentation de t 

        while (t < T_MAX && i < vp.size()) {
            if (fileD_attente.size() < 2) {
                if (t >= T_MAX) break;
                incremente_t();
                if (i < vp.size()) {
                    entrer_bureau(vp[i]);
                    i++;
                }
                else break;
            }
            if (t >= T_MAX) break;
            evoluerTableDecharge();
            evoluerTableVote(tmp);
            miseAjourTempsDiscret();

        }
        fermeture(); // fermeture de l'entrée du bureau 
        bool test = EspIso->TestIsoloirOccupe();
        while ((!fileD_attente.empty() || !file_tVote.empty() || test) || (!dech_->get_etat() || !tbV->get_etat())) {
            int tempo = t;
            evoluerTableDecharge();
            EspIso->faire_entrerIsoloir(file_isoloir);
            miseAjourEspaceIsoloir();
            auto verif = file_tVote.size();
            EspIso->choisirDansIsoloir(file_tVote, tbV);
            if (verif < file_tVote.size()) {
                miseAjourTableVote();
            }
            evoluerTableVote(tmp);
            if (t == tempo)
                miseAjourTempsDiscret();
            test = EspIso->TestIsoloirOccupe();//on vérifie s'il y a un isoloir occupé
        }
        fermee();// fermeture du bureau 

    }

    /* Méthode : affiche les Resultats de l'éléction
       coût : quasi-linéaire en taille de la liste_voix
    */

    void BureauVote::affichageResultat() {

        float p = ((float)tbV->get_nbPpr() / liste_electeur.size()) * 100;
        float abs = ((float)(liste_electeur.size() - tbV->get_nbPpr()) / liste_electeur.size()) * 100;

        std::cout << " BUREAU n°  " << numero_bureau << " : RESULTATS " << elect_->nom_elect()
            << std::endl << " PRESIDENT : " << president_bureau->nom() << " " << president_bureau->prenom() << std::endl
            << "    Nb_electeurs : " << liste_electeur.size() << std::endl
            << "    Nb_Vote : " << tbV->get_nbPpr() << std::endl
            << "    participation : " << p << "%" << std::endl
            << "    abstention : " << abs << "%" << std::endl;

        tbV->affVoixCandidat(elect_);//coût : quasi_linéaire en taille de la liste des voix des candidats

        std::cout << std::endl << "    blanc : " << tbV->get_nbBlanc()
            << " ( " << ((float)tbV->get_nbBlanc() / tbV->get_nbPpr()) * 100 << " %) " << std::endl
            << "    nul : " << tbV->get_nbNul()
            << " ( " << ((float)tbV->get_nbNul() / tbV->get_nbPpr()) * 100 << " %) " << std::endl;
    }

    /* Destructeur de la classe 
       coût : Linéaire en taille de liste_electeur
    */
    BureauVote::~BureauVote() {

        elect_->~Election();
        dech_->~Decharge();
        tbV->~TableVote();
        EspIso->~EspaceIsoloir();
        for (auto itr : liste_electeur)
            delete itr;
    }
}
