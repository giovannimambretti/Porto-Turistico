
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

 Barca(void);
 Barca (string  _nome, string _nazione, float _lunghezza, float _stazza, bool _vela);

 void setNome(string _nome);  //correzione metodo set
 void setNazione(string _Nazione);  //correzione metodo set
 void setLunghezza(float _lunghezza); //implementazione metodi set 
 void setStazza(float _stazza);//implementazione metodi set 

 
 string getNome(void);    //aggiunta metodo getNome
 string getNazione(void);  //aggiunta metodo getNazione
 float getLunghezza(void);
 float getStazza(void) ;
 bool isVela(void);
};


