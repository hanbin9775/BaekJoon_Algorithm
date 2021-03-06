// 백준5639이진검색트리.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Tree {
	Tree* left;
	Tree* right;
	int num;
public:
	Tree(int _num) {
		left = NULL;
		right = NULL;
		num = _num;
	}
	int Getnum() {
		return num;
	}
	Tree* Getleft() {
		return left;
	}
	Tree* Getright() {
		return right;
	}
	void Setleft(Tree* _left) {
		left = _left;
	}
	void Setright(Tree* _right) {
		right = _right;
	}
	void InsertNode(Tree* node) {
		if (node->Getnum() < this->Getnum()) {
			if (this->Getleft()==NULL) {
				Setleft(node);
			}
			else {
				Getleft()->InsertNode(node);
			}
		}
		if (node->Getnum() > Getnum()) {
			if (Getright()==NULL) {
				Setright(node);
			}
			else {
				Getright()->InsertNode(node);
			}
		}
	}
	void Traverse() {
		cout << num << "\n";
		if (Getleft()!=NULL) {
			Getleft()->Traverse();
		}
		if (Getright()!=NULL) {
			Getright()->Traverse();
		}
	}
};

int main()
{
	int num;

	scanf_s("%d", &num);

	Tree Root(num);

	while (scanf_s("%d", &num)){
		if (num == -1) {
			break;
		}
		Tree temp(num);
		Root.InsertNode(&temp);
	}

	Root.Traverse();

    return 0;
}

