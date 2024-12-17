#pragma once
#include <iostream>
#include <string>

using namespace std;

class Card {
private:
	string name;
	string type;
	double balance;
	int cardLogoIndex;
public:
	Card(string name, string type, double balance, int cardLogoIndex);

	string getName();
	string getType();
	double getBalance();
	int getCardLogoIndex();

	void setName(string name);
	void setType(string type);
	void setBalance(double balance);
	void setCardLogoIndex(int cardLogoIndex);

	void topUpBalance(double amount);

	void printCard();
};