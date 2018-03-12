#pragma once
#include "AppInteraction.h"
#include <string>
#include <tuple>
#include "CommandParser.h"

class TapAppInteraction :
	public AppInteraction
{
protected:
	int x;
	int y;
	std::string icon_img_path;
public:
	TapAppInteraction();
	TapAppInteraction(std::string name);
	~TapAppInteraction();

	std::tuple<int, int> getXY();
	std::string getIconImgPath();
	
	int setX(int new_x);
	int setY(int new_y);

	std::string setIconImgPath(std::string path);

	virtual std::string buildAdbCommand();
	virtual void launchInteraction();
};

