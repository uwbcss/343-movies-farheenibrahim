#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
using namespace std;

class Movie {
protected:
  int stock;
  string director;
  string title;
  int year;

public:
  // Constructor to initialize a Movie object with stock, director, title, and
  // year
  Movie(int stock, string director, string title, int year);
  // Virtual destructor to allow proper cleanup in derived classes
  virtual ~Movie() = default;
  // Returns the current stock count
  int getStock() const;

  // Increases stock count by one (used when a movie is returned)
  void increaseStock();

  // Decreases stock count by one if stock > 0; returns true if successful,
  // false otherwise
  bool decreaseStock();

  // Pure virtual function to display the movie information
  virtual void display() const = 0;

  // Pure virtual function to compare equality of this movie with another (used
  // for identifying movies)
  virtual bool equals(const Movie &other) const = 0;

  // Pure virtual function to compare order of this movie with another (used for
  // sorting)
  virtual bool lessThan(const Movie &other) const = 0;

  // Pure virtual function to get the genre code of the movie (e.g., 'F', 'D',
  // 'C')
  virtual char getGenre() const = 0;

  // Accessor functions to get movie details (non-virtual, common to all movies)
  string getTitle() const { return title; }
  string getDirector() const { return director; }
  int getYear() const { return year; }

  // Pure virtual function to clone this movie (for copying objects
  // polymorphically)
  virtual Movie *clone() const = 0;
};

#endif
