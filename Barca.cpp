#include "Barca.h"
#include <string>

using namespace std;

 Barca::Barca(void)
 {
  nome = "";
  nazione= "???";
  lunghezza = 0;
  stazza = 0;
  vela = false;
 }

 Barca::Barca (string _nome, string _nazione, float _lunghezza, float _stazza, bool _vela)
 {
  nome =_nome;
  nazione = _nazione;
  lunghezza = _lunghezza;
  stazza = _stazza;
  vela = _vela;
 }

 void Barca::getNome(string _nome) { _nome = nome; }
 void Barca::getNazione(string _nazione) { _nazione = nazione; }
 float Barca::getLunghezza(void) { return lunghezza; }
 float Barca::getStazza(void) { return stazza; }
 bool Barca::isVela(void) { return vela; }
