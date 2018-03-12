#include <tuple>
#include "opencv2/core.hpp"

using namespace cv;

#pragma once
#ifndef TAPFEATUREDETECTOR_H
#define TAPFEATUREDETECTOR_H

std::tuple<float, float> iconLocationDetector(Mat screen_img, Mat ref_img);

#endif // !TAPFEATUREDETECTOR_H
