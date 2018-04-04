#include "Control_Snake.h"


void Control(listNode &Snake_)
{

	if (GetAsyncKeyState(VK_UP) && Snake_.head->dir != Down) Snake_.head->dir = Up;
	else
	if (GetAsyncKeyState(VK_DOWN) && Snake_.head->dir != Up) Snake_.head->dir = Down;
	else
	if (GetAsyncKeyState(VK_LEFT) && Snake_.head->dir != Right) Snake_.head->dir = Left;
	else
	if (GetAsyncKeyState(VK_RIGHT) && Snake_.head->dir != Left) Snake_.head->dir = Right;
}
void Control_(listNode &Snake_)
{
	if (GetAsyncKeyState(0x57) && Snake_.head->dir != Down) Snake_.head->dir = Up;
	else
	if (GetAsyncKeyState(0x53) && Snake_.head->dir != Up) Snake_.head->dir = Down;
	else
	if (GetAsyncKeyState(0x41) && Snake_.head->dir != Right) Snake_.head->dir = Left;
	else
	if (GetAsyncKeyState(0x44) && Snake_.head->dir != Left) Snake_.head->dir = Right;
}

void randBait(Point &xy){
	int x = 1, y = 1;
	while (x % 2 == 1){
		x = 11 + rand() % (189 - 11 + 1);
	}
	while (y % 2 == 1){
		y = 11 + rand() % (89 - 11 + 1);
	}
	xy = Point(x * 5, y * 5);
}

void moveSnake(listNode &Snake_, bool Wall){
	for (Node_ * p = Snake_.head; p; p = p->pNext)
	{
		if (p->dir == Up)
		{
			if (Wall){
				p->y -= STEP;
			}
			else{
				if (p->y - STEP >= 50 + 10)
				{
					p->y -= STEP;
				}
				else
				{
					p->y = 450 - 10;
				}
			}
		}
		if (p->dir == Down)
		{
			if (Wall){
				p->y += STEP;
			}
			else{
				if (p->y + STEP <= 450 - 10)
				{
					p->y += STEP;
				}
				else
				{
					p->y = 50 + 10;
				}
			}
		}
		if (p->dir == Left)
		{
			if (Wall){
				p->x -= STEP;
			}
			else{
				if (p->x - STEP >= 50 + 10)
				{
					p->x -= STEP;
				}
				else
				{
					p->x = 950 - 10;
				}
			}
		}
		if (p->dir == Right)
		{
			if (Wall){
				p->x += STEP;
			}
			else{
				if (p->x + STEP <= 950 - 10)
				{
					p->x += STEP;
				}
				else
				{
					p->x = 50 + 10;
				}
			}
		}
	}
}

void customDelay(int &Score, int &Delay, bool &flag, int &mode){
	if (Delay > 5){
		if (Score%mode == 0){
			if (flag == false) Delay -= 5;
			flag = true;
		}
		else flag = false;
	}
}
void ResetSnake(listNode &Snake_, listNode &Snake__, int &Score_, int &Score__){
	Score_ = 0;
	Score__ = 0;
	destroyList(Snake_);
	addLast(Snake_, 100, 200, Right);
	addLast(Snake_, 90, 200, Right);
	addLast(Snake_, 80, 200, Right);
	destroyList(Snake__);
	addLast(Snake__, 900 - 100, 200, Left);
	addLast(Snake__, 900 - 90, 200, Left);
	addLast(Snake__, 900 - 80, 200, Left);
}
void StateSnake(listNode Snake_1, listNode Snake_2, bool &P1Lose, bool &P2Lose, bool wall, int Pmode){
	for (Node_ * p = Snake_1.tail; p != Snake_1.head; p = p->pPrev)
	{
		Node_ * tmp = p->pPrev;
		p->dir = tmp->dir;
		if (Snake_2.head->x == p->x && Snake_2.head->y == p->y && Pmode == 2)
		{
			P2Lose = true;
		}
		if ((Snake_1.head->x == p->x && Snake_1.head->y == p->y) || (wall && (Snake_1.head->x < 60 || Snake_1.head->x > 940 || Snake_1.head->y < 60 || Snake_1.head->y > 440)))
		{
			P1Lose = true;
		}
	}
}