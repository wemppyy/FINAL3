#include "wallet.h"

Wallet::Wallet(string name) {
	this->name = name;
}

string Wallet::getName() { return name; }
vector<Card> Wallet::getCards() { return cards; }

void Wallet::setName(string name) { this->name = name; }

void Wallet::addCard(Card card) { cards.push_back(card); }
void Wallet::removeCard(int index) {
	if (index < 0 || index >= cards.size()) {
		cerr << "Invalid index" << endl;
		return;
	}

	cards.erase(cards.begin() + index);
}

void Wallet::addExpense(double amount, string category, Card card) {
    Expense expense(category, amount, card);
    expenses.push_back(expense);
	card.setBalance(card.getBalance() - amount);
}

void Wallet::makeReport() {
    ofstream out("report.txt");
    for (auto expense : expenses) {
        out << expense.getAsString() << endl;
    }
    out.close();
}

void Wallet::writeRatingToFile(const string& filename, time_t periodAgo) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "File opening error: " << filename << endl;
        return;
    }

    vector<Expense> filteredExpenses;

    for (auto& expense : expenses) {
        if (expense.getDate() >= periodAgo) {
            filteredExpenses.push_back(expense);
        }
    }

    sort(filteredExpenses.begin(), filteredExpenses.end(),
        [](Expense& a, Expense& b) {
            return a.getAmount() > b.getAmount();
        });

    for (auto& expense : filteredExpenses) {
        out << expense.getAsString() << endl;
    }

    out.close();
}

void Wallet::writeRatingByCategoryToFile(const string& filename, time_t periodAgo) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "File opening error: " << filename << endl;
        return;
    }

    vector<Expense> filteredExpenses;

    for (auto& expense : expenses) {
        if (expense.getDate() >= periodAgo) {
            filteredExpenses.push_back(expense);
        }
    }

    sort(filteredExpenses.begin(), filteredExpenses.end(),
        [](Expense& a, Expense& b) {
            return a.getCategory() < b.getCategory();
        });

    for (auto& expense : filteredExpenses) {
        out << expense.getAsString() << endl;
    }

    out.close();
}

void Wallet::makeRatingByExpenses() {
    // rating for the week
    time_t weekAgo = time(0) - 7 * 24 * 60 * 60;
    writeRatingToFile("rating_week.txt", weekAgo);

    // rating for the month
    time_t monthAgo = time(0) - 30 * 24 * 60 * 60;
    writeRatingToFile("rating_month.txt", monthAgo);
}

void Wallet::makeRatingByCategories() {
    // rating for the week
    time_t weekAgo = time(0) - 7 * 24 * 60 * 60;
    writeRatingByCategoryToFile("rating_by_category_week.txt", weekAgo);

    // rating for the month
    time_t monthAgo = time(0) - 30 * 24 * 60 * 60;
    writeRatingByCategoryToFile("rating_by_category_month.txt", monthAgo);
}