#pragma once
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "Snake_Node.h"
#include <Windows.h>
using namespace cv;
using namespace std;

//Control
#define MENU 109
#define QUIT 113
#define RES 114
#define F1 7340032
#define ESC 27
#define PAUSE 32
#define UP 2490368
#define DOWN 2621440
#define LEFT 2424832
#define RIGHT 2555904
#define STEP 10
#define Key_W 119
#define Key_S 115
#define Key_D 100
#define Key_A 97
#define Key_N 110
#define Key_B 98
//

void Control(listNode &Snake_);
void Control_(listNode &Snake_);
void randBait(Point &xy);
void moveSnake(listNode &Snake_, bool Wall = false);
void customDelay(int &Score, int &Delay, bool &flag, int &mode);
void ResetSnake(listNode &Snake_, listNode &Snake__, int &Score_, int &Score__);
void StateSnake(listNode Snake_1, listNode Snake_2, bool &P1Lose, bool &P2Lose, bool wall, int Pmode);