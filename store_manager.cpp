#include "store_manager.h"
#include "classic.h"
#include "comedy.h"
#include "command_factory.h"
#include "drama.h"
#include "history.h"
#include "inventory.h"
#include "movie_factory.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Robust leading space trimmer
string ltrim(const string &str) {
  if (str.empty()) {
    return "";
  }
  size_t start = str.find_first_not_of(' ');
  return (start == string::npos) ? "" : str.substr(start);
}

StoreManager::StoreManager() {}

StoreManager::~StoreManager() {
  for (auto &pair : customers) {
    delete pair.second;
  }
}

MovieHashTable &StoreManager::getInventory() { return inventory; }

unordered_map<int, Customer *> &StoreManager::getCustomers() {
  return customers;
}

Customer *StoreManager::getCustomer(int id) {
  if (customers.find(id) != customers.end()) {
    return customers[id];
  }
  return nullptr;
}

void StoreManager::loadCustomers(const string &filename) {
  ifstream file(filename);
  if (!file) {
    cerr << "Could not open " << filename << endl;
    return;
  }

  int id;
  string last;
  string first;
  while (file >> id >> last >> first) {
    customers[id] = new Customer(id, first, last);
  }

  cout << "Customers loaded." << endl;
}

void StoreManager::loadMovies(const string &filename) {
  ifstream file(filename);
  if (!file) {
    cerr << "Could not open " << filename << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    if (line.empty()) {
      continue;
    }

    char genre = line[0];
    if (line.length() > 2 && line[1] == ',') {
      // Create a new Movie using the MovieFactory
      Movie *m = MovieFactory::createMovie(genre, line.substr(2));
      if (m != nullptr) {
        // Check if movie already exists in the inventory
        Movie *existing = inventory.find(m->getGenre(), m);
        if (existing == nullptr) {
          inventory.insert(m); // Store movie if not already present
        } else {
          delete m; // Prevent memory leak if duplicate
        }
      }
    } else {
      cout << "Invalid movie line: " << line << endl;
    }
  }

  cout << "Movies loaded." << endl;
}

void StoreManager::processCommands(const string &filename) {
  ifstream file(filename);
  if (!file) {
    cerr << "Could not open " << filename << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    Command *cmd = CommandFactory::createCommand(line);
    if (cmd != nullptr) {
      cmd->execute(*this);
      delete cmd;
    } else {
      cerr << "Failed to execute command: " << line << endl;
    }
  }
}
