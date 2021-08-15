#include"Titre.h"
#include<string>
using namespace std ;
Titre::Titre(string name,int q=0):Symbole(name),Quantite(q) {}

string Titre::getSymbole()const
{
    return(Symbole);
}

int Titre::getQuantite()const
{
    return(Quantite);
}

void Titre:: setSymbole(string a)
{
    Symbole=a ;
} ;

void Titre :: setQuantite(int a)
{
    Quantite = a ;
};

void Titre::AjouterQuantite(int q)
{
    this->Quantite+=q;
}
void Titre::RetirerQuantite(int q)
{
    this->Quantite-=q;
}
