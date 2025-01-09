# Simulateur d'Élection - Vote Simulation

## Description

Ce projet simule le déroulement d'un vote dans un **bureau de vote réel**, en tenant compte des différentes étapes et règles en vigueur, telles que :

- **Enregistrement des électeurs** : Gestion de l'inscription des électeurs avant l'élection.
- **Validation des identités** : Vérification de l'identité des électeurs avant de leur permettre de voter.
- **Gestion des bulletins de vote** : Traitement des bulletins déposés par les électeurs.
- **Dépouillement des résultats** : Comptabilisation des votes et gestion des résultats.
- **Affichage des statistiques finales** : Présentation des résultats sous forme de statistiques.

Le projet est écrit en **C++** en utilisant le paradigme de la **Programmation Orientée Objet (POO)**. Il vise à répliquer fidèlement l'organisation d'une élection tout en respectant la **confidentialité des votes** et la **précision du dépouillement**. Le logiciel est conçu pour optimiser le **coût temporel** et la **complexité spatiale** en utilisant des structures de données adaptées, telles que des **piles**, **files**, **dictionnaires**, **tables de hachage**, **listes chaînées**, **ensembles**, etc.

---

## Fonctionnalités

- **Enregistrement des électeurs** : Permet l'inscription des électeurs dans le système.
- **Validation des identités** : Vérifie les informations des électeurs avant qu'ils ne puissent voter.
- **Gestion des bulletins** : Permet aux électeurs de déposer leurs bulletins de vote dans l'urne.
- **Comptabilisation des votes** : Le dépouillement des résultats est effectué automatiquement après la clôture du vote.
- **Affichage des résultats** : Les résultats finaux sont affichés sous forme de statistiques détaillées.
- **Confidentialité des votes** : Les votes sont anonymes et sécurisés.
- **Optimisation des structures de données** : Utilisation de structures de données adaptées pour gérer l'enregistrement, la validation, le dépouillement et les statistiques de manière optimale.

---

## Détails Techniques

Le projet utilise plusieurs structures de données pour simuler un système d'élection efficace. Voici une description des principales structures et des optimisations mises en place :

    **File**: Employée pour gérer les files d'attente des électeurs en attente de validation de leur identité avant de pouvoir voter. Les électeurs sont ajoutés à la file et traités dans l'ordre de leur arrivée.

    Dictionnaire/HashMap : Utilisé pour stocker et récupérer rapidement les informations des électeurs et des candidats. Chaque électeur est identifié par un identifiant unique, et les informations des candidats sont indexées par leur nom ou numéro.

    Table de hachage : Une table de hachage est utilisée pour associer les identifiants des électeurs à leurs informations personnelles (nom, prénom, etc.) et à leur statut de vote, permettant un accès rapide et sécurisé.

    Liste chaînée : Pour gérer les bulletins de vote, une liste chaînée est utilisée. Chaque bulletin est ajouté sous forme de nœud dans la liste, et les résultats peuvent être comptabilisés efficacement.

    Ensemble : Un ensemble est utilisé pour garantir l'unicité des électeurs inscrits et éviter les doublons lors de la validation des identités et des votes.

Ces structures de données sont choisies en fonction des besoins du projet afin d'assurer des performances optimales en termes de coût temporel et de complexité spatiale, tout en garantissant une gestion précise et fiable des votes et des résultats.

---
## Installation

### Prérequis

- **C++17** ou supérieur installé sur votre machine.
- **Make** pour la gestion de la compilation et des dépendances.
- Aucune dépendance externe n'est requise, le projet utilise uniquement les bibliothèques standard C++.

---

## Compilation et Exécution

Ce projet utilise un **Makefile** pour simplifier la compilation et l'exécution. Voici les étapes pour compiler et exécuter le projet :

1. Clonez le dépôt :
   ```bash
   git clone git@github.com:IrALm/Simulation-Bureau-de-Vote.git
   cd Simulation-Bureau-de-Vote
2. Pour la compilation :
   ```bash
   make

3. Pour l'éxecution :
   ```bash
   ./main
4. Pour le nettoyage des fichiers générés:
   ```bash
   make clean


                                      
