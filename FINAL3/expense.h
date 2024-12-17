#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "card.h"

using namespace std;



class Expense {
private:
	string category;
	double amount;
	time_t date;
	Card card;
public:
	Expense(string category, double amount, Card card);

	string getCategory();
	double getAmount();
	time_t getDate();
	Card getCard();

	void setCategory(string category);
	void setAmount(double amount);
	void setDate(time_t date);
	void setCard(Card card);

	string getAsString();
};