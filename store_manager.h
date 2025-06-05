#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include "customer.h"
#include "movie_hashtable.h"
#include <string>
#include <unordered_map>
using namespace std;

class StoreManager {
private:
  MovieHashTable
      inventory; // Hash table storing all movies by their unique keys
  unordered_map<int, Customer *> customers;

public:
  StoreManager();
  ~StoreManager();
  // Loads customers from a file and populates the 'customers' hash map
  void loadCustomers(const string &filename);
  // Loads movies from a file and populates the 'inventory' hash table
  void loadMovies(const string &filename);
  // Processes commands (borrow, return, inventory, history) from a file
  void processCommands(const string &filename);

  MovieHashTable &getInventory();
  unordered_map<int, Customer *> &getCustomers();
  // Retrieves a pointer to a Customer object by their ID, returns nullptr if
  // not found
  Customer *getCustomer(int id);
};

#endif
