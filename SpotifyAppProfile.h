#include "AppInteraction.h"
#include "TapAppInteraction.h"
#include "TextAppInteraction.h"
#include "AppProfile.h"

#pragma once
#ifndef SPOTIFYAPPPROFILE_H
#define SPOTIFYAPPPROTILE_H

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
	void shufflePlay();
	bool play();
	bool pause();
	void alternateControl();	// Switch play and pause
};

#endif // !SPOTIFYAPPPROFILE_H


