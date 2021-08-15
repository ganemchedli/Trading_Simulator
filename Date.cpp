#include"Date.h"
#include <iostream>
#include<string>
using namespace std ;


Date::Date()
{
    Mois = 0, Jour = 0, Annee = 0;
}
Date::Date(int Day, int Month, int Year)
{
    Jour = Day;
    Mois = Month;
    Annee = Year;
}

int Date::getMois() const
{
    return Mois;
}
int Date::getJour() const
{
    return Jour ;
}
int Date::getAnnee() const
{
    return Annee ;
}

bool operator==(Date const& a, Date const& b)
{

    if (a.Jour == b.Jour && a.Mois == b.Mois && a.Annee == b.Annee)
        return true;
    else
        return false;
}

ostream& operator<< (ostream& flux, const Date& d)
{
    flux<<d.getJour()<<"/"<<d.getMois()<<"/"<<d.getAnnee() ;
    return flux;
}

istream& operator>> (istream& flux, Date& d)
{
    char tmp[1000] ;
    flux.getline(tmp,1000,'/');
    d.Jour=atoi(tmp);
    flux.getline(tmp,1000,'/');
    d.Mois=atoi(tmp);
    flux.getline(tmp,1000,';');
    d.Annee=atoi(tmp);
    return flux ;
}

bool operator<=(Date const& a, Date const& b)
{

    if(a.Annee<=b.Annee && a.Mois <=b.Mois && a.Jour<=b.Jour) {
        return true ;
    } else {
        return false ;
    }

} ;

bool operator>=(Date const& a, Date const& b)
{
    if(a.Annee>=b.Annee && a.Mois >=b.Mois && a.Jour>=b.Jour) {
        return true ;
    } else {
        return false ;
    }
} ;

Date operator+(Date  &d ,unsigned int a)
{
    Date date = d ;
    int tmp = date.Jour+a ;
    if(date.Mois!=12){
        if(tmp==31){
                date.Jour=31 ;

        }else if (tmp > 31){
          date.Jour=tmp-31;
          int mois = date.Mois+1 ;
          date.Mois=mois ;
        }else{
            date.Jour=tmp ;
         }
    }else {
        if(tmp==31){
                date.Jour=31 ;

        }else if (tmp > 31){
          date.Jour=tmp-31;
          date.Mois= 1 ;
          date.Annee=date.Annee+1 ;
        }else{
            date.Jour=tmp ;
         }

    }


return date;
}









bool operator!=(Date const& a, Date const& b)
{
    if(a.Annee!=b.Annee || a.Mois !=b.Mois || a.Jour!=b.Jour) {
        return true ;
    } else {
        return false ;
    }
};

