#include <time.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "Snake_Node.h"
#include "Control_Snake.h"
#include "Appearance.h"
#include "Button_Event.h"
#ifndef _SAVE_H_
#include "Save_Score.h"
#endif
using namespace cv;
using namespace std;

string Window = "Snake Game Plus Plus";
string NameGame = "Snake Plus";

void main(void)
{
	srand(time(NULL));
	FreeConsole();
	// Save && Load High Score
	SaveScore onePlayer[3], twoPlayer[3]; //  // [0] is easy mode, [1] is hard mode, [2] is god mode // Only save the hightest score
	loadFile(onePlayer, twoPlayer);
	//
	// Prepare for screen
	Mat3b _Screen_;
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	int width = 950, hight = 450;
	Scalar color[5] = { YELLOW, CYAN, PINK, LIME, WHITE };
	//
	// Prepare for Snake
	listNode Snake_1;
	listNode Snake_2;
	// Default
	addLast(Snake_1, 100, 200, Right);
	addLast(Snake_1, 90, 200, Right);
	addLast(Snake_1, 80, 200, Right);
	int Score1 = 2;
	int Score2 = 2;

	Point xyBait = NULL;
	bool fed = false;
	////
	// Config Game
	int delay = 0;
	int mode = 5;
	bool pause = false;
	bool help = false;
	bool wall = false;
	int Vmode = 1;// Vmode = 1: Nomarl, Vmode = 2: Hard, Vmode = 3: God.
	int Pmode = 1;//Pmode = 1: 1 Player, Pmode = 2: 2 Player.
	bool P1Lose = false;
	bool P2Lose = false;
	//Name
	string PName;
	//Data
	int * userdata = (int*)malloc(4 * sizeof(int));
	//Set Name
	namedWindow(Window);
	//Set Event Mouse
	setMouseCallback(Window, __CallBackFunc_Button, userdata);
	//Loading Screen
	loadingScreen(_Screen_, Window, NameGame);
	//Clear Screen
	_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	//Menu
	Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
	Init_Vmode(Vmode, delay, mode, wall);
	//Clear and Create new snake when game starts
	ResetSnake(Snake_1, Snake_2, Score1, Score2);
	//
	bool flag = false;
	while (true)
	{
		showAll(_Screen_, Snake_1, Snake_2, Score1, Score2, Pmode, mode);
		imshow(Window, _Screen_);
		customDelay(Score1, delay, flag, mode);
		int inpKey = 0;
		inpKey = waitKey(delay);
		if (inpKey == QUIT) {
			free(userdata);
			destroyList(Snake_1);
			destroyList(Snake_2);
			exit(EXIT_FAILURE);
		}
		if (inpKey == MENU) {
			Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
			Init_Vmode(Vmode, delay, mode, wall);
			ResetSnake(Snake_1, Snake_2, Score1, Score2);
			pause = false;
			continue;
		}
		if (inpKey == RES) {
			ResetSnake(Snake_1, Snake_2, Score1, Score2);
			randBait(xyBait);
			Init_Vmode(Vmode, delay, mode, wall);
		}
		if (inpKey == PAUSE) pause = !pause;
		if (inpKey == F1){
			pause = !pause;
			help = !help;
			showHelp(_Screen_, false);
			imshow(Window, _Screen_);
		}
		while (pause){
			if (!help) PauseText(_Screen_, 500, 250, "PAUSE", 4);
			imshow(Window, _Screen_);
			int inpKey = waitKey(10000);
			if (inpKey == PAUSE || inpKey == ESC) {
				pause = !pause;
				for (int i = 3; i >= 0; i--)
				{
					_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
					bodyShape(_Screen_, xyBait, RED); // Bait
					showAll(_Screen_, Snake_1, Snake_2, Score1, Score2, Pmode, mode);
					char text[2] = "";
					itoa(i, text, 10);
					if (i == 0)
					{
						PauseText(_Screen_, 500, 250, "START", 3);
					}
					else
						PauseText(_Screen_, 600, 250, text, 3);
					imshow(Window, _Screen_);
					waitKey(1000);
				}
				break;
			}
			if (inpKey == Key_N){
				showHelp(_Screen_, true);
				imshow(Window, _Screen_);
			}
			if (inpKey == Key_B){
				showHelp(_Screen_, false);
				imshow(Window, _Screen_);
			}
			if (inpKey == Key_A){
				showInfo(_Screen_);
				imshow(Window, _Screen_);
			}
			if (inpKey == QUIT) {
				free(userdata);
				destroyList(Snake_1);
				destroyList(Snake_2);
				exit(EXIT_FAILURE);
			}
			if (inpKey == MENU) {
				Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
				Init_Vmode(Vmode, delay, mode, wall);
				ResetSnake(Snake_1, Snake_2, Score1, Score2);
				pause = false;
				continue;
			}
			if (inpKey == RES) {
				ResetSnake(Snake_1, Snake_2, Score1, Score2);
				randBait(xyBait);
				Init_Vmode(Vmode, delay, mode, wall);
				break;
			}
		}
		_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
		if (fed == false){
			randBait(xyBait);
			fed = true;
		}
		//Snake 1
		if (Snake_1.head->x == xyBait.x && Snake_1.head->y == xyBait.y)
		{
			Score1++;
			if (Snake_1.tail->dir == Right) addLast(Snake_1, Snake_1.tail->x - 10, Snake_1.tail->y, Snake_1.tail->dir);
			if (Snake_1.tail->dir == Left) addLast(Snake_1, Snake_1.tail->x + 10, Snake_1.tail->y, Snake_1.tail->dir);
			if (Snake_1.tail->dir == Up) addLast(Snake_1, Snake_1.tail->x, Snake_1.tail->y + 10, Snake_1.tail->dir);
			if (Snake_1.tail->dir == Down) addLast(Snake_1, Snake_1.tail->x, Snake_1.tail->y - 10, Snake_1.tail->dir);
			fed = false;
		}
		//Snake 2
		if (Pmode == 2){
			if (Snake_2.head->x == xyBait.x && Snake_2.head->y == xyBait.y)
			{
				Score2++;
				if (Snake_2.tail->dir == Right) addLast(Snake_2, Snake_2.tail->x - 10, Snake_2.tail->y, Snake_2.tail->dir);
				if (Snake_2.tail->dir == Left) addLast(Snake_2, Snake_2.tail->x + 10, Snake_2.tail->y, Snake_2.tail->dir);
				if (Snake_2.tail->dir == Up) addLast(Snake_2, Snake_2.tail->x, Snake_2.tail->y + 10, Snake_2.tail->dir);
				if (Snake_2.tail->dir == Down) addLast(Snake_2, Snake_2.tail->x, Snake_2.tail->y - 10, Snake_2.tail->dir);
				fed = false;
			}
		}
		bodyShape(_Screen_, xyBait, RED);
		imshow(Window, _Screen_);
		// Switch State
		//Snake 1
		StateSnake(Snake_1, Snake_2, P1Lose, P2Lose, wall, Pmode);
		//Snake 2
		if (Pmode == 2){
			if (Snake_1.head->x == Snake_2.head->x && Snake_1.head->y == Snake_2.head->y){
				P1Lose = true;
				P2Lose = true;
			}
			StateSnake(Snake_2, Snake_1, P2Lose, P1Lose, wall, Pmode);
		}
		//Lose
		if (P1Lose == true && P2Lose == false){
			bool flag = false; // Remember High Score
			while (true) {
				_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
				showAll(_Screen_, Snake_1, Snake_2, Score1, Score2, Pmode, mode);
				putText(_Screen_, "Please press (R) to restart or", Point(400, 300), FONT_ITALIC, 0.5, WHITE);
				putText(_Screen_, "       press (Q) to quit GAME...", Point(400, 330), FONT_ITALIC, 0.5, WHITE);
				if (Pmode == 1) {
					PauseText(_Screen_, 325, 250, "GAME OVER :)", 3);
					if (checkScore(onePlayer, twoPlayer, Vmode, Pmode, Score1, 1)) flag = true;
					if (flag){
						saveFile(onePlayer, twoPlayer);
					}
				}
				else {
					PauseText(_Screen_, 500, 250, "P2 WIN", 3);
					if (checkScore(onePlayer, twoPlayer, Vmode, Pmode, Score2, 2)) flag = true;
					if (flag){
						saveFile(onePlayer, twoPlayer);
					}
				}

				imshow(Window, _Screen_);
				int inpKey = waitKey(10000);
				if (inpKey == QUIT) {
					free(userdata);
					destroyList(Snake_1);
					destroyList(Snake_2);
					exit(EXIT_FAILURE);
				}
				if (inpKey == MENU) {
					Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
					Init_Vmode(Vmode, delay, mode, wall);
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					pause = false;
					P2Lose = false;
					break;
				}
				if (inpKey == RES) {
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					P1Lose = false;
					randBait(xyBait);
					Init_Vmode(Vmode, delay, mode, wall);
					break;
				}
			}
		}
		if (P2Lose == true && P1Lose == false){
			bool flag = false; // Remember High Score
			while (true) {
				_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
				showAll(_Screen_, Snake_1, Snake_2, Score1, Score2, Pmode, mode);
				PauseText(_Screen_, 500, 250, "P1 WIN", 3);
				putText(_Screen_, "Please press (R) to restart or", Point(400, 300), FONT_ITALIC, 0.5, WHITE);
				putText(_Screen_, "       press (Q) to quit GAME...", Point(400, 330), FONT_ITALIC, 0.5, WHITE);
				if (checkScore(onePlayer, twoPlayer, Vmode, Pmode, Score1, 1)) flag = true;
				if (flag){
					saveFile(onePlayer, twoPlayer);
				}
				imshow(Window, _Screen_);
				int inpKey = waitKey(10000);
				if (inpKey == QUIT) {
					free(userdata);
					destroyList(Snake_1);
					destroyList(Snake_2);
					exit(EXIT_FAILURE);
				}
				if (inpKey == MENU) {
					Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
					Init_Vmode(Vmode, delay, mode, wall);
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					pause = false;
					P2Lose = false;
					break;
				}
				if (inpKey == RES) {
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					randBait(xyBait);
					Init_Vmode(Vmode, delay, mode, wall);
					P2Lose = false;
					break;
				}
			}
		}
		//When head snake 1 and head snake 2 meeting
		if (P1Lose == true && P2Lose == true){
			bool flag = false; // Remember High Score
			while (true) {
				_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
				showAll(_Screen_, Snake_1, Snake_2, Score1, Score2, Pmode, mode);
				if (Score2 > Score1){
					PauseText(_Screen_, 500, 250, "P2 WIN", 3);
					if (checkScore(onePlayer, twoPlayer, Vmode, Pmode, Score2, 2)) flag = true;
					if (flag){
						//putText(_Screen_, "P2 >> YOU GET HIGH SCORE!!!", Point(290, 400), FONT_ITALIC, 0.5, LIME);
						saveFile(onePlayer, twoPlayer);
					}
				}
				else if (Score2 < Score1){
					PauseText(_Screen_, 500, 250, "P1 WIN", 3);
					if (checkScore(onePlayer, twoPlayer, Vmode, Pmode, Score1, 1)) flag = true;
					if (flag){
						//putText(_Screen_, "P1 >> YOU GET HIGH SCORE!!!", Point(290, 400), FONT_ITALIC, 0.5, LIME);
						saveFile(onePlayer, twoPlayer);
					}
				}
				else
					PauseText(_Screen_, 500, 250, "Draw", 3);
				putText(_Screen_, "Please press (R) to restart or", Point(400, 300), FONT_ITALIC, 0.5, WHITE);
				putText(_Screen_, "       press (Q) to quit GAME...", Point(400, 330), FONT_ITALIC, 0.5, WHITE);
				imshow(Window, _Screen_);
				int inpKey = waitKey(10000);
				if (inpKey == QUIT) {
					free(userdata);
					destroyList(Snake_1);
					destroyList(Snake_2);
					exit(EXIT_FAILURE);
				}
				if (inpKey == MENU) {
					Menu(userdata, Snake_1, color, Vmode, Pmode, onePlayer, twoPlayer);
					Init_Vmode(Vmode, delay, mode, wall);
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					P2Lose = false;
					P1Lose = false;
					break;
				}
				if (inpKey == RES) {
					ResetSnake(Snake_1, Snake_2, Score1, Score2);
					randBait(xyBait);
					Init_Vmode(Vmode, delay, mode, wall);
					P2Lose = false;
					P1Lose = false;
					break;
				}
			}
		}
		// Control
		Control(Snake_1);
		if (Pmode == 2) Control_(Snake_2);
		moveSnake(Snake_1, wall);
		if (Pmode == 2) moveSnake(Snake_2, wall);
		imshow(Window, _Screen_);
	}
	destroyList(Snake_1);
	destroyList(Snake_2);
	free(userdata);
}