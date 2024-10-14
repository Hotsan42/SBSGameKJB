#include <iostream>
#include "MainGame.h"

using namespace std;

void main()
{
	MainGame * mainGame = new MainGame();
	mainGame -> Release();
	delete mainGame;

	mainGame -> nullptr;
}