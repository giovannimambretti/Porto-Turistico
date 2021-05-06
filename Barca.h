#pragma once
#include <string>    // utilizza gli oggetti di Classe string

using namespace std; // serve per non dover sempre dereferenziare gli oggetti di std

class Barca
{
 private:

 string nome;      // utilizzo di oggetto string per rappresentare una stringa di caratteri
 string nazione;
 float lunghezza;
 float stazza;
 bool vela;

 public:

 Barca(voidnome, string _nazione, float _lunghezza, float _stazza, bool _vela);

 void getNome(string _nome) ;
 void getNazione(string _nazione);
 float g
);
 Barca (string  _
etLunghezza(void);
 float getStazza(void) ;
 bool isVela(void);
};
