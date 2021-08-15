#include"PrixJournaliers.h"
#include<string>


istream& operator>> (istream& flux, PrixJournaliers& p){
    flux>>p.DatePrixJournaliers;
    char tmp[1000];
    flux.getline(tmp,1000,';');
    p.SymboleAction=tmp;
    flux>>p.Prix;
    return flux ;
}
ostream& operator<< (ostream& flux, PrixJournaliers& p){
    flux<<p.getDatePrixJournaliers()<<"  "<<p.SymboleAction<<"  "<<p.Prix ;
    return flux;
}


 bool operator==(PrixJournaliers const& a, PrixJournaliers const& b) {
     if (a.getSymboleAction()==b.getSymboleAction()&&a.getDatePrixJournaliers()==b.getDatePrixJournaliers()){
        return true ;
     }else{
      return false ;
     }

 }
