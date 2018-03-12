#pragma once
#include "AppInteraction.h"
#include <string>
#include <tuple>
#include "CommandParser.h"
#include "TapFeatureDetector.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

class TapAppInteraction :
	public AppInteraction
{
protected:
	int x;
	int y;
	bool FIXED;		// If true, will not run FLANN feature matching
	std::string icon_img_path;
public:
	TapAppInteraction();
	TapAppInteraction(std::string name, std::string icon_img);
	TapAppInteraction(std::string name, int set_x, int set_y);
	~TapAppInteraction();

	std::tuple<int, int> getXY();
	std::string getIconImgPath();
	
	int setX(int new_x);
	int setY(int new_y);

	std::string setIconImgPath(std::string path);

	virtual std::string buildAdbCommand();
	virtual void launchInteraction();
};

