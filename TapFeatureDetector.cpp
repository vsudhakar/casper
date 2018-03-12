/*
	Based off of A. Huaman's code at opencv.org
*/

#include "stdafx.h"
#include "TapFeatureDetector.h"

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace cv::xfeatures2d;

std::tuple<float, float> iconLocationDetector(Mat screen_img, Mat icon_img)
{
	// Find Matches
	int minHessian = 400;
	Ptr<SURF> detector = SURF::create(minHessian);
	detector->setHessianThreshold(minHessian);
	std::vector<KeyPoint> keypoints_screen, keypoints_ref;
	Mat descriptors_screen, descriptors_ref;
	detector->detectAndCompute(screen_img, Mat(), keypoints_screen, descriptors_screen);
	detector->detectAndCompute(icon_img, Mat(), keypoints_ref, descriptors_ref);
	FlannBasedMatcher matcher;
	std::vector<DMatch> matches;
	matcher.match(descriptors_ref, descriptors_screen, matches);

	// Separate "good" matches
	double max_dist = 0; double min_dist = 100;
	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_ref.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}

	std::vector< DMatch > good_matches;
	for (int i = 0; i < descriptors_ref.rows; i++)
	{
		if (matches[i].distance <= max(2 * min_dist, 0.02))
		{
			good_matches.push_back(matches[i]);
		}
	}
	
	// Find mass center of well matched points
	std::vector<Point2f> well_matched_points;
	std::vector<int> good_screen_matches;
	for (int i = 0; i < good_matches.size(); i++) {
		good_screen_matches.push_back(good_matches[i].trainIdx);
	}
	KeyPoint::convert(keypoints_screen, well_matched_points, good_screen_matches);
	float sum_x = 0.;
	float sum_y = 0.;
	for (int i = 0; i < well_matched_points.size(); i++) {
		sum_x += well_matched_points[i].x;
		sum_y += well_matched_points[i].y;
	}
	Point2f centerMass(sum_x / well_matched_points.size(), sum_y / well_matched_points.size());

	
	/* DEBUG
	DISPLAY THE MATCHED FEATURES TO VISUALLY VERIFY
	*/
	//-- Draw only "good" matches
	/*
	Mat img_matches;
	drawMatches(icon_img, keypoints_ref, screen_img, keypoints_screen,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Show detected matches
	imshow("Good Matches", img_matches);
	waitKey(0);
	*/


	return std::tuple<float, float>(centerMass.x, centerMass.y);

}
