#include <cstring>
#include <cstdio>

class Barca
{
 private:

 char nome[32];
 char nazione[16];
 float lunghezza;
 float stazza;
 bool vela;

 public:

 Barca(void)
 {
  strcpy(nome, "");
  strcpy(nazione, "???");
  lunghezza = 0;
  stazza = 0;
  vela = false;
 }

 Barca (char _nome[], char _nazione[], float _lunghezza, float _stazza, bool _vela)
 {
  strcpy(nome, _nome);
  strcpy(nazione, _nazione);
  lunghezza = _lunghezza;
  stazza = _stazza;
  vela = _vela;
 }

 void getNome(char* _nome) { strcpy(_nome, nome); }
 void getNazione(char* _nazione) { strcpy(_nazione, nazione); }
 float getLunghezza(void) { return lunghezza; }
 float getStazza(void) { return stazza; }
 bool isVela(void) { return vela; }
};
