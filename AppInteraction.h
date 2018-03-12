#include <stdlib.h>
#include <string>
#include <tuple>

enum class Interaction { TAP, TEXT };

#pragma once
#ifndef APPINTERACTION_H
#define APPINTERACTION_H

class AppInteraction
{
protected:
	int ActionId;
	std::string FriendlyName;
	Interaction ActionType;

public:
	AppInteraction();
	~AppInteraction();
	
	virtual std::string buildAdbCommand() = 0;
	Interaction getActionType();

	virtual void launchInteraction() = 0;
};

#endif // !APPINTERACTION_H
