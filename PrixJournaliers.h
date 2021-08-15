#ifndef PRIXJOURNALIERS_H_INCLUDED
#define PRIXJOURNALIERS_H_INCLUDED
#include<string>
#include"Date.h"
#include"Bourse.h"
using namespace std ;
class PrixJournaliers
{
    double Prix ;
    string SymboleAction;
    Date DatePrixJournaliers ;
public:
    string getSymboleAction()const
    {
        return SymboleAction;
    }
    double getPrix ()const
    {
        return Prix;
    }
    Date getDatePrixJournaliers()const
    {
        return DatePrixJournaliers ;
    }
    ~PrixJournaliers(){};
    friend bool operator==(PrixJournaliers const& a, PrixJournaliers const& b) ;
    friend istream& operator>> (istream& flux, PrixJournaliers& p) ;
    friend ostream& operator<< (ostream& flux, PrixJournaliers& p) ;

};


#endif // PRIXJOURNALIERS_H_INCLUDED
