#include "movie.h"

// Constructor: Initializes a Movie object with given attributes.
// Stores the number of copies in stock, director name, movie title, and release
// year.
Movie::Movie(int stock, string director, string title, int year)
    : stock(stock), director(director), title(title), year(year) {}
// Returns the current number of copies in stock.
int Movie::getStock() const { return stock; }
// Increases the stock count by 1.
void Movie::increaseStock() { stock++; }

// Attempts to decrease the stock by 1.
// Returns true if successful (stock was available), false otherwise.
bool Movie::decreaseStock() {
  if (stock > 0) {
    stock--;
    return true;
  }
  return false;
}
