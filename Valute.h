#ifndef Valute_h
#define Valute_h
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

using namespace std;


class OdnosValuta{
   struct PairHash {
        size_t operator () (const pair<string,string>& p) const {
        auto hash1 = std::hash<string>{}(p.first);
        auto hash2 = std::hash<string>{}(p.second);

        // Kombiniranje hash vrijednosti
        return hash1 ^ hash2;
    }
   };
   unordered_map<string, vector<pair<string, double>>> lista_susjedstva;
   unordered_map<pair<string,string>, double, PairHash> mapa_odnosa;
   public:
   void dodajNoviOdnos(string s1,string s2, double vr);
   void ispisiOdnose();
   double vratiOdnos(string s1,string s2);
   void BFS(queue<string>&red ,unordered_map<string,double>&udaljenosti);
   string vratiPresjecni(unordered_map<string,double>&udaljenosti_pocetni,unordered_map<string,double>&udaljenosti_krajnji);
};



#endif // Valute_H
