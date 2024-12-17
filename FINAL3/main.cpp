#define TESTER 0

#include <iostream>
#include <string>
#include <vector>
#include "wallet.h"
#include "card.h"

using namespace std;

void cardAddingMenu(Wallet &wallet) {
	string cardName;
	string cardType;
	double cardBalance;
	int cardLogoIndex;

	system("cls");

	cout << "Enter card name: ";
	cin >> cardName;

	cout << "Enter card type: ";
	cin >> cardType;

	cout << "Enter card balance: ";
	cin >> cardBalance;

	cout << "Select card logo index (1-5): " << endl;
	cout << "\n1. Duck" << endl;
	cout << "\\_('<" << endl;
	cout << " \\___)" << endl;
	cout << "\n2. Fish" << endl;
	cout << "   __ " << endl;
	cout << " \\/ o\\" << endl;
	cout << " /\\__/ " << endl;
	cout << "\n3. Penguin" << endl;
	cout << " (0> " << endl;
	cout << " //\\ " << endl;
	cout << " V_/_" << endl;
	cout << "\n4. Spider" << endl;
	cout << "   _    " << endl;
	cout << "_\\( )/_ " << endl;
	cout << " /(O)\\  " << endl;
	cout << "\n5. Car" << endl;
	cout << "    __     " << endl;
	cout << " __/  \\_   " << endl;
	cout << "'-o---o-'   " << endl << endl;
	cin >> cardLogoIndex;

	Card card(cardName, cardType, cardBalance, cardLogoIndex);
	wallet.addCard(card);
}

int menu() {
	cout << "1. Add card" << endl;
	cout << "2. Remove card" << endl;
	cout << "3. Top up balance" << endl;
	cout << "4. Add expense" << endl;
	cout << "5. Make report" << endl;
	cout << "6. Make rating by extenses" << endl;
	cout << "7. Make rating by categories" << endl;
	cout << "8. Exit" << endl;
	cout << endl;
	cout << "9. Previous card" << endl;
	cout << "0. Next card" << endl;

	int choice;
	cin >> choice;

	return choice;
}

void add_test_cards(Wallet &wallet) {
	Card card1("Card1", "Debit", 1000, 1);
	Card card2("Card2", "Credit", 2000, 2);
	Card card3("Card3", "Debit", 3000, 3);
	Card card4("Card4", "Credit", 4000, 4);
	Card card5("Card5", "Debit", 5000, 5);

	wallet.addCard(card1);
	wallet.addCard(card2);
	wallet.addCard(card3);
	wallet.addCard(card4);
	wallet.addCard(card5);
}

int main() {
	Wallet wallet("My Wallet");

#ifndef TESTER
	cout << "Hello! First you need to create your first card!" << endl;
	system("pause");
	cardAddingMenu(wallet);
#endif // 0


#ifdef TESTER
	add_test_cards(wallet);
#endif // 0

	vector<Card> cards = wallet.getCards();
	int currentCardIndex = 0;
	int totalCards = cards.size();

	int removeIndex;
	double amount;
	double expenseAmount;
	string expenseCategory;

	while (true) {
		system("cls");

		cards[currentCardIndex].printCard();

		switch (menu()) {
		case 1:
			cardAddingMenu(wallet);
			break;
		case 2:
			cout << "Enter card index to remove: ";
			cin >> removeIndex;
			wallet.removeCard(removeIndex);
			break;
		case 3:
			cout << "Enter amount to top up: ";
			cin >> amount;
			cards[currentCardIndex].topUpBalance(amount);
			break;
		case 4:
			cout << "Enter expense amount: ";
			cin >> expenseAmount;
			cout << "Enter category: ";
			cin >> expenseCategory;
			wallet.addExpense(expenseAmount, expenseCategory, cards[currentCardIndex]);
			break;
		case 5:
			wallet.makeReport();
			break;
		case 6:
			wallet.makeRatingByExpenses();
			break;
		case 7:
			wallet.makeRatingByCategories();
			break;
		case 9:
			if (currentCardIndex == 0) {
				currentCardIndex = totalCards - 1;
			}
			else {
				currentCardIndex--;
			}
			break;
		case 0:
			if (currentCardIndex == totalCards - 1) {
				currentCardIndex = 0;
			}
			else {
				currentCardIndex++;
			}
			break;
		case 8:
			return 0;
		}
	}

	return 0;
}
