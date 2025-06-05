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
  Movie(int stock, string director, string title, int year);
  virtual ~Movie() = default;

  int getStock() const;
  void increaseStock();
  bool decreaseStock();

  virtual void display() const = 0;
  virtual bool equals(const Movie &other) const = 0;
  virtual bool lessThan(const Movie &other) const = 0;
  virtual char getGenre() const = 0;

  string getTitle() const { return title; }
  string getDirector() const { return director; }
  int getYear() const { return year; }
  virtual Movie *clone() const = 0;
};

#endif
