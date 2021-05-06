#pragma once
#include "Barca.h"

using namespace std;

class Porto
{
 private:

 bool occupato[100];
 Barca barche[100];
 static const float TARIFFA_VELA;
 static const float TARIFFA_MOTORE;

 public:

 Porto(void);
 
 int arrivo(Barca barca);

 float partenza(int posto, int giorni);

 Barca informazioni(int posto);

 int cerca(float minimo, float massimo, Barca imbarcazioni[]);
};
