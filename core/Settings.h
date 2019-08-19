# pragma once
#ifndef SETTINGS_H
# define SETTINGS_H
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <map>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
using namespace std;

// Directory Settings.
const string SOUNDS_DIR = "res/sounds";
const string MUSIC_DIR = "res/music";
const string IMAGES_DIR = "res/images";
const string LOGS_DIR = "..logs/";
const string FONT_DIR = "res/font";
const string TEST_DIR = "..test/";

//Display Settings.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const bool FULLSCREEN = false;
const int MAX_HEIGHT = SCREEN_HEIGHT - 40;

// Ammo Settings.
const int BULLET_WIDTH = 3;
const int BULLET_HEIGHT = 10;
const int BULLETS_ALLOWED = 100;
const int BULLET_SPEED_FACTOR = 10;

//Ship Settings.
const int SHIP_SPEED_FACTOR = 5;
const int SHIP_PAN_SPEED = 2;
const double SHIP_REVERESE_SPEED = 0.8;

//Drop Settings.
const int REPAIR_KIT_VALUE = 1;

//Performace Settings
const int FPS = 60;

# endif
