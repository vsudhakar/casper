#include "stdafx.h"
#include "TextAppInteraction.h"


TextAppInteraction::TextAppInteraction()
{
	TextAppInteraction("");
}

TextAppInteraction::TextAppInteraction(std::string userText)
{
	ActionType = Interaction::TEXT;
	inputText = userText;
}


TextAppInteraction::~TextAppInteraction()
{
}

std::string TextAppInteraction::buildAdbCommand()
{
	std::string inputTextCmd = textCommandBuilder(inputText);
	return inputTextCmd;
}

std::string TextAppInteraction::buildAdbCommand(std::string runtime_text)
{
	std::string inputTextCmd = textCommandBuilder(runtime_text);
	return inputTextCmd;
}

void TextAppInteraction::launchInteraction()
{
	std::string runnableAdbCmd = buildAdbCommand();
	system(runnableAdbCmd.c_str());
}

void TextAppInteraction::launchInteraction(std::string runtime_text)
{
	std::string runnableAdbCmd = buildAdbCommand(runtime_text);
	system(runnableAdbCmd.c_str());
}