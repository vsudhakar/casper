#include "AppInteraction.h"
#include "TapAppInteraction.h"
#include "TextAppInteraction.h"

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
	virtual void launchApp();
	void launchSearchMenu();
	void selectSearchBar();
	void runSearchQuery(std::string query_text);
	void play();
	void pause();
};

#endif // !SPOTIFYAPPPROFILE_H


