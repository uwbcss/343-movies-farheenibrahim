#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
  // Constructor: initializes a Comedy movie with stock, director, title, and
  // release year
  Comedy(int stock, const std::string &director, const std::string &title,
         int year);
  // Displays the details of the Comedy movie (overrides base Movie class)
  void display() const override;
  // Checks if this Comedy movie is equal to another Movie (based on sorting
  // attributes)
  bool equals(const Movie &other) const override;
  // Returns the genre character representing Comedy ('F')
  bool lessThan(const Movie &other) const override;
  char getGenre() const override;
  // Creates and returns a deep copy (clone) of this Comedy movie object
  Movie *clone() const override;
  int getYear() const;
  // Accessor for the movie title
  string getTitle() const;
};

#endif
