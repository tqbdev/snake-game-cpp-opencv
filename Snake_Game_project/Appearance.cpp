#include "Appearance.h"


void BoardLimit(Mat &img, int &x2, int &y2)
{
	int x1 = 50, y1 = 50;
	rectangle(img, Point(x1, y1), Point(x2, y2), RED, 2);
}

void putScore(Mat &img, int score, int score_, int Pmode)
{
	char string[20] = "Score : ";
	char num[10] = "";
	strcat(string, itoa(score, num, 10));
	if (Pmode == 1)
		putText(img, string, Point(850, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	else
	{
		putText(img, "P1:", Point(780, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
		putText(img, itoa(score, num, 10), Point(810, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
		putText(img, "P2:", Point(850, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
		putText(img, itoa(score_, num, 10), Point(880, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	}
	putText(img, "Quit (Q)", Point(50, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	putText(img, "Restart (R)", Point(150, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	putText(img, "PAUSE (Space)", Point(270, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	putText(img, "Menu (M)", Point(420, 30), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
	putText(img, "HELP (F1)", Point(50, 480), FONT_HERSHEY_SIMPLEX, 0.5, LIME);
}

void PauseText(Mat &img, int x, int y, char *text, int size)
{
	putText(img, text, Point(x - size * 50, y), FONT_HERSHEY_SIMPLEX, size, LIME, 2);
}

void headShape(Mat &img, int x, int y, Dir dir, bool flag)
{
	int lineType = 8;
	int w = 8;
	/** Create some points */
	Point rook_points[1][3];
	// 4 chiều đầu rắn
	if (dir == Right)
	{
		rook_points[0][0] = Point(x, y - w);
		rook_points[0][2] = Point(w + x, y);
		rook_points[0][1] = Point(x, y + w);
	}
	else
	if (dir == Left)
	{
		rook_points[0][0] = Point(x, y - w);
		rook_points[0][2] = Point(x - w, y);
		rook_points[0][1] = Point(x, y + w);
	}
	else
	if (dir == Up)
	{
		rook_points[0][0] = Point(x - w, y);
		rook_points[0][2] = Point(x, y - w);
		rook_points[0][1] = Point(x + w, y);
	}
	else
	if (dir == Down)
	{
		rook_points[0][0] = Point(x - w, y);
		rook_points[0][2] = Point(x, y + w);
		rook_points[0][1] = Point(x + w, y);
	}

	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 3 };
	if (flag == true)
		fillPoly(img, ppt, npt, 1, PINK, lineType);
	else
		fillPoly(img, ppt, npt, 1, CYAN, lineType);

}

void bodyShape(Mat &img, Point &xy, Scalar &color)
{
	int thickness = -1;
	int lineType = 8;
	int w = 200;
	circle(img,
		xy,
		w / 32.0,
		color,
		thickness,
		lineType);
}

void loadingScreen(Mat &img, string &Window, string &NameGame){
	putText(img, NameGame, Point(50, 150), FONT_HERSHEY_PLAIN, 10, RED, 5);
	putVer(img);
	int percent = 0;
	while (percent < 5){
		Point rook_points[1][4];
		rook_points[0][0] = Point(250, 400);
		rook_points[0][1] = Point(250, 450);
		rook_points[0][3] = Point(250 + 125 * percent, 400);
		rook_points[0][2] = Point(250 + 125 * percent, 450);
		const Point* ppt[1] = { rook_points[0] };
		int npt[] = { 4 };
		fillPoly(img, ppt, npt, 1, CYAN, 8);
		putText(img, "Loading", Point(350, 300), FONT_HERSHEY_SCRIPT_COMPLEX, 3, LIME, 2);
		rectangle(img, Point(250, 400), Point(750, 450), CYAN, 1);
		imshow(Window, img);
		waitKey(1000);
		percent++;
	}
}

void putVer(Mat &img){
	putText(img, VER, Point(915, 485), FONT_HERSHEY_PLAIN, 1, WHITE, 1);
}

void putMode(Mat &img, int &mode){
	if (mode == 4) { // Mode Easy
		putText(img, "MODE EASY", Point(550, 30), FONT_HERSHEY_PLAIN, 1.25, WHITE, 2);
		return;
	}
	if (mode == 3) { // Mode Hard
		putText(img, "MODE HARD", Point(550, 30), FONT_HERSHEY_PLAIN, 1.25, WHITE, 2);
		return;
	}
	if (mode == 2) { // Mode God
		putText(img, "MODE GOD", Point(550, 30), FONT_HERSHEY_PLAIN, 1.25, WHITE, 2);
		return;
	}
}

void showSnake(Mat &img, Scalar *color, listNode &Snake_, bool flag){
	int i = 0;
	headShape(img, Snake_.head->x, Snake_.head->y, Snake_.head->dir, flag);
	for (Node_ * p = Snake_.head->pNext; p; p = p->pNext)
	{
		i++;
		bodyShape(img, Point(p->x, p->y), color[i % 4]);
	}
}

void Menu(int* userdata, listNode &Snake_, Scalar color[4], int &Vmode, int &Pmode, SaveScore onePlayer[3], SaveScore twoPlayer[3]){
	//Screen
	Mat3b _Screen_;
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
	_Screen_ = Mat3b(500, 1000, CV_32FC3);

	Rect but_play;
	Rect but_exit;
	Rect but_opt;
	Rect but_high;
	bool Next = false;
	*(userdata + 3) = Next;
	//Reset
	destroyList(Snake_);
	addLast(Snake_, 100, 200, Right);
	addLast(Snake_, 90, 200, Right);
	addLast(Snake_, 80, 200, Right);

	//Menu Game
	but_play = Rect(450, 230, 100, 50);
	but_opt = Rect(450, 290, 100, 50);
	but_high = Rect(450, 350, 100, 50);
	but_exit = Rect(450, 410, 100, 50);
	_Screen_(but_play) = Vec3b(255, 255, 255);
	_Screen_(but_exit) = Vec3b(255, 255, 255);
	_Screen_(but_high) = Vec3b(255, 255, 255);
	_Screen_(but_opt) = Vec3b(255, 255, 255);
	putText(_Screen_, "Snake Plus", Point(50, 150), FONT_HERSHEY_PLAIN, 10, RED, 5);
	putText(_Screen_(but_play), PLAY_G, Point(but_play.width*0.07, but_play.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(but_exit), EXIT_G, Point(but_exit.width*0.33, but_exit.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(but_high), HIGH_G, Point(but_high.width*0.1, but_high.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(but_opt), OPTIONAL_G, Point(but_exit.width*0.15, but_exit.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	while (!Next)
	{
		setMouseCallback("Snake Game Plus Plus", __CallBackFunc_Button, userdata);
		Event_Button(userdata + 2, _Screen_, but_play, but_exit, but_opt, but_high, *(userdata), *(userdata + 1), Next, Vmode, Pmode, onePlayer, twoPlayer);
		imshow("Snake Game Plus Plus", _Screen_);
		showSnake(_Screen_, color, Snake_, 0);
		moveSnake(Snake_);
		putVer(_Screen_);
		Event_Button(userdata + 2, _Screen_, but_play, but_exit, but_opt, but_high, *(userdata), *(userdata + 1), Next, Vmode, Pmode, onePlayer, twoPlayer);
		imshow("Snake Game Plus Plus", _Screen_);
		waitKey(1);
	}
}
void Optional(int &Vmode, int &Pmode){
	Mat3b _Screen_;
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	_Screen_ = Mat::zeros(_Screen_.rows, _Screen_.cols, CV_32FC3);
	_Screen_ = Mat3b(500, 1000, CV_32FC3);
	int * userdata = (int*)malloc(4 * sizeof(int));
	setMouseCallback("Snake Game Plus Plus", __CallBackFunc_Button, userdata);
	//Tile
	putText(_Screen_, "Optional", Point(175, 150), FONT_HERSHEY_PLAIN, 10, RED, 5);
	//Mode
	Rect but_left;
	Rect but_right;
	Rect rec_bar_mode;
	but_left = Rect(350, 200, 50, 50);
	but_right = Rect(600, 200, 50, 50);
	rec_bar_mode = Rect(410, 200, 180, 50);
	_Screen_(but_left) = Vec3b(255, 255, 255);
	_Screen_(but_right) = Vec3b(255, 255, 255);
	_Screen_(rec_bar_mode) = Vec3b(255, 255, 255);
	putText(_Screen_(but_left), "<", Point(but_left.width*0.4, but_left.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(but_right), ">", Point(but_right.width*0.4, but_right.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(rec_bar_mode), "Normal", Point(420, 240), FONT_HERSHEY_PLAIN, 3, WHITE, 3, 8);
	//Player - Player
	Rect but_pleft;
	Rect but_pright;
	Rect rec_bar_player;
	but_pleft = Rect(350, 300, 50, 50);
	but_pright = Rect(600, 300, 50, 50);
	rec_bar_player = Rect(410, 300, 180, 50);
	_Screen_(but_pleft) = Vec3b(255, 255, 255);
	_Screen_(but_pright) = Vec3b(255, 255, 255);
	_Screen_(rec_bar_player) = Vec3b(255, 255, 255);
	putText(_Screen_(but_pleft), "<", Point(but_pleft.width*0.4, but_pleft.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_(but_pright), ">", Point(but_pright.width*0.4, but_pright.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	putText(_Screen_, "1Player", Point(410, 340), FONT_HERSHEY_PLAIN, 3, WHITE, 3, 8);
	//Button back;
	Rect but_back;
	but_back = Rect(700, 375, 100, 50);
	_Screen_(but_back) = Vec3b(255, 255, 255);
	putText(_Screen_(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	while (true){
		setMouseCallback("Snake Game Plus Plus", __CallBackFunc_Button, userdata);
		if (Event_Button_Opt(userdata + 2, _Screen_, but_left, but_right, but_pleft, but_pright, but_back, *(userdata), *(userdata + 1), Vmode, Pmode) == -1){
			break;
		}
		if (Vmode == 1){
			_Screen_(rec_bar_mode) = Vec3b(255, 255, 255);
			putText(_Screen_, "Normal", Point(420, 240), FONT_HERSHEY_PLAIN, 3, BLACK, 3, 8);
		}
		else if (Vmode == 2){
			_Screen_(rec_bar_mode) = Vec3b(255, 255, 255);
			putText(_Screen_, "Hard", Point(445, 240), FONT_HERSHEY_PLAIN, 3, BLACK, 3, 8);
		}
		else{
			_Screen_(rec_bar_mode) = Vec3b(255, 255, 255);
			putText(_Screen_, "God", Point(450, 240), FONT_HERSHEY_PLAIN, 3, BLACK, 3, 8);
		}
		if (Pmode == 1){
			_Screen_(rec_bar_player) = Vec3b(255, 255, 255);
			putText(_Screen_, "1Player", Point(410, 340), FONT_HERSHEY_PLAIN, 3, BLACK, 3, 8);
		}
		else{
			_Screen_(rec_bar_player) = Vec3b(255, 255, 255);
			putText(_Screen_, "2Player", Point(410, 340), FONT_HERSHEY_PLAIN, 3, BLACK, 3, 8);
		}

		imshow("Snake Game Plus Plus", _Screen_);
		waitKey(1);
	}
}

void Init_Vmode(int Vmode, int &delay, int &mode, bool &wall){
	if (Vmode == 1)
	{
		delay = 56;
		mode = 4;
		wall = false;
	}
	else if (Vmode == 2){
		delay = 56;
		mode = 3;
		wall = true;
	}
	else{
		wall = true;
		delay = 26;
		mode = 2;
	}
}

void showHighScore(SaveScore onePlayer[], SaveScore twoPlayer[]){
	Mat3b img;
	img = Mat3b(500, 1000, CV_32FC3);
	img = Mat::zeros(img.rows, img.cols, CV_32FC3);
	img = Mat3b(500, 1000, CV_32FC3);
	int *userdata = (int*)malloc(4 * sizeof(int));
	setMouseCallback("Snake Game Plus Plus", __CallBackFunc_Button, userdata);
	Rect but_back;
	but_back = Rect(435, 425, 100, 50);
	img(but_back) = Vec3b(255, 255, 255);
	putText(img(but_back), "Back", Point(but_back.width*0.32, but_back.height*0.6), FONT_HERSHEY_PLAIN, 1, BLACK);
	while (true){
		setMouseCallback("Snake Game Plus Plus", __CallBackFunc_Button, userdata);
		if (Event_HighScore(userdata + 2, img, but_back, *(userdata), *(userdata + 1)) == -1){
			break;
		}
		putText(img, "Snake Plus", Point(50, 150), FONT_HERSHEY_PLAIN, 10, RED, 5);
		putVer(img);
		putText(img, "HIGH SCORE", Point(440, 200), FONT_ITALIC, 0.5, CYAN);
		putText(img, "One Player", Point(150, 250), FONT_ITALIC, 0.5, YELLOW);
		for (int i = 0; i < 3; i++){
			putText(img, onePlayer[i].name, Point(150, 300 + 50 * i), FONT_ITALIC, 0.5, WHITE);
			char score[4]; itoa(onePlayer[i].score, score, 10);
			putText(img, score, Point(270, 300 + 50 * i), FONT_ITALIC, 0.5, WHITE);
		}
		putText(img, "Two Players", Point(750, 250), FONT_ITALIC, 0.5, YELLOW);
		for (int i = 0; i < 3; i++){
			putText(img, twoPlayer[i].name, Point(750, 300 + 50 * i), FONT_ITALIC, 0.5, WHITE);
			char score[4]; itoa(twoPlayer[i].score, score, 10);
			putText(img, score, Point(670, 300 + 50 * i), FONT_ITALIC, 0.5, WHITE);
		}

		putText(img, "MODE", Point(462, 250), FONT_ITALIC, 0.5, WHITE);
		putText(img, "NORMAL", Point(453, 300), FONT_ITALIC, 0.5, WHITE);
		putText(img, "HARD", Point(462, 350), FONT_ITALIC, 0.5, WHITE);
		putText(img, "GOD", Point(464, 400), FONT_ITALIC, 0.5, WHITE);
		imshow("Snake Game Plus Plus", img);
		waitKey(1);
	}
}

void showHelp(Mat &img, bool flag){
	// Create area to show help
	int lineType = 8;
	Point rook_points[1][4];
	rook_points[0][0] = Point(50, 50);
	rook_points[0][1] = Point(950, 50);
	rook_points[0][2] = Point(950, 450);
	rook_points[0][3] = Point(50, 450);
	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 4 };
	fillPoly(img, ppt, npt, 1, BLACK, lineType);
	//
	// Show help
	putText(img, "LUAT CHOI", Point(120, 120), FONT_ITALIC, 0.5, CYAN);

	rook_points[0][0] = Point(110, 130);
	rook_points[0][1] = Point(450, 130);
	rook_points[0][2] = Point(450, 450);
	rook_points[0][3] = Point(110, 450);
	
	// Part Two
	if (flag == true){
		fillPoly(img, ppt, npt, 1, BLACK, lineType);
		putText(img, "Tinh thang thua:", Point(120, 160), FONT_ITALIC, 0.5, LIME);
		putText(img, "- Neu ai dung trung doi phuong", Point(120, 180), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  se tinh theo diem so:", Point(120, 200), FONT_ITALIC, 0.5, WHITE);
		putText(img, "- Ai nhieu diem hon se thang.", Point(120, 220), FONT_ITALIC, 0.5, WHITE);
		putText(img, "Press B to Back...", Point(120, 400), FONT_ITALIC, 0.5, CYAN);
	}
	else{
		// Part One
		fillPoly(img, ppt, npt, 1, BLACK, lineType);
		putText(img, "Ta se co 3 muc do choi:", Point(120, 140), FONT_ITALIC, 0.5, WHITE);
		putText(img, "- Normal:", Point(120, 160), FONT_ITALIC, 0.5, LIME);
		putText(img, "  1. Toc do cham.", Point(120, 180), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  2. Toc do tang sau 4 lan an.", Point(120, 200), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  3. Dung tuong khong thua.", Point(120, 220), FONT_ITALIC, 0.5, WHITE);
		putText(img, "- Hard:", Point(120, 240), FONT_ITALIC, 0.5, LIME);
		putText(img, "  1. Toc do nhanh.", Point(120, 260), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  2. Toc do tang sau 3 lan an.", Point(120, 280), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  3. Dung vao tuong se thua.", Point(120, 300), FONT_ITALIC, 0.5, WHITE);
		putText(img, "- God:", Point(120, 320), FONT_ITALIC, 0.5, LIME);
		putText(img, "  1. Toc do nhanh nhat.", Point(120, 340), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  2. Toc do tang sau 2 lan an.", Point(120, 360), FONT_ITALIC, 0.5, WHITE);
		putText(img, "  3. Dung vao tuong se thua.", Point(120, 380), FONT_ITALIC, 0.5, WHITE);
		putText(img, "Press N to Next...", Point(120, 400), FONT_ITALIC, 0.5, CYAN);
		//
	}
	//
	// Line
	line(img, Point(460, 100), Point(460, 400), WHITE);
	//
	putText(img, "DIEU KHIEN RAN", Point(520, 120), FONT_ITALIC, 0.5, CYAN);
	putText(img, "- Che do mot nguoi choi:", Point(520, 140), FONT_ITALIC, 0.5, RED);
	putText(img, "  Ta dung cac phim mui ten tren", Point(520, 160), FONT_ITALIC, 0.5, WHITE);
	putText(img, "  ban phim de di chuyen.", Point(520, 180), FONT_ITALIC, 0.5, WHITE);
	putText(img, "- Che do hai nguoi choi:", Point(520, 200), FONT_ITALIC, 0.5, RED);
	putText(img, "  Ta dung them cac phim A, S, D, W tren", Point(520, 220), FONT_ITALIC, 0.5, WHITE);
	putText(img, "  ban phim de di chuyen ran thu hai.", Point(520, 240), FONT_ITALIC, 0.5, WHITE);

	putText(img, "CAC PHIM CHUC NANG", Point(520, 260), FONT_ITALIC, 0.5, CYAN);
	putText(img, "(R): Restart Game.", Point(520, 280), FONT_ITALIC, 0.5, WHITE);
	putText(img, "(Q): Quit Game.", Point(520, 300), FONT_ITALIC, 0.5, WHITE);
	putText(img, "(P): Pause Game.", Point(520, 320), FONT_ITALIC, 0.5, WHITE);
	putText(img, "(M): Return to Menu.", Point(520, 340), FONT_ITALIC, 0.5, WHITE);
	putText(img, "(F1): Instruction.", Point(520, 360), FONT_ITALIC, 0.5, WHITE);

	putText(img, "ESC to back...", Point(520, 390), FONT_ITALIC, 0.5, CYAN);
	putText(img, "About. (Press A)", Point(700, 390), FONT_ITALIC, 0.5, LIME);
	//
}
void showAll(Mat3b _Screen_, listNode Snake_1, listNode Snake_2, int Score1, int Score2, int Pmode, int mode){
	int width = 950, hight = 450;
	Scalar color[5] = { YELLOW, CYAN, PINK, LIME, WHITE };
	BoardLimit(_Screen_, width, hight);
	showSnake(_Screen_, color, Snake_1, 0);
	if (Pmode == 2) showSnake(_Screen_, color + 1, Snake_2, 1);
	putScore(_Screen_, Score1, Score2, Pmode);
	putVer(_Screen_);
	putMode(_Screen_, mode);
}

void showInfo(Mat &img){
	// Create area to show help
	int lineType = 8;
	Point rook_points[1][4];
	rook_points[0][0] = Point(50, 50);
	rook_points[0][1] = Point(950, 50);
	rook_points[0][2] = Point(950, 450);
	rook_points[0][3] = Point(50, 450);
	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 4 };
	fillPoly(img, ppt, npt, 1, BLACK, lineType);
	//
	// Show some information
	putText(img, "THONG TIN DO AN", Point(370, 120), FONT_ITALIC, 1, CYAN);
	line(img, Point(75, 130), Point(925, 130), WHITE);
	putText(img, "Do an duoc thuc hien boi:", Point(150, 160), FONT_ITALIC, 0.5, LIME);
	putText(img, "1. Le Tuan Anh (1512003).", Point(150, 180), FONT_ITALIC, 0.5, WHITE);
	putText(img, "2. Tran Quoc Bao (1512029).", Point(150, 200), FONT_ITALIC, 0.5, WHITE);
	putText(img, "Ca 2 hien dang la sinh vien Khoa CNTT, DH KHTN - Tp.HCM.", Point(150, 220), FONT_ITALIC, 0.5, WHITE);
	putText(img, "Do an duoc hoan thanh vao 23.05.2016", Point(150, 240), FONT_ITALIC, 0.5, LIME);
	putText(img, "Lien he: ", Point(150, 260), FONT_ITALIC, 0.5, RED);
	putText(img, "Email >> tranquocbao3897@gmail.com", Point(150, 280), FONT_ITALIC, 0.5, WHITE);
	putText(img, "Website >> 1512029tqb.hol.es", Point(180, 300), FONT_ITALIC, 0.5, WHITE);
	putText(img, "Email >> letuananh035@gmail.com", Point(150, 320), FONT_ITALIC, 0.5, WHITE);
	putText(img, "BACK. (Press B)", Point(700, 390), FONT_ITALIC, 0.5, LIME);
	line(img, Point(75, 410), Point(925, 410), WHITE);
	//
}