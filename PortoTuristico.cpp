// PortoTuristico.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


#include <cstring>
#include <cstdio>

#include "Barca.h"
#include "Porto.h"

int _tmain(int argc, _TCHAR* argv[])
{
 Porto porto;
 Barca barca, barche[100];
 int scelta;
 std::string nome;
 std::string nazione;
 float lunghezza, stazza;
 char tipo;
 int posto, giorni;
 float importo;
 float minimo, massimo;
 int i, n;

 do {
     cout << "1 => arrivo Vela\r\n";
	 cout << "2 => arrivo Motore\r\n";
	 cout << "3 => Partenza\r\n";
	 cout << "4 => Informazioni\r\n";
	 cout << "5 => Cerca\r\n";
	 cout << "0 => Fine\r\n";
	 cin >> scelta ;
	 switch (scelta)
	       {
			case 1:		cout << "Nome? "; cin >> nome;
						cout << "Nazione? "; cin >> nazione;
						cout << "Lunghezza? "; cin >> lunghezza;
						cout << "Stazza? "; cin >> stazza;
						barca = Barca(nome, nazione, lunghezza, stazza, true);
						if ((posto = porto.arrivo(barca)) < 0)
						  cout << "Nessun posto disponibile!\r\n";
						else
						  cout << "Assegnato posto "  <<  posto << "\r\n";
						break;
			case 2:		cout << "Nome? "; cin >> nome;
						cout << "Nazione? "; cin >> nazione;
						cout << "Lunghezza? "; cin >> lunghezza;
						cout << "Stazza? "; cin >> stazza;
						barca = Barca(nome, nazione, lunghezza, stazza, false);
						if ((posto = porto.arrivo(barca)) < 0)
						  cout << "Nessun posto disponibile!\r\n";
						else
						  cout << "Assegnato posto "  << posto << "\r\n";
						break;
			case 3:		  cout << "Posto? "; cin >> posto;
						  cout << "Giorni? "; cin >> giorni;
						if ((importo = porto.partenza(posto, giorni)) == 0)
						  cout << "Posto errato!\r\n";
						else
							cout << "Importo: \r\n"  << importo;
						break;
			case 4:		   cout << "Posto? "; cin >> posto;
						barca = porto.informazioni(posto);
						if (barca.getLunghezza() == 0)
						   cout << "Posto errato!\r\n";
						else
						    {
							 barca.getNome(nome);
							 barca.getNazione(nazione);
							 lunghezza = barca.getLunghezza();
							 stazza = barca.getStazza();
							 tipo = barca.isVela() ? 'V' : 'M';
							 cout << nome << nazione << lunghezza << stazza << tipo;
						    }
						break;
			case 5:		     cout << "Lunghezza minima? " ; cin >> minimo;
						     cout << "Lunghezza massima? " ; cin >> massimo;
						n = porto.cerca(minimo, massimo, barche);
						for (i=0; i<n; i++)
						   {
							barche[i].getNome(nome);
							barche[i].getNazione(nazione);
							lunghezza = barche[i].getLunghezza();
							stazza = barche[i].getStazza();
							tipo = barche[i].isVela() ? 'V' : 'M';
							cout << nome << nazione << lunghezza << stazza << tipo;
						   }
						break;
			default:
			case 0:		break;
	       }
    } while (scelta!=0);
}
