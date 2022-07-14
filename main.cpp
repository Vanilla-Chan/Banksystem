#include "konto.h"
#include "newkonto.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
void printkonto(vector<konto> k,int index);
void newkonto(vector<konto> k);
void kontostand(vector<konto> k,short kontonummer);
void geld_abheben(vector<konto> k,short kontonummer);
void geld_einzahlen(vector<konto> k,short kontonummer);
void ueberweisen(vector<konto> k,short kontonummer);
bool validate(string pw);
void admin();
int main() {
	cout << "Bitte Kontonummer eingeben: ";
	short kontonummer;
	cin >> kontonummer;
	vector<konto> Kontoverwaltung;
	konto test = konto(0110412523,"Julian Siefert",1500,10000,3,10235412);
	Kontoverwaltung.push_back(test);
	Kontoverwaltung.push_back(konto());
	konto gianni = konto(1,"Gianni",1,1,1,1);
	char eingabe;

	do{
		//system("clear");
		cout << "======== Hauptmenü ========" << endl;
		cout << "1) Kontostand anzeigen" << endl;
		cout << "2) Geld abheben" << endl;
		cout << "3) Geld einzahlen" << endl;
		cout << "4) Ueberweisen" << endl;
		cout << "5) Adminfunktionen" << endl;
		cout << "6) Abbruch" << endl;
		short eingabe;
		cin >> eingabe;
		switch(eingabe){
		case 1:
			kontostand(Kontoverwaltung,kontonummer);
			break;
		case 2:
			geld_abheben(Kontoverwaltung,kontonummer);
			break;
		case 3:
			geld_einzahlen(Kontoverwaltung,kontonummer);
			break;
		case 4:
			ueberweisen(Kontoverwaltung,kontonummer);
			break;
		case 5:{
			cout << "Bitte geben Sie das Adminpasswort ein : ";
			string adminpw;
			cin >> adminpw;
			if(validate(adminpw)){
				admin();
				break;
			}
			else{
				cout << "Falsches Adminpasswort Programm wird beendet!!!" << endl;
				return 0;
				break;
			}}
		case 6:
			cout << "Das Programm wird auf Ihren Wunsch hin beendet!! "<< endl;
			return 0;
		default:
			cout << "Falsche eingabe";
			break;
			}
	}
	while(eingabe !=4);
	return 0;
}
void printkonto(vector<konto> k,int index){
	cout << "Kontoinhaber: " << k[index].getowner() <<endl <<
			"Bankleitzahl: " << k[index].getBLZ() << endl <<
			"Kontonummer: " << k[index].getnr() << endl<<
			"Dispo: " << k[index].getdispo() << endl <<
			"Kontostand: " << k[index].getKontostand() << endl <<
			"Zinssatz: " << k[index].getzinssatz() << endl <<
			"Kartennummer: " << k[index].getkartennummer() << endl;
}
void newkonto(vector<konto> k){
	konto newkonto;
	k.push_back(newkonto);
	int size = k.size()-1;
	cout << "Geben Sie den Kontoinhaber ein: " << endl;
	string tempowner;
	cin >> tempowner;
	k[size].setowner(tempowner);
	k[size].setkartennummer(k[size].getkartennummer()+1);
	cout << "Geben Sie bitte den Kontostand an: ";
	float tempkontostand = 0.00f;
	cin >> tempkontostand;
	k[size].setkontostand(tempkontostand);
}
void kontostand(vector<konto> k, short kontonummer){
	 cout << "Ihr Kontostand beträgt:" << k[kontonummer-1].getKontostand() << endl;
	 getchar();
}
void geld_abheben(vector<konto> k,short kontonummer){
	short kn=kontonummer-1;
	cout << "Wie viel Geld wollen Sie abheben? ";
	int amount;
	float kontostand = k[kn].getKontostand();
	cin >> amount;
	kontostand -= amount;
	cout << "Sie haben " << amount << "abgehoben." << endl;
	k[kn].setkontostand(kontostand);
	cout <<"Ihr neuer Kontostand beträgt: " << kontostand << endl;

}
void geld_einzahlen(vector<konto> k,short kontonummer){
	short kn=kontonummer-1;
	cout << "Wie viel Geld wollen Sie einzahlen? ";
	int amount;
	float kontostand = k[kn].getKontostand();
	cin >> amount;
	kontostand += amount;
	cout << "Sie haben " << amount << "eingezahlt." << endl;
	k[kn].setkontostand(kontostand);
	cout <<"Ihr neuer Kontostand beträgt: " << kontostand << endl;
}
void ueberweisen(vector<konto> k,short kontonummer){
	short kn=kontonummer-1;
	cout << "Wie viel Geld wollen Sie ueberweisen? ";
	int amount;
	float kontostand = k[kn].getKontostand();
	cin >> amount;
	cout << "Geben Sie die Kontonummer ein, auf welches Sie überweisen wollen: " << endl;
	short targetnr;
	cin >> targetnr;
	k[kn].newvorgang("Sie haben ueberwiesen");
	k[targetnr-1].getueberweisung(amount);
	string tempowner = k[targetnr-1].getowner();
	k[kontonummer].sendueberweisung(amount, tempowner);
	cout <<"Ihr neuer Kontostand beträgt: " << kontostand << endl;
}
bool validate(string pw){
	if(pw == "Peter"){
		return 1;
	}
	return 0;
}
void admin(){
	cout << "Admintest"<< endl;
}
