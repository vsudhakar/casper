#include "CommandParser.h"
#include "AppInteraction.h"
#include <vector>
#include <map>

#pragma once
#ifndef APPPROFILE_H
#define APPPROFILE_H

class AppProfile
{
protected:
	std::string FriendlyName;
	std::string Package;
	std::vector<AppInteraction*> AppActions;
	std::map<std::string, AppInteraction*> ActionMap;

public:
	AppProfile();

	std::string launchAppCommand();
	std::string getFriendlyName();
	std::string getPackage();

	std::vector<AppInteraction*> getAppActions();
		 
	std::vector<AppInteraction*> addAppAction(AppInteraction* action);
};


#endif // !APPPROFILE_H