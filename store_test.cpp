/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "store_manager.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Begin testStoreFinal" << std::endl;
  StoreManager store;
  std::cout << "Loading customers..." << std::endl;
  store.loadCustomers("data4customers.txt");
  std::cout << "Customers loaded." << std::endl;
  store.loadMovies("data4movies.txt");
  std::cout << "Movies loaded." << std::endl;
  store.processCommands("data4commands.txt");
  std::cout << "Commands processed." << std::endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
