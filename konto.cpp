#include <iostream>
#include "konto.h"

konto::konto(int iNr,std::string iOwner, unsigned int iDispo, float iKontostand, double iZinssatz, unsigned int iKartennummer){
nr = iNr;
kontostand = iKontostand;
owner = iOwner;
dispo = iDispo;
zinssatz = iZinssatz;
kartennummer = iKartennummer;
}

konto::konto(){
 nr = 1;
}

int konto::getnr(){
	return nr;
}
int konto::getBLZ(){
	return BLZ;
}
float konto::getKontostand(){
	return kontostand;
}
std::string konto::getowner(){
	return owner;
}
unsigned int konto::getdispo(){
	return dispo;
}
double konto::getzinssatz(){
	return zinssatz;
}
int konto::getkartennummer(){
	return kartennummer;
}
void konto::setnr(int iNr){
	nr = iNr;
}
void konto::setowner(std::string iOwner){
	owner = iOwner;
}
void konto::setdispo(unsigned int iDispo){
	dispo = iDispo;
}
void konto::setkontostand(float iKontostand){
	kontostand = iKontostand;
}
void konto::setzinssatz(double iZinssatz){
	zinssatz = iZinssatz;
}
void konto::setkartennummer(int iKartennummer){
	kartennummer = iKartennummer;
}
//Zusätzliche Methoden
void konto::Auszahlung(int Zahl){
	kontostand = kontostand - Zahl;
	std::cout << "Ihr neuer Kontostand beträgt : " << kontostand << std::endl;
	std::cout << "Sie bekommen " << Zahl << "ausgezahlt" << std::endl;

}
void konto::Einzahlung(float Zahl){
	kontostand = kontostand + Zahl;
	std::cout << "Sie haben " << Zahl << " eingezahl" << std::endl;
	std::cout << "Ihr neuer Kontostand beträgt:" << kontostand << std::endl;
}
void konto::getueberweisung(float Zahl){
	kontostand = kontostand + Zahl;
}
void konto::sendueberweisung(float Zahl,std::string target){
	std::cout << "Sie haben " << Zahl << "an " << target << "ueberwiesen"<< std::endl;
	kontostand -= Zahl;
}
void konto::newvorgang(std::string vorgang){
	verlauf.push(vorgang);
}
void konto::printverlauf(){
	for(int i = 0 ; i<= verlauf.size();i++){
		while(!verlauf.empty()){
			std::cout << verlauf.top() << std::endl;
			verlauf.pop();
		}
	}
}



