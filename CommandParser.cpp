#include "stdafx.h"

#include <stdlib.h>
#include <string>
#include <regex>
#include "CommandParser.h"

#include "opencv2/core.hpp"

const std::string ADB_COMMAND = "adb";
const std::string ADB_SHELL_COMMAND = "adb shell";
const std::string ADB_SHELL_MONKEY = "monkey -p";
const std::string ADB_SHELL_INPUT = "input";
const std::string ADB_INPUT_TAP = "tap";
const std::string ADB_INPUT_TEXT = "text";
const std::string ADB_SHELL_SCREENCAP = "screencap";
const std::string ADB_FILE_PULL = "pull";

const std::string DEFAULT_STORAGE_DIR = "/sdcard/";

const std::string PARSE_SPACE_CHAR	= " ";
const std::string SAFE_SPACE_CHAR	= "%s";
	
std::string parseSearchQuery(std::string userInput)
{
	std::size_t idx = userInput.find(PARSE_SPACE_CHAR);
	while (idx != std::string::npos) {
		userInput.replace(userInput.find(PARSE_SPACE_CHAR), PARSE_SPACE_CHAR.length(), SAFE_SPACE_CHAR);
		idx = userInput.find(PARSE_SPACE_CHAR);
	}
	return userInput;
}

std::string launchAppCommandBuilder(std::string packageName)
{
	std::string shellCmdString = ADB_SHELL_COMMAND + " " + ADB_SHELL_MONKEY + " " + packageName + " 1";
	return shellCmdString;
}

std::string tapCommandBuilder(int x, int y) {
	std::string shellCmdString = ADB_SHELL_COMMAND + " " + ADB_SHELL_INPUT + " " + ADB_INPUT_TAP + " " + std::to_string(x) + " " + std::to_string(y);
	return shellCmdString;
}

std::string textCommandBuilder(std::string rawInput)
{
	std::string safeTextInput = parseSearchQuery(rawInput);
	std::string shellCmdString = ADB_SHELL_COMMAND + " " + ADB_SHELL_INPUT + " " + ADB_INPUT_TEXT + " " + safeTextInput;
 	return shellCmdString;
}

std::string screenCapCommandBuilder(std::string screencapName)
{
	std::string shellCmdString = ADB_SHELL_COMMAND + " " + ADB_SHELL_SCREENCAP + " " + DEFAULT_STORAGE_DIR + screencapName;
	return shellCmdString;
}

std::string pullCommandBuilder(std::string fileName)
{
	std::string shellCmdString = ADB_COMMAND + " " + ADB_FILE_PULL + " " + DEFAULT_STORAGE_DIR + fileName;
	return shellCmdString;
}



