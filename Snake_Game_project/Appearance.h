#pragma once
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "Snake_Node.h"
#include "Button_Event.h"
#include "Control_Snake.h"
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

#define VER "Ver 2.0"

void BoardLimit(Mat &img, int &x2, int &y2);
void putScore(Mat &img, int score, int score_, int Pmode);
void PauseText(Mat &img, int x, int y, char *text, int size);
void headShape(Mat &img, int x, int y, Dir dir, bool flag);
void bodyShape(Mat &img, Point &xy, Scalar &color);
void loadingScreen(Mat &img, string &Window, string &NameGame);
void putVer(Mat &img);
void putMode(Mat &img, int &mode);
void showSnake(Mat &img, Scalar *color, listNode &Snake_, bool flag);
void Menu(int* userdata, listNode &Snake_, Scalar color[4], int &Vmode, int &Pmode, SaveScore onePlayer[3], SaveScore twoPlayer[3]);
void Optional(int &Vmode, int &Pmode);
void Init_Vmode(int Vmode, int &delay, int &mode, bool &wall);
void showHighScore(SaveScore onePlayer[], SaveScore twoPlayer[]);
void showHelp(Mat &img,bool flag);
void showAll(Mat3b _Screen_, listNode Snake_1, listNode Snake_2, int Score1, int Score2, int Pmode, int mode);
void showInfo(Mat &img);