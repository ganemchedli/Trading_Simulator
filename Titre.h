#ifndef TITRE_H_INCLUDED
#define TITRE_H_INCLUDED
#include<string>
using namespace std ;
class Titre
{
    string Symbole ;
    int Quantite ;
public:
    Titre(){} ;
    Titre(string,int);
    string getSymbole()const;
    int getQuantite()const;
    void setSymbole(string) ;
    void setQuantite(int);
    void AjouterQuantite(int);
    void RetirerQuantite(int);
    ~Titre(){};
};


#endif // TITRE_H_INCLUDED
