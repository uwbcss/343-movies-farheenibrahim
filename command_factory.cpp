#include "command_factory.h"
#include <iostream>
#include <sstream>

using namespace std;

// Returns a static reference to the command registry.
// This registry maps command type characters (e.g., 'B', 'R', 'H') to
// corresponding factory functions (i.e., functions that return Command*).
unordered_map<char, CommandFactory::Creator> &CommandFactory::getRegistry() {
  static unordered_map<char, Creator> registry;
  return registry;
}
// Registers a command type with its corresponding factory function.
// For example, registerType('B', [](istream& s) { return new Borrow(s); });
void CommandFactory::registerType(char type, Creator creator) {
  getRegistry()[type] = creator;
}

// Factory method: Creates a Command object based on the input line.
// - Extracts the first character as the command type (e.g., 'B', 'R')
// - Looks up the registered factory function
// - If found, invokes the function with the remainder of the line
// - Returns a dynamically allocated Command* (caller must delete)
Command *CommandFactory::createCommand(const string &line) {
  if (line.size() < 3) {
    cout << "ERROR: Malformed command line: \"" << line << "\"" << endl;
    return nullptr;
  }

  char type = line[0];
  // Look up the factory function for this type in the registry
  auto it = getRegistry().find(type);
  if (it == getRegistry().end()) {
    cout << "ERROR: Unknown command type: " << type << endl;
    return nullptr;
  }

  istringstream stream(line.substr(2)); // safe now
  return it->second(stream);
}
