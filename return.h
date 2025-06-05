#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "movie.h"
#include <string>
using namespace std;

class Return : public Command {
private:
  Movie *movie;
  int customerID;

public:
  // Constructor: parses input stream to initialize the Return command (e.g.,
  // customer ID, movie info)
  explicit Return(
      istream &stream); // parses from input
                        // Destructor: cleans up any dynamically allocated
                        // memory (e.g., deletes 'movie' if owned)
  ~Return();
  // Executes the return operation on the given StoreManager instance
  // This will update inventory and customer's transaction history
  void execute(StoreManager &store) override;
  // Displays information about the return command (e.g., for debugging or
  // logging)

  void display() const override;
  // Creates a copy of this Return command object (used for polymorphic cloning)

  Command *clone() const override;
};

#endif
