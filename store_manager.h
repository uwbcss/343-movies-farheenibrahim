#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include "customer.h"
#include "movie_hashtable.h"
#include <string>
#include <unordered_map>

class StoreManager {
private:
  MovieHashTable inventory;
  std::unordered_map<int, Customer *> customers;

public:
  StoreManager();
  ~StoreManager();

  void loadCustomers(const std::string &filename);
  void loadMovies(const std::string &filename);
  void processCommands(const std::string &filename);

  MovieHashTable &getInventory();
  std::unordered_map<int, Customer *> &getCustomers();
  Customer *getCustomer(int id);
};

#endif
