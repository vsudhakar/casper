#include "stdafx.h"
#include "SpotifyAppProfile.h"

#include <stdio.h>
#include <iostream>

using namespace std;


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

	TapAppInteraction *action_tap_search = new TapAppInteraction("Go to Search Menu", "ref_images/spotify_search_icon.png");
	AppActions.push_back(action_tap_search);
	ActionMap.insert(std::make_pair("goToSearchMenu", action_tap_search));

	TapAppInteraction *action_tap_searchBar = new TapAppInteraction("Select Search Bar", "ref_images/spotify_search_bar.png");
	ActionMap.insert(std::make_pair("selectSearchBar", action_tap_searchBar));

	TapAppInteraction *action_tap_shufflePlay = new TapAppInteraction("Shuffle Play Current Artist/Album", "ref_images/spotify_shuffle_play.png");
	ActionMap.insert(std::make_pair("selectShufflePlay", action_tap_shufflePlay));

	TextAppInteraction *action_text_searchQuery = new TextAppInteraction();
	ActionMap.insert(std::make_pair("inputSearchQuery", action_text_searchQuery));

	TapAppInteraction *action_tap_topSearchResult = new TapAppInteraction("Select Top Search Result", 80, 340);
	ActionMap.insert(std::make_pair("selectTopSearchResult", action_tap_topSearchResult));
	
	TapAppInteraction *action_tap_play = new TapAppInteraction("Tap Play Button", "ref_images/spotify_play_icon.png");
	ActionMap.insert(std::make_pair("playMusic", action_tap_play));

	TapAppInteraction *action_tap_pause = new TapAppInteraction("Tap Pause Button", "ref_images/spotify_pause_icon.png");
	ActionMap.insert(std::make_pair("pauseMusic", action_tap_pause));
}


SpotifyAppProfile::~SpotifyAppProfile()
{
}

void SpotifyAppProfile::launchApp()
{
	std::string runnable_cmd = launchAppCommand();
	system(runnable_cmd.c_str());
}

void SpotifyAppProfile::launchSearchMenu() 
{
	AppInteraction* action = ActionMap["goToSearchMenu"];
	action->launchInteraction();
}

void SpotifyAppProfile::selectSearchBar()
{
	AppInteraction* action = ActionMap["selectSearchBar"];
	action->launchInteraction();
}

void SpotifyAppProfile::runSearchQuery(std::string query_text)
{
	launchSearchMenu();
	/*selectSearchBar(); bug with the select query */
	launchSearchMenu();
	TextAppInteraction* action = dynamic_cast<TextAppInteraction*>(ActionMap["inputSearchQuery"]);
	action->launchInteraction(query_text);
	AppInteraction* next_action = ActionMap["selectTopSearchResult"];
	next_action->launchInteraction();
}

void SpotifyAppProfile::shufflePlay()
{
	AppInteraction* action = ActionMap["selectShufflePlay"];
	action->launchInteraction();
	TapAppInteraction* tapAction = dynamic_cast<TapAppInteraction*>(action);
	int x = std::get<0>(tapAction->getXY());
	int y = std::get<1>(tapAction->getXY());
	cout << "x: " << x << " , y: " << y << std::endl;
}

bool SpotifyAppProfile::play()
{
	AppInteraction* action = ActionMap["playMusic"];
	action->launchInteraction();
	return true;
	/*TODO: Check current state*/
}

bool SpotifyAppProfile::pause()
{
	AppInteraction* action = ActionMap["pauseMusic"];
	action->launchInteraction();
	return true;
	/*TODO: Check current state*/
}