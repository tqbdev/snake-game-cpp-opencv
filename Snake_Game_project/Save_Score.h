#pragma once
#include <iostream>
#include "KeyBoard.h"
#define File_Name "data.config"

#ifndef _SAVE_H_
#define _SAVE_H_
struct SaveScore{
	char name[10];
	int score;
};
#endif
void loadFile(SaveScore onePlayer[3], SaveScore twoPlayer[3]);
void saveFile(SaveScore onePlayer[3], SaveScore twoPlayer[3]);
bool checkScore(SaveScore onePlayer[3], SaveScore twoPlayer[3], int &vMode, int &pMode, int &Score, int Player);
