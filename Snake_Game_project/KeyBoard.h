#pragma once
#include <iostream>
#include <Windows.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#define MAX 10
using namespace cv;
using namespace std;

char getKey();
void getName(char s[MAX], int Pmode,int Player);