#include<string>
#include<iostream>
#include"Bourse.h"
#include"BourseVector.h"
#include"PrixJournaliers.h"
#include<iterator>
#include <fstream>
#include<vector>
using namespace std ;


BourseVector::BourseVector(Date date,vector<PrixJournaliers> historique):Bourse(date,historique)
{

   for (unsigned int i = 0 ; i < historique.size() ; i++ ){
    Historique.push_back(historique.at(i)) ;
   }


}


PrixJournaliers* BourseVector::rechercherPrixActionDate(string S, Date d)
{
    PrixJournaliers* prix = NULL ;
    unsigned int i=0 ;
    bool trouve = false ;
    do{
        if(S == Historique.at(i).getSymboleAction() && d == Historique.at(i).getDatePrixJournaliers()) {
            prix=&Historique.at(i) ;
            trouve=true ;
        }
        i++;
        if(i==Historique.size()){
            trouve=true ;
        }

    }while(trouve==false) ;

    return prix;
};


PrixJournaliers* BourseVector::rechercherPrixActionAujourdhui(string sym)
{



    PrixJournaliers* prix = NULL ;
    unsigned int i=0 ;
    bool trouve = false ;

   do {
        if(sym == Historique.at(i).getSymboleAction() && DateAujourdhui==Historique.at(i).getDatePrixJournaliers()) {
            prix=&Historique.at(i) ;
            trouve=true ;
        }
        i++ ;
        if(i==Historique.size()){
            trouve=true;
        }


    } while(trouve==false) ;

    return prix;


}


void BourseVector::AffichePrixJournaliers(Date d )
{
    for(unsigned int i=0; i<Historique.size(); i++) {
        if (Historique.at(i).getDatePrixJournaliers()==DateAujourdhui){
        cout<<i<<"  "<<Historique.at(i)<<endl;
        }

    }
} ;
/*
void BourseVector::AffichePrixJournaliers(Date d1, Date& d2) {
    for(unsigned int i=0; i<Historique.size(); i++) {
        if (Historique.at(i).getDatePrixJournaliers()>=d1 && Historique.at(i).getDatePrixJournaliers()<=d2)
        cout<<" "<<Historique.at(i)<<endl;

    }
}

*/
