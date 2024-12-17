#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "card.h"
#include "expense.h"

class Wallet {
private:
	string name;
	vector<Card> cards;
	vector<Expense> expenses;
public:
	Wallet(string name);

	string getName();
	vector<Card> getCards();

	void setName(string name);

	void addCard(Card card);
	void removeCard(int cardName);
	void addExpense(double amount, string category, Card card);

	void writeRatingToFile(const string& filename, time_t periodAgo);
	void writeRatingByCategoryToFile(const string& filename, time_t periodAgo);

	void makeReport();
	void makeRatingByExpenses();
	void makeRatingByCategories();

};