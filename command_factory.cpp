#include "command_factory.h"
#include <iostream>
#include <sstream>

using namespace std;

unordered_map<char, CommandFactory::Creator> &CommandFactory::getRegistry() {
  static unordered_map<char, Creator> registry;
  return registry;
}

void CommandFactory::registerType(char type, Creator creator) {
  getRegistry()[type] = creator;
}
// command_factory.cpp

Command *CommandFactory::createCommand(const string &line) {
  if (line.size() < 3) {
    cout << "ERROR: Malformed command line: \"" << line << "\"" << endl;
    return nullptr;
  }

  char type = line[0];
  auto it = getRegistry().find(type);
  if (it == getRegistry().end()) {
    cout << "ERROR: Unknown command type: " << type << endl;
    return nullptr;
  }

  istringstream stream(line.substr(2)); // safe now
  return it->second(stream);
}
