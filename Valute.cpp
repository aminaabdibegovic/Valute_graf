#include "Valute.h"
#include<iostream>
#include<unordered_map>
#include<climits>
#include<set>
#include<cmath>
#include<iomanip>


using namespace std;


void OdnosValuta ::dodajNoviOdnos(string s1,string s2, double vr){

      if(mapa_odnosa.find(make_pair(s1,s2)) != mapa_odnosa.end())
        cout<<"Unijeli ste vec postojeci odnos."<<endl;
      else{
        mapa_odnosa[make_pair(s1,s2)] = vr ;
        lista_susjedstva[s1].push_back(make_pair(s2,vr));
        lista_susjedstva[s2].push_back(make_pair(s1,1/vr));

      }
}

void OdnosValuta::ispisiOdnose(){

    for(auto par : mapa_odnosa)
        cout<<"{"<<par.first.first<< "," << par.first.second << "," << par.second<<"}" << endl ;
  }


double OdnosValuta ::vratiOdnos(string pocetni, string krajnji) {
  int n = lista_susjedstva.size();
  unordered_map<string,double> udaljenost;

  for (const auto& par : lista_susjedstva) {
        udaljenost[par.first] = -1;
  }

  udaljenost[pocetni] = 1.0;
  queue<string> red;
  red.push(pocetni);
  double odnos = 1.0 ;


  while(!red.empty()) {
    string trenutni = red.front();
    red.pop();
    for(auto el:lista_susjedstva[trenutni]) {
       if(udaljenost[el.first] == -1) {
         udaljenost[el.first] = round((udaljenost[trenutni] * el.second) * 10000.0) / 10000.0 ;

          red.push(el.first);
       }
    }
    if(udaljenost[krajnji] != -1)
       return round(udaljenost[krajnji] * 1000.0) / 1000.0;

  }
  return 0 ;

}


//druga verzija preko BFS-a, mozda brza
/*

double OdnosValuta ::vratiOdnos(string pocetni,string krajnji){
  int n = lista_susjedstva.size();
  unordered_map<string,double> udaljenost_pocetni;
  unordered_map<string,double> udaljenost_krajnji;


  for (const auto& par : lista_susjedstva) {
        udaljenost_pocetni[par.first] = -1;
        udaljenost_krajnji[par.first] = -1;

  }

  udaljenost_pocetni[pocetni] = 1.0;
  udaljenost_krajnji[krajnji]=1.0;

  queue<string> red_pocetni;
  queue<string> red_krajnji;
  red_pocetni.push(pocetni);
  red_krajnji.push(krajnji);

  string presjekCvor="-1";
  double odnos = 1.0;
  while(!red_pocetni.empty() && !red_krajnji.empty()){
      BFS(red_pocetni,udaljenost_pocetni);
      BFS(red_krajnji,udaljenost_krajnji);

      presjekCvor = vratiPresjecni(udaljenost_pocetni,udaljenost_krajnji);
      if(presjekCvor!= ""){
          return round((udaljenost_pocetni[presjekCvor] * 1/udaljenost_krajnji[presjekCvor]) * 1000.0) / 1000.0 ;
      }
  }
  return 0 ;
}
void OdnosValuta ::BFS(queue<string>&red ,unordered_map<string,double>&udaljenosti){
    string trenutni = red.front();
    red.pop();
    for(auto par : lista_susjedstva[trenutni]){
        if(udaljenosti[par.first]==-1){
            udaljenosti[par.first]=round((udaljenosti[trenutni] * par.second) * 10000.0 ) / 10000.0;
            red.push(par.first);
        }
    }
};

string OdnosValuta ::vratiPresjecni(unordered_map<string,double>&udaljenosti_pocetni,unordered_map<string,double>&udaljenosti_krajnji){
    string presjecniCvor="";
    for(auto par : lista_susjedstva)
        if(udaljenosti_pocetni[par.first]!=-1 && udaljenosti_krajnji[par.first]!=-1)
           return par.first;
    return "";
}
*/
