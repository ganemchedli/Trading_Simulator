#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
using namespace std ;
class Date
{
private:
    int Mois,Jour,Annee ;
public:
    Date();
    Date(int, int, int);
    int getMois() const ;
    int getJour() const ;
    int getAnnee() const ;
    friend bool operator==(Date const& a, Date const& b) ;
    friend ostream& operator<< (ostream& flux, const Date& d) ;
    friend istream& operator>> (istream& flux, Date& d) ;
    friend bool operator<=(Date const& a, Date const& b) ;
    friend bool operator>=(Date const& a, Date const& b) ;
    friend Date operator+(Date  &d ,unsigned int a);
    friend bool operator!=(Date const& , Date const&);
    ~Date() {}
    friend class Simulator ;
};

#endif // DATE_H_INCLUDED
