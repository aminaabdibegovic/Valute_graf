#include "Valute.h"
#include<iomanip>
#include<cmath>

int main(){

   OdnosValuta G;

   G.dodajNoviOdnos("USD","GBP",0.7871);
   G.dodajNoviOdnos("USD","JPY",148.1115);
   G.dodajNoviOdnos("EUR","BAM",1.9558);
   G.dodajNoviOdnos("USD","EUR",0.9179);
   G.dodajNoviOdnos("TRY","DKK",0.2263);
   G.dodajNoviOdnos("TRY","JPY",4.8975);
   G.dodajNoviOdnos("RSD","TRY",0.2811);
   G.dodajNoviOdnos("EGP","DKK",0.2215);
   G.dodajNoviOdnos("AUD","USD",0.6586);
   G.dodajNoviOdnos("AUD","CAD",0.8844);
   G.dodajNoviOdnos("CHF","GBP",0.9069);
   G.dodajNoviOdnos("RUB","RSD",1.2203);
   G.dodajNoviOdnos("CAD","EUR",0.6835);

  //direktna grana
   //cout<<G.vratiOdnos("EUR","BAM")<<endl;
   //povratna
   // cout<<G.vratiOdnos("BAM","EUR")<<endl;

   // cout<<G.vratiOdnos("AUD","RSD")<<endl;
     //obrisem granu AUD-USD, treba isto vratit
     //obrisem i granu USD-JPY, treba vratiti 0
    //cout<<G.vratiOdnos("AUD","RSD")<<endl;

    //cout<<G.vratiOdnos("CHF","EUR")<<endl;
    //obrisem USD-EUR
    //cout<<G.vratiOdnos("CHF","EUR")<<endl;
    //obrisem i usd-aud, treba 0


    //cout<<G.vratiOdnos();
    //obrisi granu
}
