#include "Barca.h"
#include "Porto.h"
 Porto::Porto(void)
 {
  for (int posto=0; posto<100; posto++)
     occupato[posto] = false;
 }

 int Porto::arrivo(Barca barca)
 {
	 if (barca.isVela())
    {
	 for (int posto=51; posto<=100; posto++)
	    if (!occupato[posto-1])
		  {
		   barche[posto-1] = barca;
		   occupato[posto-1] = true;
		   return posto;
		  }
	 return -1; // nessun posto libero per barche a vela
    }
  else
      {
	   if (barca.getLunghezza() < 10)
	     for (int posto=1; posto<=20; posto++)
		    if (!occupato[posto-1])
			  {
			   barche[posto-1] = barca;
			   occupato[posto-1] = true;
			   return posto;
			  }
		 for (int posto=21; posto<=100; posto++)
		    if (!occupato[posto-1])
		      {
		       barche[posto-1] = barca;
		       occupato[posto-1] = true;
		       return posto;
		      }
		return -1; // nessun posto libero
      }
 }

 float Porto::partenza(int posto, int giorni)
 {
  if (posto<=0 || posto>= 100)
    return 0;

  if (!occupato[posto-1])
    return 0;
  
  occupato[posto-1] = false;

  if (barche[posto-1].isVela())
    return giorni*tariffa_vela*barche[posto-1].getLunghezza();
  else
	  return giorni*tariffa_motore*barche[posto-1].getStazza();
 }

 Barca Porto::informazioni(int posto)
 {
  Barca barca; // imbarcazione inavlida

  if (posto<=0 || posto>= 100)
    return barca;

  if (!occupato[posto-1])
    return barca;

  return barche[posto-1];
 }

 int Porto::cerca(float minimo, float massimo, Barca imbarcazioni[])
 {
  int numero = 0;

  for (int posto=1; posto<=100; posto++)
     if (occupato[posto-1])
	   if (barche[posto-1].getLunghezza() >= minimo && barche[posto-1].getLunghezza() <= massimo)
	     {
		  imbarcazioni[numero] = barche[posto-1];
		  numero++;
	     }
 return numero;
 }
 void Porto::setTariffa_vela(float tv){tariffa_vela=tv;};
 void Porto::setTariffa_motore(float tm){tariffa_motore=tm;};
 float Porto::getTariffa_vela(void){return tariffa_vela;}
 float Porto::getTariffa_motore(void){return tariffa_motore;}
 
Barca Porto::modifica(int posto, string _nome, string _nazione,float _lunghezza,float _stazza)
{
	barche[posto].setNome(_nome);
	barche[posto].setNazione(_nazione);
	barche[posto].setLunghezza(_lunghezza);
	barche[posto].setStazza(_stazza);
	return barche[posto-1];
 }
