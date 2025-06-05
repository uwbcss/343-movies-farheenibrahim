#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:
  Classic(int stock, const std::string &director, const std::string &title,
          int month, int year, const std::string &actor);
  void display() const override;
  bool equals(const Movie &other) const override;
  bool lessThan(const Movie &other) const override;
  char getGenre() const override;
  Movie *clone() const override;

  // Optional getters
  string getActor() const;
  int getMonth() const;

private:
  int month;
  std::string actor;
};

#endif