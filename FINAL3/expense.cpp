#define _CRT_SECURE_NO_WARNINGS
#include "expense.h"

Expense::Expense(string category, double amount, Card card) : card(card) {
	this->category = category;
	this->amount = amount;
	this->date = time(0);
}

string Expense::getCategory() { return category; }
double Expense::getAmount() { return amount; }
time_t Expense::getDate() { return date; }
Card Expense::getCard() { return card; }

void Expense::setCategory(string category) { this->category = category; }
void Expense::setAmount(double amount) { this->amount = amount; }
void Expense::setDate(time_t date) { this->date = date; }
void Expense::setCard(Card card) { this->card = card; }

string Expense::getAsString() {
	string result = card.getName() + ", " + getCategory() + ": " + to_string(getAmount()) + " - " + ctime(&date);
	return result;
}