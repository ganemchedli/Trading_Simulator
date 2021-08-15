#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED
#include"Bourse.h"
#include"Date.h"
#include"Trader.h"
#include"portefeuille.h"
#include"BourseVector.h"

using namespace std ;
class Simulator
{
private:
    Date  DateDepart ;
    Date DateDeJour ;
    unsigned int NbJours ;
    double MontantDepart ;
    PorteFeuille P;
    Trader* T;
    Bourse* bourse ;

public :

    Simulator(Date const,Date,int,double, Trader*, Bourse* );
    void LancerUneSimulation();
    Date getDateDeDepart() const ;
    Date getDateDeJours() const ;
    int getNbDeJours () const;
    void setDateDeJour(Date);
    void setMontantDepart (double s);
    double getMontantDepart() const;
    void AppliquerTransaction(Transaction) ;
    void AfficheDetailPortefeuille();
    double CalculResultat();
    ~Simulator();
};

#endif // SIMULATOR_H_INCLUDED

