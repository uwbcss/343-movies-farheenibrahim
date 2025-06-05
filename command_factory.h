#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "command.h"
#include <functional>
#include <string>
#include <unordered_map>

class CommandFactory {
public:
  // Alias for a function that creates a Command object from an input stream
  using Creator = std::function<Command *(std::istream &)>;
  // Creates a Command object based on the command line string
  // Parses the command type from the string and uses the registered creator
  // function
  static Command *createCommand(const std::string &line);
  static void registerType(char type, Creator creator);

private:
  static std::unordered_map<char, Creator> &getRegistry();
};

#endif
