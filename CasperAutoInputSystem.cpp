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

#include "CommandParser.h"

using namespace std;

int main()
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
		if (userInput == 'Y' || userInput == 'y') {
			cout << "Selected Shuffle Play option for top result!\n";
			tCmd = tapCommandBuilder(80, 340);
			system(tCmd.c_str());
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			tCmd = tapCommandBuilder(358, 850);
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

