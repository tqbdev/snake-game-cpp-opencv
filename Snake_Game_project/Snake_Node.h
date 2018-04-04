#include <iostream>
#pragma once
enum Dir { Up, Right, Down, Left };

struct Node_ {
	int x, y;
	Dir dir;
	Node_ * pNext;
	Node_ * pPrev;
};

struct listNode{
	Node_ * head = NULL;
	Node_ * tail = NULL;
};

Node_* getNode(int &x, int &y, Dir &dir);
void addLast(listNode &lst, int x, int y, Dir dir);
void destroyList(listNode &lst);
