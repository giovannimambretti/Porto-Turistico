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
 float tariffav=10, tariffam=20;
 do {
     cout << "1 => arrivo Vela\r\n";
	 cout << "2 => arrivo Motore\r\n";
	 cout << "3 => modifica tariffa vela\r\n";
	 cout << "4 => modifica tariffa motore\r\n";
	 cout << "5 => Partenza\r\n";
	 cout << "6 => informazioni\r\n";
	 cout << "7 => cerca \r\n";
	 cout << "8 => modifica imbarcazione \r\n";
	 cout << "0 => Fine\r\n";
	 cin >> scelta ;
	 switch (scelta)
	       {
			case 1:		cout << "Nome? "; cin >> nome;
						cout << "Nazione? "; cin >> nazione;
						cout << "Lunghezza? (in metri) "; cin >> lunghezza; //aggiunta unità di misura
						cout << "Stazza? (in tonnelate)"; cin >> stazza; //aggiunta unità di misura
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
			case 3:
				cout<<"modifica tariffa vela\n";
				cin>>tariffav;
				porto.setTariffa_vela(tariffav);
				cout<<"cambio tariffa riuscito\n";
				cout<<porto.getTariffa_vela()<<"\n"; // questa riga di codice fa vedere che effetivamente è cambiata la tariffa
				break;
				
			case 4:
				cout<<"modifica tariffa motore\n";
				cin>>tariffam;
				porto.setTariffa_motore(tariffam);
				cout<<"cambio tariffa riuscito\n";
				cout<<porto.getTariffa_motore()<<"\n"; // questa riga di codice fa vedere che effetivamente è cambiata la tariffa
				break;
					
			case 5:		 
							porto.setTariffa_vela(tariffav); // qui si passa per i metodi setTariffa_vela e setTariffa_motore perchè se uno non passa per i punti 3 e 4 del menù prende il valore iniziale settato a 10 e 20
							porto.setTariffa_motore(tariffam);
						  cout << "Posto? "; cin >> posto;
						  cout << "Giorni? "; cin >> giorni;
						if ((importo = porto.partenza(posto, giorni)) == 0)
						  cout << "Posto errato!\r\n";
						else
							cout << "Importo: \r\n"  << importo <<"\n";
						break;
			case 6:		   cout << "Posto? "; cin >> posto;
						barca = porto.informazioni(posto);
						if (barca.getLunghezza() == 0)
						   cout << "Posto errato!\r\n";
						else
						    {
							 nome=barca.getNome(); //qui è get perchè se no modifica il nome
							 nazione=barca.getNazione(); //qui è get perchè se no modifica la nazione
							 lunghezza = barca.getLunghezza();
							 stazza = barca.getStazza();
							 tipo = barca.isVela() ? 'V' : 'M';
							 cout << nome <<"\n" << nazione <<"\n" << lunghezza <<"\n" << stazza <<"\n" << tipo <<"\n"; //aggiunto /n per migliorare la grafica
						    }
						break;
			case 7:		     cout << "Lunghezza minima? " ; cin >> minimo;
						     cout << "Lunghezza massima? " ; cin >> massimo;
						n = porto.cerca(minimo, massimo, barche);
						for (i=0; i<n; i++)
						   {
							nome=barche[i].getNome(); //qui è get perchè se no modifica la nazione
							nazione=barche[i].getNazione(); //qui è get perchè se no modifica la lunghezza
							lunghezza = barche[i].getLunghezza();
							stazza = barche[i].getStazza();
							tipo = barche[i].isVela() ? 'V' : 'M';
							cout << nome <<"\n"<< nazione<<"\n" << lunghezza<<"\n" << stazza<<"\n" << tipo<<"\n"<<"posto n:"<<posto<<"\n"; //aggiunto /n per migliorare la grafica e aggiunta stampa numero posto
						   }
						break;
			case 8
				
				:
						cout << "Posto? "; cin >> posto;
						barca = porto.informazioni(posto);
						if (barca.getLunghezza() == 0)
						   cout << "Posto errato!\r\n";
						else
						{
							cout << "Nome? "; cin >> nome;
						cout << "Nazione? "; cin >> nazione;
						cout << "Lunghezza? "; cin >> lunghezza;
						cout << "Stazza? "; cin >> stazza;
						
							barca = porto.modifica(posto,nome,nazione,lunghezza,stazza);
							cout<<"informazioni modificate\n";
						}
						break;
			default: cout<<"scelta sbagliata selezionare i numeri da 0 a 8\n"; //aggiunta output se qualcuno aggiunge un numero non presente sul menù
			case 0:	
				break; 
	       }
    } while (scelta!=0);
}



