#include<string>
#include<iostream>
#include"Bourse.h"
#include"BourseListe.h"
#include"PrixJournaliers.h"
#include <fstream>
#include<vector>
#include<list>





using namespace std ;


BourseListe::BourseListe(Date date,vector<PrixJournaliers> historique):Bourse(date,historique)
{

    for (vector<PrixJournaliers>::iterator it = historique.begin(); it !=historique.end(); it++){
        Historique.push_back(*it);
    }

}


PrixJournaliers* BourseListe::rechercherPrixActionDate(string S, Date d)
{
    PrixJournaliers* prix = NULL ;
    list<PrixJournaliers>::iterator it = Historique.begin() ;
    bool trouve = false ;
    do{
           // cout<<"au cours de recherche"<<endl ;
        if(S == (*it).getSymboleAction() && d == (*it).getDatePrixJournaliers()) {
            prix=&(*it) ;
            trouve=true ;
        }
        it++;

      }while(trouve== false || it!=Historique.end()) ;

    return prix;
};


PrixJournaliers* BourseListe::rechercherPrixActionAujourdhui(string sym)
{



    PrixJournaliers* prix = NULL ;
   list<PrixJournaliers>::iterator it = Historique.begin() ;
    bool trouve = false ;

   do {
        if(sym == (*it).getSymboleAction() && DateAujourdhui==(*it).getDatePrixJournaliers()) {
            prix=&(*it);
            trouve=true ;
        }
        it++ ;


    } while(trouve==false||it==Historique.end()) ;

    return prix;


}

void BourseListe::AffichePrixJournaliers(Date d )
{
    for(list<PrixJournaliers>::iterator it = Historique.begin() ; it != Historique.end(); it++) {
        if ((*it).getDatePrixJournaliers()==d){
        cout<<"  "<<(*it)<<endl;
        }
    }
}

