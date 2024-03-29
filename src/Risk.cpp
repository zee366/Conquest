/*
	COMP 345 D Fall 2018
	Assignment 4
	Written by Team #9:
		Amritpal Padda	40042768
		Francois Roy	40065497
		Jason Brennan	27793928
		Olivier Hébert	40051654

	Submitted on November 29, 2018

	Program Description:
		This program is a demo for a console text-based implementation of the board game Risk.
		The program demonstrates the following requirements:
			- Part 1: New Strategies
				Added 2 new strategies
					- Random
					- Cheater
				Random players decide their actions randomly
				Cheater players auto conquer countries, and double the army value of their countries when reinforcing and fortifying
			- Part 2: Tournament
				Allow the user to choose normal mode or tournament mode on program start
				Tournament mode runs a tournament of multiple games on multiple maps with computer controlled strategies
				Results of the tournament are displayed afterwards
*/

#include "stdafx.h"
#include "Game.h"

// Entry point of the program. The Game object manages all aspects of a game session.
// Game::initialize() / Game::initializeTournament() handles creation of map, players, dice, cards, etc
// Game::run() / Game::runTournament() manages the game loop, executing each player's turn until the game ends
int main()
{
	cout << "---------------------------------------------------" << endl;
	cout << "-----------------------RISK------------------------" << endl;
	cout << "---------------------------------------------------" << endl << endl;

	Game game;

	unsigned int gameMode = 0;

	while (cout << "Choose a game Mode (1 - Normal, 2 - Tournament): " && (!(cin >> gameMode) || gameMode < 1 || gameMode > 2)) {
		cout << "That is not a number between 1 and 2" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	switch (gameMode) {
	case 1:
		game.initialize();
		game.run();
		break;
	case 2:
		game.initializeTournament();
		game.runTournament();
		break;
	}
    return 0;
}

