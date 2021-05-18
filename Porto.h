
#pragma once
#include "Barca.h"

using namespace std;

class Porto
{
 private:
 

  float tariffa_vela;
  float tariffa_motore;

 public:
 Barca barche[100];
 bool occupato[100];
 Porto(void);
 
 int arrivo(Barca barca);

 float partenza(int posto, int giorni);

 Barca informazioni(int posto);
 int cerca(float minimo, float massimo, Barca imbarcazioni[]);
 void setTariffa_vela(float tv);
 void setTariffa_motore(float tm);
 float getTariffa_vela(void);
 float getTariffa_motore(void);
 Barca modifica(int posto, string _nome, string _nazione,float _lunghezza,float _stazza);
};

