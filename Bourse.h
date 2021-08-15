#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include<string>
#include<vector>
#include"PrixJournaliers.h"
#include"Date.h"
using namespace std ;

class PrixJournaliers ;
class Bourse
{
protected:
    Date DateAujourdhui ;
public :
    Bourse() ;
    Bourse(Date date,vector<PrixJournaliers> h):DateAujourdhui(date){};
    Date getDateAujourdhui(){return DateAujourdhui ;}
    void setDateAujourdhui(Date d ){DateAujourdhui=d;}
    virtual PrixJournaliers* rechercherPrixActionDate(string,Date ) = 0;
    virtual PrixJournaliers* rechercherPrixActionAujourdhui(string) = 0;
    virtual void AffichePrixJournaliers(Date) =0;
    friend class Simulator ;
    friend class PorteFeuille ;
    virtual ~Bourse(){};


};


#endif // BOURSE_H_INCLUDED

