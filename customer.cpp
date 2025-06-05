#include "customer.h"
#include "command.h"
#include <iostream>
using namespace std;

// Constructor: Initializes a Customer with an ID, last name, and first name
Customer::Customer(int id, string last, string first)
    : CustomerID(id), firstName(first), lastName(last) {}

// Destructor: Frees dynamically allocated Command history objects
Customer::~Customer() {
  for (Command *cmd : history) {
    delete cmd; // prevent memory leaks
  }
}
// Adds a command to the customer's history (e.g., borrow or return)
void Customer::addToHistory(Command *cmd) { history.push_back(cmd); }
// Displays the customer's transaction history to standard output
void Customer::displayHistory() const {
  cout << "==========================" << endl;
  cout << "History for " << CustomerID << " " << lastName << " " << firstName
       << ":" << endl;

  if (history.empty()) {
    cout << "No history for " << firstName << " " << lastName << endl;
  } else {
    for (const auto &cmd : history) {
      cmd->display();
    }
  }
}
// Returns the customer's unique ID
int Customer::getID() const { return CustomerID; }

// Returns the full name of the customer (first + last)
string Customer::getName() const { return firstName + " " + lastName; }

// Returns the customer's first name
string Customer::getFirstName() const { return firstName; }

// Returns the customer's last name
string Customer::getLastName() const { return lastName; }
