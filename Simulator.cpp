#include"Simulator.h"
#include"Bourse.h"
#include"PrixJournaliers.h"
#include"Portefeuille.h"
#include"Titre.h"
#include"Date.h"
#include<string>
#include"Trader.h"

#include<fstream>
using namespace std ;

Simulator::Simulator(Date d, Date b,int Nbj,double m, Trader* trader, Bourse* brs ):DateDepart(d),DateDeJour(b),NbJours(Nbj),MontantDepart(m),P(m),T(trader),bourse(brs)
{

}
Date Simulator:: getDateDeDepart() const
{
    return DateDepart;
}
int Simulator::getNbDeJours() const
{
    return NbJours;
}
double Simulator::getMontantDepart() const
{
    return MontantDepart;
}

Date Simulator :: getDateDeJours() const
{
    return DateDeJour ;
}

void Simulator::setDateDeJour(Date d )
{
    DateDeJour=d ;
}



void Simulator :: AppliquerTransaction(Transaction T)        //transaction le decision(achat , vente ou rien faire ) , symbole de l'action et quantite
{
    if (T.getDecision()== 0) {             // Acheter
        PrixJournaliers* prixjournaler=bourse->rechercherPrixActionAujourdhui(T.getTitre().getSymbole()); //pointeur sur le titre désiré
        if(prixjournaler!= NULL) {
            if (P.getSolde()>=( (prixjournaler->getPrix())*(T.getTitre().getQuantite() ) ) ) {
                P.AjouterTitre(T.getTitre());
                double prix=((prixjournaler->getPrix())*T.getTitre().getQuantite()); // calculer le montant d'achat
                P.setSolde(P.getSolde()-prix); //retirer le montant de solde de portefeuille
            } else {
                setDateDeJour(DateDeJour+1);
                bourse->setDateAujourdhui(DateDeJour) ;
                cout<<"passe au jour suivant"<<endl ;

            }
        }
    } else if (T.getDecision()== 1) {      // vendre
        if(P.getNombreTitre()!=0&&P.rechercherTitre(T.getTitre().getSymbole())!=NULL) {
            Titre* titre=P.rechercherTitre(T.getTitre().getSymbole()); // POINTEUR SUR LE TITRE DANS LE PORTEFEUILLE
            PrixJournaliers* prixjournaler=bourse->rechercherPrixActionAujourdhui(T.getTitre().getSymbole());
            if ( titre->getQuantite()>=T.getTitre().getQuantite()&& titre!=NULL ) {

                P.RetirerTitre(T.getTitre().getSymbole(),T.getTitre().getQuantite());
                double prix=((prixjournaler->getPrix())*T.getTitre().getQuantite());         //calcul de prix de vente
                P.setSolde(P.getSolde()+prix);
            } else {
                setDateDeJour(DateDeJour+1);
                bourse->setDateAujourdhui(DateDeJour) ;
                cout<<"passe au jour suivant"<<endl ;

            }

        } else {
            setDateDeJour(DateDeJour+1);
            bourse->setDateAujourdhui(DateDeJour) ;
            cout<<"passe au jour suivant"<<endl ;

        }
    } else  {   // RienFaire
        setDateDeJour(DateDeJour+1);
        bourse->setDateAujourdhui(DateDeJour) ;
        cout<<"passe au jour suivant"<<endl ;

    }

}








void Simulator::AfficheDetailPortefeuille()
{
    double solde=0 ;
    string action ;
    if(P.getNombreTitre()!=0) {
        for( int i=0; i<P.getNombreTitre(); i++) {                                     // Calcul de prix total des actions dans le jour courant
            PrixJournaliers* prixjournaler=bourse->rechercherPrixActionAujourdhui(P.getTitre(i).getSymbole());
            if(prixjournaler!=NULL) {
                solde+=(prixjournaler->getPrix())*(P.getTitre(i).getQuantite());
            } else {
                continue;
            }
        }

        cout<< endl <<endl <<"Detail de Portefuille"<<endl;
        cout<<"Les actions en possession :"<<endl;
        for(int i=0; i<P.getNombreTitre(); i++) {
            action=P.getTitre(i).getSymbole();
            PrixJournaliers* prixjournaler=bourse->rechercherPrixActionAujourdhui(P.getTitre(i).getSymbole());
            if(prixjournaler!=NULL) {
                double prix = prixjournaler->getPrix() ;
                cout<< action <<"\t"<< "quantite:"<<P.getTitre(i).getQuantite()<<"\t"<<"prix unitaire" << prix << endl << endl;
            } else {
                continue ;
            }
        }
    }
    cout<<"Montant restant:"<<P.getSolde()<<endl;
    cout<<"Le solde totale de portefeuille est :"<<solde+P.getSolde()<<endl;

}



double Simulator::CalculResultat()
{

    double resultat ;
    resultat=P.getSolde()- MontantDepart;
    return resultat ;
}

void Simulator::LancerUneSimulation() // LANCER UNE SIMULATION de debut à la fin
{



    while(DateDeJour != DateDepart+NbJours) {
        cout<< endl<<endl<<endl ;
        this->AppliquerTransaction(T->PrendreDecision(*bourse,P) ) ;
        int i = 0 ;
        cout<<"Date d'aujourd'hui \t"<<bourse->getDateAujourdhui()<<endl ;
        cout<<"voir detail portefeuille maintenat (cliquer sur 1) " << endl ;
        cin >> i ;
        if(i==1) {
            this->AfficheDetailPortefeuille() ;
        } else {
            continue ;
        }
    };


}


Simulator :: ~Simulator()
{
    delete T ;
    delete bourse ;
}




















