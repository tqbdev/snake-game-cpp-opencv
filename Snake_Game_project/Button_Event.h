#pragma once
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "Snake_Node.h"
#include "Appearance.h"
#include "Save_Score.h"
using namespace cv;
using namespace std;

//Color
#define YELLOW Scalar(255,255,0)
#define CYAN Scalar(0,255,255)
#define LIME Scalar(0,255,0)
#define PINK Scalar(255,0,255)
#define RED Scalar(0, 0, 255)
#define BLACK Scalar(0,0,0)
#define WHITE Scalar(255,255,255)

#define PLAY_G "Play Game"
#define EXIT_G "Exit"
#define OPTIONAL_G "Optional"
#define HIGH_G "HighScore"


void Event_Button(int *key, Mat3b &_Screen_, Rect but_play, Rect but_exit, Rect but_opt, Rect but_high, int x, int y, bool &Next, int &Vmode, int &Pmode, SaveScore onePlayer[3], SaveScore twoPlayer[3]);
int Event_Button_Opt(int *key, Mat3b &_Screen_, Rect but_left, Rect but_right, Rect but_pleft, Rect but_pright, Rect but_back, int x, int y, int &Vmode, int &Pmode);
void __CallBackFunc_Button(int event, int x, int y, int flags, void* userdata);
int Event_HighScore(int *key, Mat3b &_Screen_, Rect but_back, int x, int y);