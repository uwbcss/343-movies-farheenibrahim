#include "movie.h"

Movie::Movie(int stock, string director, string title, int year)
    : stock(stock), director(director), title(title), year(year) {}

int Movie::getStock() const { return stock; }

void Movie::increaseStock() { stock++; }

bool Movie::decreaseStock() {
  if (stock > 0) {
    stock--;
    return true;
  }
  return false;
}
