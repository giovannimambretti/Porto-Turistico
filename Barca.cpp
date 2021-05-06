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

 void Barca::setNome(string _nome) {nome= _nome;}
 void Barca::setNazione(string _nazione) {nazione= _nazione;}
 void Barca::setLunghezza(float _lunghezza ) {lunghezza= _lunghezza;}
 void Barca::setStazza(float _stazza) {nome= _stazza;}
 string Barca::getNome(void){return nome;}
 string Barca::getNazione(void){return nazione;}
 float Barca::getLunghezza(void){return lunghezza;}
 float Barca::getStazza(void){return stazza;}
 bool Barca::isVela(void){return vela;}
