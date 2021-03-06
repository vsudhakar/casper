// CasperAutoInputSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <regex>
#include <thread>
#include <chrono>
#include <string>
#include <tuple>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include "CommandParser.h"
#include "TapFeatureDetector.h"

#include "AppProfile.h"
#include "SpotifyAppProfile.h"
#include "GMapsAppProfile.h"

using namespace cv;

using namespace std;

int imgCompTester()
{	
	cout << "Test image comparison\n";
	// Load img files
	Mat screen_img = imread("screen.png", IMREAD_GRAYSCALE);
	Mat icon_img = imread("icon.png", IMREAD_GRAYSCALE);
	if (!screen_img.data || !icon_img.data)
	{
		std::cout << " --(!) Error reading images " << std::endl; return -1;
	}
	std::tuple<float, float> icon_estimate = iconLocationDetector(screen_img, icon_img);
	cout << "Point is estimated at: (" << std::to_string(std::get<0>(icon_estimate)) << " , " << std::to_string(std::get<1>(icon_estimate)) << ")\n";
	return 0;
}

int appTester()
{
	cout << "Hello! Welcome to Casper, your automated input system while driving.\n";
	char userInput;
	cout << "Let's execute a sample Spotify run! Shall we?\n (Y/N)\n";
	cin >> userInput;
	if (userInput == 'Y' || userInput == 'y') {
		cout << "Let's begin.\n";
		cout << "Issuing ADB shell commands via system()\n";
		std::string aCmd = launchAppCommandBuilder("com.spotify.music");
		system(aCmd.c_str());
		// Sleep until spotify is loaded
		std::this_thread::sleep_for(std::chrono::milliseconds(7500));
		cout << "Spotify has been opened.\n";
		cout << "Now issuing events...\n";
		std::string tCmd;
		tCmd = tapCommandBuilder(360, 1150);
		cout << tCmd << "\n";
		system(tCmd.c_str());
		tCmd = tapCommandBuilder(360, 100);
		cout << tCmd << "\n";
		system(tCmd.c_str());

		cout << "What would you like to listen to?\n";
		std::string searchQuery;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.sync();
		std::getline(std::cin, searchQuery);
		cout << "Searching for " << searchQuery << "\n";
		std::string adbCommand = textCommandBuilder(searchQuery);
		//std::string adbCommand = "adb shell input text " + searchQuery;
		system(adbCommand.c_str());
		cout << "I think I found something for " << searchQuery << "\nWould you like me to play it?\n";
		cout << "(Y/N)\n";
		cin >> userInput;
		cout << "Selecting top result";
		tCmd = tapCommandBuilder(80, 340);
		system(tCmd.c_str());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		if (userInput == 'Y' || userInput == 'y') {
			cout << "Selected Shuffle Play option for top result!\n";
			cout << "Pulling screenshot to match shuffle play\n";
			std::string scCmd = screenCapCommandBuilder("currentDisplay.png");
			std::string fCmd = pullCommandBuilder("currentDisplay.png");
			system(scCmd.c_str());
			system(fCmd.c_str());
			// Compare images to find estimated tap location
			Mat screen_img = imread("currentDisplay.png", IMREAD_GRAYSCALE);
			Mat icon_img = imread("icon.png", IMREAD_GRAYSCALE);
			std::tuple<float, float> icon_estimate = iconLocationDetector(screen_img, icon_img);
			cout << "Point is estimated at: (" << std::to_string(std::get<0>(icon_estimate)) << " , " << std::to_string(std::get<1>(icon_estimate)) << ")\n";
			tCmd = tapCommandBuilder((int) floor(std::get<0>(icon_estimate)), (int) floor(std::get<1>(icon_estimate)));
			system(tCmd.c_str());
		}
		else {
			cout << "Okay, maybe next time... :)";
		}
	}
	else {
		cout << "Awh. I was really looking forward to trying out something cool.";
	}
	
    return 0;
}

void appProfileDemo() {
	/*
	SpotifyAppProfile* spotify_instance = new SpotifyAppProfile();
	spotify_instance->launchApp();
	std::this_thread::sleep_for(std::chrono::milliseconds(7000));

	cout << "What would you like to listen to?\n";
	std::string searchQuery;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.sync();
	std::getline(std::cin, searchQuery);
	cout << "Searching for " << searchQuery << "\n";

	spotify_instance->runSearchQuery(searchQuery);

	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	cout << "Shuffle play started!\n";
	spotify_instance->shufflePlay();

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	cout << "Pause!\n";
	spotify_instance->pause();

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	cout << "Play again! Everything is better with music...\n";
	spotify_instance->play();
	*/

	GMapsAppProfile* gmaps_instance = new GMapsAppProfile();
	gmaps_instance->launchApp();
}

void debugShufflePlay()
{
	SpotifyAppProfile* spotify_instance = new SpotifyAppProfile();
	cout << "Calling Shuffle Play action.\n";
	spotify_instance->shufflePlay();
}

int main() {
	int appChoice;
	cout << "Welcome to Casper!\n[1] Image Comparison Demo\n[2] App Clickthrough Demo\n[3] App Profile Demo\n[4] Debug Spotify Shuffle Play\n";
	cin >> appChoice;
	if (appChoice == 1) {
		imgCompTester();
	}
	else if (appChoice == 2) {
		appTester();
	}
	else if (appChoice == 3) {
		appProfileDemo();
	}
	else if (appChoice == 4) {
		debugShufflePlay();
	}
	else {
		cout << "Sorry! " << std::to_string(appChoice) << " is an invalid option. Try again.";
		main();
	}
	return 0;
}