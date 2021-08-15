#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include<string>
#include<vector>
#include"PrixJournaliers.h"
#include"Date.h"
using namespace std ;
class BourseVector : public Bourse
{
private:
    vector<PrixJournaliers> Historique ;
public :
    BourseVector(Date,vector<PrixJournaliers>);
    PrixJournaliers* rechercherPrixActionDate(string S , Date d );
    PrixJournaliers* rechercherPrixActionAujourdhui(string);
    void AffichePrixJournaliers(Date);
    ~BourseVector(){} ;
    friend class Simulator ;


};



#endif // BOURSEVECTOR_H_INCLUDED
