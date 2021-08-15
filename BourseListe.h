#ifndef BOURSELISTE_H_INCLUDED
#define BOURSELISTE_H_INCLUDED

#include<list>
using namespace std ;
class BourseListe : public Bourse
{
private:
    list<PrixJournaliers> Historique ;
public :

    BourseListe(Date date,vector<PrixJournaliers> historique);
    PrixJournaliers* rechercherPrixActionDate(string S , Date d );
    PrixJournaliers* rechercherPrixActionAujourdhui(string);
    void AffichePrixJournaliers(Date);
    ~BourseListe(){} ;
    friend class Simulator ;


};


#endif // BOURSELISTE_H_INCLUDED


