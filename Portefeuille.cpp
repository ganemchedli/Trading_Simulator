#include <iostream>
#include<string>
#include"Portefeuille.h"
#include"Titre.h"

using namespace std;


PorteFeuille::PorteFeuille(double b=0)
{
    Solde=b;
}

double PorteFeuille:: getSolde() const
{
    return Solde ;
}

void PorteFeuille::setSolde(double a )
{
    Solde=a ;
}


int PorteFeuille :: getNombreTitre() const
{
    return Tab.size() ;
} ;


Titre* PorteFeuille::rechercherTitre(string a )
{




    Titre* titre = NULL ;
    unsigned int i=0 ;
    bool trouve = false ;

    do {
        if(Tab.size()==0){
            trouve=true ;
        }
        else if(a == Tab.at(i).getSymbole() && Tab.size()!=0 ) {
            titre=&Tab.at(i) ;
            trouve=true ;
        }
        i++ ;
        if(i==Tab.size()) {
            trouve=true;
        }


    } while(trouve==false) ;


    /*Titre* titre = NULL ;
    if(Tab.size()!=0) {
        for(int i=0;i<this->getNombreTitre();i++)
        {
            if (Tab[i].getSymbole()==a )
            {
                titre=&Tab[i];
            }

        }
    }*/
    return(titre);
}


void PorteFeuille::AjouterTitre(Titre T)
{
    Titre* titre=rechercherTitre(T.getSymbole());
    if (titre != NULL) {
        titre->AjouterQuantite(T.getQuantite()) ;
    } else {
        Tab.push_back(T);
    }
}


void PorteFeuille::RetirerTitre(string a,int b)
{

    int i = 0 ;
    Titre* titre=rechercherTitre(a);
    if (titre!=NULL) {
        if (titre->getQuantite()==b) {
            while(titre->getSymbole()!=Tab.at(i).getSymbole()) {
                i++ ;
            }
            Tab.erase(Tab.begin()+i);
        } else if(titre->getQuantite() > b) {
            titre->RetirerQuantite(b);

        }
    } else {
        cout<<"Portefeuille est vide" << endl ;
    }
}


Titre PorteFeuille::getTitre(int i) const
{

    return this->Tab.at(i) ;
} ;

ostream& operator<< (ostream& flux, PorteFeuille& p) {

       for( int i=0 ; i < p.getNombreTitre();i++){
      flux<< "Titre\t" << p.getTitre(i).getSymbole()<<"  "<<p.getTitre(i).getQuantite()<<endl ;

    }
    return flux ;


}


