#ifndef BANKSYSTEM_H_
#define BANKSYSTEM_H_
#include <string>
class Benutzer{};
class Konto
	{
private:
	unsigned int nr;
	const int BLZ = 53267400;
	std::string owner;
	unsigned int dispo;
	float kontostand;
	double zinssatz;
	unsigned int kartennummer;
	public:
	Konto(int iNr,std::string iOwner, unsigned int iDispo, float iKontostand, double iZinssatz, unsigned int iKartennummer);
	Konto();
	int getnr();
	int getBLZ();
	float getKontostand();
	std::string getowner();
	unsigned int getdispo();
	double getzinssatz();
	int getkartennummer();
	void setnr(int iNr);
	void setowner(std::string iOwner);
	void setdispo(unsigned int iDispo);
	void setzinssatz(double iZinssatz);
	void setkartennummer(int iKartennummer);
	void setkontostand(float iKontostand);
	void Auszahlung(int Zahl);
	void Einzahlung(float Zahl);
	void getueberweisung(float Zahl);
	void sendueberweisung(float Zahl, std::string nr);
	void newvorgang(std::string);
	};
#endif /* BANKSYSTEM_H_ */
