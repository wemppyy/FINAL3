#include "card.h"

Card::Card(string name, string type, double balance, int cardLogoIndex) {
	this->name = name;
	this->type = type;
	this->balance = balance;
	this->cardLogoIndex = cardLogoIndex;
}

string Card::getName() { return name; }
string Card::getType() { return type; }
double Card::getBalance() { return balance; }
int Card::getCardLogoIndex() { return cardLogoIndex; }

void Card::setName(string name) { this->name = name; }
void Card::setType(string type) { this->type = type; }
void Card::setBalance(double balance) { this->balance = balance; }
void Card::setCardLogoIndex(int cardLogoIndex) { this->cardLogoIndex = cardLogoIndex; }

void Card::topUpBalance(double amount) { balance += amount; }

void Card::printCard() {
	system("cls");

    cout << "---------------------------" << endl
        << "  " << name << endl
        << "  " << type << endl
        << "  " << "$" << balance << endl << endl;

    switch (cardLogoIndex) {
    case 1:
        cout << " \\_('<" << endl;
        cout << "  \\___)" << endl;
        break;
    case 2:
        cout << "    __ " << endl;
        cout << "  \\/ o\\" << endl;
        cout << "  /\\__/ " << endl;
        break;
    case 3:
        cout << "  (0> " << endl;
        cout << "  //\\ " << endl;
        cout << "  V_/_" << endl;
        break;
    case 4:
        cout << "    _    " << endl;
        cout << " _\\( )/_ " << endl;
        cout << "  /(O)\\  " << endl;
        break;
    case 5:
        cout << "     __     " << endl;
        cout << "  __/  \\_   " << endl;
        cout << " '-o---o-'   " << endl;
        break;
    default:
        cout << "Unknown card logo" << endl;
        break;
    }

    cout << "---------------------------" << endl;
}