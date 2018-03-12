#include "stdafx.h"
#include "TapAppInteraction.h"


TapAppInteraction::TapAppInteraction()
{
	TapAppInteraction("");
}

TapAppInteraction::TapAppInteraction(std::string name)
{
	ActionType = Interaction::TAP;

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
	
	// Grab Screencap from Device

	// Train on Screencrap to get tap location
	
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
