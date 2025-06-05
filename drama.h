#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  Drama(int stock, const string &director, const string &title, int year);
  void display() const override;
  bool equals(const Movie &other) const override;
  bool lessThan(const Movie &other) const override;
  char getGenre() const override;
  Movie *clone() const override;
};

#endif
