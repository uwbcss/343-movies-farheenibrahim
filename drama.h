#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  Drama(int stock, const string &director, const string &title, int year);
  // Displays details of the Drama movie (overrides Movie::display)
  void display() const override;
  // Checks equality of this Drama movie with another Movie object
  // Equality based on sorting attributes: Director and Title
  bool equals(const Movie &other) const override;
  bool lessThan(const Movie &other) const override;
  // Returns genre character for Drama ('D')
  char getGenre() const override;
  Movie *clone() const override;
};

#endif
