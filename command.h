#ifndef COMMAND_H
#define COMMAND_H

class StoreManager;

class Command {
public:
  // Executes the command using the provided StoreManager context
  // Must be implemented by derived classes
  virtual void execute(StoreManager &store) = 0;
  // Displays information about the command (for logging/debugging)
  virtual void display() const = 0;
  // Creates and returns a deep copy (clone) of the command
  // Useful for polymorphic command storage and execution
  virtual Command *clone() const = 0;
  virtual ~Command() = default;
};
#endif
