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
    return giorni*TARIFFA_VELA*barche[posto-1].getLunghezza();
  else
	  return giorni*TARIFFA_MOTORE*barche[posto-1].getStazza();
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


const float Porto::TARIFFA_VELA = 10; // per metro al giorno
const float Porto::TARIFFA_MOTORE = 20; // per tonnellata al giorno
