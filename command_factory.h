// #ifndef COMMAND_FACTORY_H
// #define COMMAND_FACTORY_H

// #include "command.h"
// #include <string>

// class CommandFactory {
// public:
//   static Command *createCommand(const std::string &line);
// };

// #endif

#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "command.h"
#include <functional>
#include <string>
#include <unordered_map>

class CommandFactory {
public:
  using Creator = std::function<Command *(std::istream &)>;
  static Command *createCommand(const std::string &line);
  static void registerType(char type, Creator creator);

private:
  static std::unordered_map<char, Creator> &getRegistry();
};

#endif
