#include "AppInteraction.h"
#include "TapAppInteraction.h"
#include "TextAppInteraction.h"
#include "AppProfile.h"

#include <string>

#pragma once

#ifndef GMAPSAPPPROFILE_H
#define GMAPSAPPPROFILE_H

class GMapsAppProfile :
	public AppProfile
{
public:
	GMapsAppProfile();
	~GMapsAppProfile();

	// API Actions
	virtual void launchApp();
	void launchDrivingMode();
	void launchVoiceSearch();
	void recenterMap();

	void startNavigationTo(std::string destinationString);
};



#endif // !GMAPSAPPPROFILE

