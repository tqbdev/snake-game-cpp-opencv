#include "Snake_Node.h"

Node_* getNode(int &x, int &y, Dir &dir){
	Node_* p = new Node_;
	if (p == NULL){
		exit(EXIT_FAILURE);
	}

	p->x = x;
	p->y = y;
	p->dir = dir;
	p->pNext = NULL;
	p->pPrev = NULL;

	return p;
}

void addLast(listNode &lst, int x, int y, Dir dir){
	Node_ * p = getNode(x, y, dir);
	if (lst.head == NULL){
		lst.head = lst.tail = p;
	}
	else{
		p->pPrev = lst.tail;
		lst.tail->pNext = p;
		lst.tail = p;
	}
}

void destroyList(listNode &lst){
	Node_ * p;
	while (lst.head){
		p = lst.head;
		lst.head = lst.head->pNext;
		delete p;
	}
}
