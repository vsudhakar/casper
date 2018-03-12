#include "AppInteraction.h"
#include "TapAppInteraction.h"

#pragma once
#ifndef SPOTIFYAPPPROFILE_H
#define SPOTIFYAPPPROTILE_H

#include "AppProfile.h"
class SpotifyAppProfile :
	public AppProfile
{
public:
	SpotifyAppProfile();
	~SpotifyAppProfile();

	// API Actions
	void launchSearchMenu();
};

#endif // !SPOTIFYAPPPROFILE_H


