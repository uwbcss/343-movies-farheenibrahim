#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
  Comedy(int stock, const std::string &director, const std::string &title,
         int year);
  void display() const override;
  bool equals(const Movie &other) const override;
  bool lessThan(const Movie &other) const override;
  char getGenre() const override;
  Movie *clone() const override;
  int getYear() const;
  string getTitle() const;
};

#endif
