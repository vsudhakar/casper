#include <string>

#pragma once
#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

std::string parseSearchQuery(std::string userInput);

std::string launchAppCommandBuilder(std::string packageName);

std::string tapCommandBuilder(int x, int y);

std::string textCommandBuilder(std::string rawInput);

#endif // !COMMANDPARSER_H
