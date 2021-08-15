#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include"Titre.h"
#include<vector>
#include<string>

using namespace std ;
class PorteFeuille
{
    vector<Titre> Tab  ;
    double Solde ;
public:
    PorteFeuille(double);
    double getSolde() const;
    void setSolde(double);
    int getNombreTitre() const;
    Titre getTitre(int) const  ;
    Titre* rechercherTitre(string) ;
    void AjouterTitre(Titre);
    void RetirerTitre(string,int);
    friend ostream& operator<< (ostream& flux, PorteFeuille& p) ;

    ~PorteFeuille(){} ;
    friend class Simulator;
};


#endif // PORTEFEUILLE_H_INCLUDED
