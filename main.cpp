#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<windows.h>
#include"Date.h"
#include"PrixJournaliers.h"
#include"Portefeuille.h"
#include"Titre.h"
#include"Trader.h"
#include"TraderHumain.h"
#include"TraderAletoire.h"
#include"TraderAlgo.h"
#include"Bourse.h"
#include"BourseListe.h"
#include"BourseVector.h"
#include"Transaction.h"
#include"Simulator.h"
#include<cstdlib>
#include<ctime>

using namespace std;
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c =  {x,y} ;
    SetConsoleCursorPosition(h,c);
}
int main()
{

    int choix, mode, nombre, stl, jour,mois, annee , menu=1;
    string id ;
    double montant, resultat ;
    Trader* t;
    Bourse* b;
    srand((unsigned) time(0));
    string const AnciennesSimulation("Historique.txt");
    vector<PrixJournaliers> Historique ;

    ifstream f("prices_simple.csv");

    if(f.is_open()) {

        while(!f.eof()) {

            PrixJournaliers* P = new PrixJournaliers ;
            f >> (*P) ;
            Historique.push_back(*P);


        };
    };

    while(menu==1){
    system("cls");
    color(10,0);
    gotoxy(25,2);
    cout<<"\t\t\tSimalateur Trading version 1.0"<<endl;
    gotoxy(25,3);
    cout<<"\t\t\t------------------------------"<<endl;
    gotoxy(25,7);
    cout<<"1. LANCER UNE SIMULATION"<<endl;
    gotoxy(25,10);
    cout<<"2. CONSULTER L'HISTORIQUE"<<endl;
    gotoxy(25,15);
    cin>>choix ;
    switch(choix) {
    case 1 : {
        system("cls");
        cout<<"Selectionner une date de depart (jour,mois,annee) \t" ;
        do{
        cin >> jour >> mois >> annee ;
        if(annee>2016||annee<2010){cout << "La date doit etre comprise entre les annees 2010 et 2016 ! Entree une autre date s'il vous plait : \n ";}
        }while( annee < 2010 || annee > 2016);
        Date const date_depart(jour,mois,annee) ;
        Date date_jour(jour,mois,annee);
        cout<<endl <<"Entrer un montant de depart\t"<<endl ;
        do {
            cin >> montant ;
            if (montant<=0){cout << "Vous ne pouvez pas commmencer une simulation avec ce montant! Entree une autre montant s'il vous plait : \n ";}
        } while(montant<=0);
        cout<<endl<<"Entrer un nombre de jour pour cette simulation\t"<<endl ;
        do {
            cin>>nombre;
        } while(nombre<=0) ;
        cout<<endl<<"Selectionner un mode de decision : 1.Manuel  2.Aleatoir  3.Algorithmique\t"<<endl ;
        do {
            cin >>mode;
        } while(mode!=1 && mode!=2 && mode!=3);
        cout<<endl<<"Donner un identifiant au trader\t"<<endl ;
        cin>> id ;
        if(mode==1) {
            t =new TraderHumain(id) ;

        } else if (mode==2){
            t=new TraderAleatoire(id) ;
        }else{
          t=new TraderAlgo(id) ;
        }
        cout<<endl<<"Selectionner type de bourse : 1.Vector 2.Liste \t" ;
        while(stl!=1 && stl!=2) {
            cin>>stl ;
        }
            if(stl==1) {
                b= new BourseVector(date_jour,Historique) ;
            }else{
                b= new BourseListe(date_jour,Historique) ;
                }
             system("cls");
            Simulator simulation(date_depart,date_jour,nombre,montant,t,b);

            ofstream monFlux(AnciennesSimulation.c_str(),ios::app);
            if(monFlux) {
                monFlux<<"------------------------------------------"<<endl ;
                monFlux<<endl <<"Historique de Simulation\t"<<"Date de depart\t"<<simulation.getDateDeDepart()<<endl<<endl;
                monFlux<<"ID de trader:  "<<t->getId() <<endl;
                monFlux<<"Nombre de jour de simulation:\t"<<simulation.getNbDeJours()<<endl ;
                monFlux<<"Montant de depart:\t"<<simulation.getMontantDepart()<<endl;
                simulation.LancerUneSimulation();
                resultat=simulation.CalculResultat();
                monFlux<<"Resultat finale:\t"<<resultat+simulation.getMontantDepart()<<"\t"<< (resultat/simulation.getMontantDepart())*100<<"%"<<endl;
                monFlux<<"--------------------------------------------"<<endl;
            } else {
                cout<<"ERREU: Impossible d'ouvrir le fichier en ecriture "<<endl;
            }
        }

    break ;

    case 2 : {
        system("cls") ;
        ifstream fichier("Historique.txt");
        if(fichier) {

            string ligne ;
            while(getline(fichier,ligne)) {
                cout<<ligne<<endl;
            }
        } else {
            cout<<"Erreur: Impossible d'ouvrir le fichier en lecture"<<endl;
        }
    }
    break;
    }

    cout<< endl<< endl <<"Pour retour au menu cliquer .1 // Pour sortir de l'application cliquer .2"<<endl ;
    cin >> menu ;
    system("cls");

}

 cout << endl<<endl<<"SEE YOU SOON" ;
 return 0 ;
}
