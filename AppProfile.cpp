#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include "AppProfile.h"


AppProfile::AppProfile()
{
}

std::string AppProfile::launchAppCommand() {
	std::string cmd = launchAppCommandBuilder(Package);
	return cmd;
};
std::string AppProfile::getFriendlyName() {
	return FriendlyName;
};
std::string AppProfile::getPackage() {
	return Package;
};
std::vector<AppInteraction*> AppProfile::getAppActions()
{
	return AppActions;
}
std::vector<AppInteraction*> AppProfile::addAppAction(AppInteraction* newAction)
{
	AppActions.push_back(newAction);
	return AppActions;
}
;
