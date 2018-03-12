#include "stdafx.h"
#include "SpotifyAppProfile.h"


SpotifyAppProfile::SpotifyAppProfile()
{
	FriendlyName = "Spotify Music";
	Package = "com.spotify.music";

	/* Build Interactions */
	/*
	AppInteraction *action_launch_app;
	AppInteraction *action_tap_search;
	AppInteraction *action_text_search;
	AppInteraction *action_tap_selectTopResult;
	AppInteraction *action_tap_shufflePlay;
	AppInteraction *action_tap_playPause;
	*/

	TapAppInteraction *action_tap_search = new TapAppInteraction("Go to Search Menu");
	action_tap_search->setX(360);
	action_tap_search->setY(1150);
	AppActions.push_back(action_tap_search);
	// Add to map
	ActionMap.insert(std::make_pair("goToSearchMenu", action_tap_search));

	//action_launch_app = new AppInteraction()
}


SpotifyAppProfile::~SpotifyAppProfile()
{
}

void SpotifyAppProfile::launchSearchMenu() 
{
	// Retrieve action from map
	AppInteraction* action = ActionMap["goToSearchMenu"];
	
	// Launch interaction
	action->launchInteraction();
}