#pragma once
#include "AppInteraction.h"
#include <string>
#include "CommandParser.h"
class TextAppInteraction :
	public AppInteraction
{
protected:
	std::string inputText;
public:
	TextAppInteraction();
	TextAppInteraction(std::string userText);
	~TextAppInteraction();

	virtual std::string buildAdbCommand();
	virtual void launchInteraction();

	// Option to input text at runtime
	virtual std::string buildAdbCommand(std::string runtime_text);
	virtual void launchInteraction(std::string runtime_text);
};

