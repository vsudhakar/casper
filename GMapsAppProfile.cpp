#include "stdafx.h"
#include "GMapsAppProfile.h"

#include <thread>


GMapsAppProfile::GMapsAppProfile()
{
	FriendlyName = "Google Maps";
	Package = "com.google.android.apps.maps";

	/* Build Interactions */
	TapAppInteraction *action_tap_hamburgerMenu = new TapAppInteraction("Open Hamburger Menu", 85, 111);
	ActionMap.insert(std::make_pair("openHamburgerMenu", action_tap_hamburgerMenu));
	TapAppInteraction *action_tap_drivingMenuAction = new TapAppInteraction("Start Driving Mode", "ref_images/gmaps_startDriving_icon.png");
	ActionMap.insert(std::make_pair("startDrivingMode", action_tap_drivingMenuAction));
	TapAppInteraction *action_tap_voiceInput = new TapAppInteraction("Launch Voice Input", "ref_images/gmaps_voice_icon.png");
	ActionMap.insert(std::make_pair("launchVoiceInput", action_tap_voiceInput));
}


GMapsAppProfile::~GMapsAppProfile()
{
}

void GMapsAppProfile::launchApp()
{
	std::string runnable_cmd = launchAppCommand();
	system(runnable_cmd.c_str());
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	// Launch driving mode
	AppInteraction *first_action = ActionMap["openHamburgerMenu"];
	AppInteraction *second_action = ActionMap["startDrivingMode"];
	AppInteraction *third_action = ActionMap["launchVoiceInput"];

	first_action->launchInteraction();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	second_action->launchInteraction();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	third_action->launchInteraction();
}