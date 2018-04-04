#include "Button_Event.h"
void Event_Button(int *key, Mat3b &_Screen_, Rect but_play, Rect but_exit, Rect but_opt, Rect but_high, int x, int y, bool &Next, int &Vmode, int &Pmode, SaveScore onePlayer[3], SaveScore twoPlayer[3]){
	if (*key == 1 && Next == false){//Mouse over
		if (but_play.contains(Point(x, y)))
		{
			_Screen_(but_play) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_play, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_play), PLAY_G, Point(but_play.width*0.07, but_play.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_exit.contains(Point(x, y)))
		{
			_Screen_(but_exit) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_exit, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_exit), EXIT_G, Point(but_exit.width*0.33, but_exit.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_opt.contains(Point(x, y)))
		{
			_Screen_(but_opt) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_opt, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_opt), OPTIONAL_G, Point(but_opt.width*0.14, but_opt.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_high.contains(Point(x, y)))
		{
			_Screen_(but_high) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_high, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_high), HIGH_G, Point(but_high.width*0.1, but_opt.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else{
			_Screen_(but_play) = Vec3b(255, 255, 255);
			_Screen_(but_exit) = Vec3b(255, 255, 255);
			_Screen_(but_opt) = Vec3b(255, 255, 255);
			_Screen_(but_high) = Vec3b(255, 255, 255);
			rectangle(_Screen_, but_play, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_exit, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_high, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_opt, Scalar(255, 255, 255), 2);
			putText(_Screen_(but_play), PLAY_G, Point(but_play.width*0.07, but_play.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_exit), EXIT_G, Point(but_exit.width*0.33, but_exit.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_opt), OPTIONAL_G, Point(but_opt.width*0.14, but_opt.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_high), HIGH_G, Point(but_high.width*0.1, but_high.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
	}
	else if (*key == 2){//Mouse press
		if (but_play.contains(Point(x, y)) && Next == false)
		{
			_Screen_(but_play) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_play, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_play), PLAY_G, Point(but_play.width*0.07, but_play.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			Next = true;
		}
		else if (but_exit.contains(Point(x, y)))
		{
			_Screen_(but_exit) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_exit, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_exit), EXIT_G, Point(but_exit.width*0.33, but_exit.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			exit(EXIT_FAILURE);
		}
		else if (but_opt.contains(Point(x, y)))
		{
			_Screen_(but_opt) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_opt, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_opt), OPTIONAL_G, Point(but_opt.width*0.14, but_opt.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			Optional(Vmode, Pmode);
			*key = 0;
		}
		else if (but_high.contains(Point(x, y)))
		{
			_Screen_(but_high) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_high, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_high), HIGH_G, Point(but_high.width*0.1, but_high.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			showHighScore(onePlayer, twoPlayer);
			*key = 0;
		}
	}
}
int Event_Button_Opt(int *key, Mat3b &_Screen_, Rect but_left, Rect but_right, Rect but_pleft, Rect but_pright, Rect but_back, int x, int y, int &Vmode, int &Pmode){
	if (*key == 1){//Mouse over
		if (but_left.contains(Point(x, y)))
		{
			_Screen_(but_left) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_left, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_left), "<", Point(but_left.width*0.4, but_left.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_right.contains(Point(x, y)))
		{
			_Screen_(but_right) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_right, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_right), ">", Point(but_right.width*0.4, but_right.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_pleft.contains(Point(x, y)))
		{
			_Screen_(but_pleft) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_pleft, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_pleft), "<", Point(but_pleft.width*0.4, but_pleft.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_pright.contains(Point(x, y)))
		{
			_Screen_(but_pright) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_pright, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_pright), ">", Point(but_pright.width*0.4, but_pright.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else if (but_back.contains(Point(x, y)))
		{
			_Screen_(but_back) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_back, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else{
			_Screen_(but_left) = Vec3b(255, 255, 255);
			_Screen_(but_right) = Vec3b(255, 255, 255);
			_Screen_(but_pleft) = Vec3b(255, 255, 255);
			_Screen_(but_pright) = Vec3b(255, 255, 255);
			_Screen_(but_back) = Vec3b(255, 255, 255);
			rectangle(_Screen_, but_left, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_right, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_pleft, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_pright, Scalar(255, 255, 255), 2);
			rectangle(_Screen_, but_back, Scalar(255, 255, 255), 2);
			putText(_Screen_(but_left), "<", Point(but_left.width*0.4, but_left.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_right), ">", Point(but_right.width*0.4, but_right.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_pleft), "<", Point(but_pleft.width*0.4, but_pleft.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_pright), ">", Point(but_pright.width*0.4, but_pright.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
	}
	else if (*key == 2){//Mouse press
		if (but_left.contains(Point(x, y)))
		{
			_Screen_(but_left) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_left, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_left), "<", Point(but_left.width*0.4, but_left.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			if (Vmode >= 2) Vmode--;
		}
		else if (but_right.contains(Point(x, y)))
		{
			_Screen_(but_right) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_right, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_right), ">", Point(but_right.width*0.4, but_right.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			if (Vmode <= 2) Vmode++;
		}
		else if (but_pleft.contains(Point(x, y)))
		{
			_Screen_(but_pleft) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_pleft, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_pleft), "<", Point(but_pleft.width*0.4, but_pleft.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			if (Pmode == 2) Pmode = 1;
		}
		else if (but_pright.contains(Point(x, y)))
		{
			_Screen_(but_pright) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_pright, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_pright), ">", Point(but_pright.width*0.4, but_pright.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			if (Pmode == 1) Pmode = 2;
		}
		else if (but_back.contains(Point(x, y)))
		{
			_Screen_(but_back) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_back, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			return -1;
		}
	}
	return 0;
}
int Event_HighScore(int *key, Mat3b &_Screen_, Rect but_back, int x, int y){
	if (*key == 1){//Mouse over
		if (but_back.contains(Point(x, y)))
		{
			_Screen_(but_back) = Vec3b(0, 255, 255);
			rectangle(_Screen_, but_back, Scalar(0, 255, 255), 2);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
		else{
			_Screen_(but_back) = Vec3b(255, 255, 255);
			rectangle(_Screen_, but_back, Scalar(255, 255, 255), 2);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
		}
	}
	else if (*key == 2){//Mouse press
		if (but_back.contains(Point(x, y)))
		{
			_Screen_(but_back) = Vec3b(0, 0, 255);
			rectangle(_Screen_, but_back, Scalar(0, 0, 255), 2);
			putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
			imshow("Snake Game Plus Plus", _Screen_);
			waitKey(100);
			return -1;
		}
	}
	return 0;
}
void __CallBackFunc_Button(int event, int x, int y, int flags, void* userdata)
{
	int * tmp = (int*)userdata;
	//Event Menu
	if (event == EVENT_MOUSEMOVE)
	{
		*tmp = x;
		*(tmp + 1) = y;
		*(tmp + 2) = 1;
	}

	if (event == EVENT_LBUTTONDOWN)
	{
		*tmp = x;
		*(tmp + 1) = y;
		*(tmp + 2) = 2;
	}

	if (event == EVENT_LBUTTONUP)
	{
		*tmp = x;
		*(tmp + 1) = y;
		*(tmp + 2) = 3;
	}
	waitKey(1);
}