//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
CP_Vector windowSize;
CP_Image splashScreen;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{

	windowSize.x = 640;
	windowSize.y = 360;
	splashScreen = CP_Image_Load("./Assets/Digipen_WHITE.png");
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	float time = CP_System_GetSeconds();

	CP_System_SetWindowSize(1920, 1080);
	CP_Graphics_DrawRect(0, 0, 1920, 1080);
	if(time < 2)
		CP_Image_Draw(splashScreen, 1920 / 2, 1080 / 2, (float)CP_Image_GetWidth(splashScreen), (float)CP_Image_GetHeight(splashScreen), 255);

	float xScale = 0;
	float yPos = 0;
	if (time >= 2) 
	{
		if (time < 3)
		{
			xScale = 1 - (time - 2);
			yPos = -200 +((time-2) * 1000);
		}
		CP_Image_DrawAdvanced(splashScreen, 1920 / 2, (1080 / 2) + yPos, (float)CP_Image_GetWidth(splashScreen) * xScale, (float)CP_Image_GetHeight(splashScreen), 255, yPos + 200);
	}

	if (CP_Input_KeyDown(KEY_ESCAPE)) 
	{
		CP_Engine_Terminate();
	}

	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
