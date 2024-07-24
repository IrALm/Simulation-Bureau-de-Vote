
/*
    Fait par AGANZE LWABOSHI Moise 
    
*/

#include <cstdlib>
#include <ctime>
#include "BureauVote.hpp"
#include "Decharge.hpp"
#include "Isoloir.hpp"
using namespace std;
using namespace elections;

// initialisation des quelques variables statiques

int EspaceIsoloir::nb_isoloir = 3 ;// nombre d'isoloir présent dans l'Espace d'Isoloir
int Election::nb_Candidat = 3 ;// nombre des candidats pour l'élection
double Decharge::Pb = 0 ;// probabilité de prendre un bulletin blanc
double Isoloir::Pn = 0 ;// probabilité de rendre un bulletin nul 



int main(void)
{
   // initialisation du générateur de nombres aléatoires
   std::srand(std::time(nullptr));

   // création des personnes
   std::vector<Personne*> vp = {
      new Personne("A", "bic", 7),
      new Personne("B", "gad", 9),
      new Personne("C", "ann", 2),
      new Personne("D", "pol", 5),
      new Personne("E", "lam", 1),
      new Personne("F", "bul", 10),
      new Personne("G", "yap", 3),
      new Personne("X", "nel", 5),
      new Personne("Y", "rik", 2),
      new Personne("Z", "pat", 8)
   };
   
   // on récupère les candidats 

   std::set<Personne* , Personne::CompAlpha>nb = { vp[7] , vp[8] , vp[9] };

   // on déclare et on initialise nos données
   
   int duree_decharge = 3 ;
   int duree_isoloir = 6 ;
   int duree_tVote = 4;
   int T_max = 20 ;
   int nb_elect = vp.size() - nb.size(); 
   int numBureau = 258 ;

   // on crée le bureau de vote 

   BureauVote* bureau = new BureauVote( vp ,nb, vp[2] , numBureau , duree_decharge , duree_isoloir, duree_tVote , nb_elect , T_max);
   
   // On fait appel aux méthodes d'affichage pour afficher les premières infos
   
   bureau->get_elec()->affiche();// affiche les informations relatives par rapport à l'élection
   bureau->aff_elect();// affiche la liste électorale
   bureau->get_dech()->affiche_bulletin(bureau->get_elec());// affiche les bulletins de votes ( chaque candidat avec son nombre des bulletins présent dans la décharge)

   cout << endl << endl << endl ;
   bureau->processus_vote(vp);// simule le déroulement du vote dans le bureau de vote ( entrées , sorties , ...) 
   cout << endl << endl << endl ;

   bureau->affichageResultat() ;// affiche les résultats de l'élection
   cout << endl << endl << endl ;

   // libération de la mémoire allouée dynamiquement par bureau 
   bureau->~BureauVote();
   
   // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}
