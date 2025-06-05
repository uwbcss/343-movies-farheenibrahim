#ifndef COMMAND_H
#define COMMAND_H

class StoreManager;

class Command {
public:
  virtual void execute(StoreManager &store) = 0;
  virtual void display() const = 0;
  virtual Command *clone() const = 0;
  virtual ~Command() = default;
};
#endif
