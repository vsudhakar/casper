#include "stdafx.h"
#include "TapAppInteraction.h"

using namespace cv;

TapAppInteraction::TapAppInteraction()
{
	TapAppInteraction("", "");
}

TapAppInteraction::TapAppInteraction(std::string name, std::string icon_img)
{
	ActionType = Interaction::TAP;
	FriendlyName = name;
	icon_img_path = icon_img;
	FIXED = false;
}

TapAppInteraction::TapAppInteraction(std::string name, int set_x, int set_y)
{
	ActionType = Interaction::TAP;
	FriendlyName = name;
	x = set_x;
	y = set_y;
	FIXED = true;
}


TapAppInteraction::~TapAppInteraction()
{
}

/* Overloaded Functions */
std::string TapAppInteraction::buildAdbCommand() {
	std::string cmd = tapCommandBuilder(x, y);
	return cmd;
}

void TapAppInteraction::launchInteraction() {
	// Run on main thread via system() calls

	if (FIXED) {
		std::string runnableSystemCmd = buildAdbCommand();
		system(runnableSystemCmd.c_str());
		return;
	}
	
	// Grab Screencap from Device
	std::string screenCap_cmd = screenCapCommandBuilder("tapTrainImg.png");
	system(screenCap_cmd.c_str());
	std::string pull_cmd = pullCommandBuilder("tapTrainImg.png");
	system(pull_cmd.c_str());

	// Train on ScreenCap to get tap location
	Mat screen_img = imread("tapTrainImg.png", IMREAD_GRAYSCALE);
	Mat ref_img = imread(icon_img_path, IMREAD_GRAYSCALE);
	std::tuple<float, float> tap_estimate = iconLocationDetector(screen_img, ref_img);
	x = (int)floor(std::get<0>(tap_estimate));
	y = (int)floor(std::get<1>(tap_estimate));
	
	// Run tap interaction
	std::string runnableSystemCmd = buildAdbCommand();
	system(runnableSystemCmd.c_str());

}


/* Getters and Setters */

std::tuple<int, int> TapAppInteraction::getXY()
{
	return std::tuple<int, int>(x, y);
}

std::string TapAppInteraction::getIconImgPath()
{
	return icon_img_path;
}

int TapAppInteraction::setX(int new_x)
{
	x = new_x;
	return x;
}

int TapAppInteraction::setY(int new_y)
{
	y = new_y;
	return y;
}

std::string TapAppInteraction::setIconImgPath(std::string path)
{
	icon_img_path = path;
	return icon_img_path;
}
