#include "KeyBoard.h"


char getKey(){
	if (GetAsyncKeyState(0x30)) return '0';
	else
	if (GetAsyncKeyState(0x31)) return '1';
	else
	if (GetAsyncKeyState(0x32)) return '2';
	else
	if (GetAsyncKeyState(0x33)) return '3';
	else
	if (GetAsyncKeyState(0x34)) return '4';
	else
	if (GetAsyncKeyState(0x35)) return '5';
	else
	if (GetAsyncKeyState(0x36)) return '6';
	else
	if (GetAsyncKeyState(0x37)) return '7';
	else
	if (GetAsyncKeyState(0x38)) return '8';
	else
	if (GetAsyncKeyState(0x39)) return '9';
	else
	if (GetAsyncKeyState(0x41)) return 'a';
	else
	if (GetAsyncKeyState(0x42)) return 'b';
	else
	if (GetAsyncKeyState(0x43)) return 'c';
	else
	if (GetAsyncKeyState(0x44)) return 'd';
	else
	if (GetAsyncKeyState(0x45)) return 'e';
	else
	if (GetAsyncKeyState(0x46)) return 'f';
	else
	if (GetAsyncKeyState(0x47)) return 'g';
	else
	if (GetAsyncKeyState(0x48)) return 'h';
	else
	if (GetAsyncKeyState(0x49)) return 'i';
	else
	if (GetAsyncKeyState(0x4A)) return 'j';
	else
	if (GetAsyncKeyState(0x4B)) return 'k';
	else
	if (GetAsyncKeyState(0x4C)) return 'l';
	else
	if (GetAsyncKeyState(0x4D)) return 'm';
	else
	if (GetAsyncKeyState(0x4E)) return 'n';
	else
	if (GetAsyncKeyState(0x4F)) return 'o';
	else
	if (GetAsyncKeyState(0x50)) return 'p';
	else
	if (GetAsyncKeyState(0x51)) return 'q';
	else
	if (GetAsyncKeyState(0x52)) return 'r';
	else
	if (GetAsyncKeyState(0x53)) return 's';
	else
	if (GetAsyncKeyState(0x54)) return 't';
	else
	if (GetAsyncKeyState(0x55)) return 'u';
	else
	if (GetAsyncKeyState(0x56)) return 'v';
	else
	if (GetAsyncKeyState(0x57)) return 'w';
	else
	if (GetAsyncKeyState(0x58)) return 'x';
	else
	if (GetAsyncKeyState(0x59)) return 'y';
	else
	if (GetAsyncKeyState(0x5A)) return 'z';
	else
	if (GetAsyncKeyState(0x20)) return ' ';
	else
	if (GetAsyncKeyState(0x0D)) return '\n';
	else
	if (GetAsyncKeyState(0x08)) return 0;
	else
	if (GetAsyncKeyState(0x60)) return '0';
	else
	if (GetAsyncKeyState(0x61)) return '1';
	else
	if (GetAsyncKeyState(0x62)) return '2';
	else
	if (GetAsyncKeyState(0x63)) return '3';
	else
	if (GetAsyncKeyState(0x64)) return '4';
	else
	if (GetAsyncKeyState(0x65)) return '5';
	else
	if (GetAsyncKeyState(0x66)) return '6';
	else
	if (GetAsyncKeyState(0x67)) return '7';
	else
	if (GetAsyncKeyState(0x68)) return '8';
	else
	if (GetAsyncKeyState(0x69)) return '9';
	else return -1;

}
void getName(char s[MAX], int Pmode, int Player){
	//Screen
	Mat3b _Screen_;
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	int len = 0;
	s[0] = '\0';
	while (true){
		char key = getKey();
		if (key != -1){
			if (key == '\n'){
				break;
			}
			else{
				if (key == 0){
					if (len > 1){
						s[len - 1] = '\0';
						len--;
					}
					else {
						s[0] = '\0';
						len = 0;
					}
				}
				else{
					if (len < MAX){
						s[len] = key;
						len++;
						s[len] = '\0';
					}
				}
			}
		}
		_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
		if (Pmode == 1)
			putText(_Screen_, "YOU GET HIGH SCORE!!!", Point(150, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 255, 0)); 
		else{
			if (Player == 1){
				putText(_Screen_, "P1 >> YOU GET HIGH SCORE!!!", Point(50, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 255, 0));
			}
			else{
				putText(_Screen_, "P2 >> YOU GET HIGH SCORE!!!", Point(50, 60), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 255, 0));
			}
		}
		putText(_Screen_, "Your Name:", Point(40, 120), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 0));
		putText(_Screen_, s, Point(140, 120), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 0));
		putText(_Screen_, "Luu y: Ten toi da la 10 ki tu thuong hoac so", Point(140, 150), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 0));
		imshow("Snake Game Plus Plus", _Screen_);
		waitKey(200);
	}
}