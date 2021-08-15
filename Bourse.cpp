#include<string>
#include"Bourse.h"
#include"PrixJournaliers.h"

Bourse::Bourse(string a):Nom(a){
};

int Bourse::ChercherAction(string S){
    int r = -1;
    for(int i=0;i<TabDuPrix.size();i++){
        if(S==TabDuPrix.at(i).getSymboleAction()){
           r=i;
           break ;
        }

    }
    return r ;



};


void Bourse::AffichePrixJournaliers(Date DateDeb ,Date DateFin){

} ;

