// 스택.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
    return 0;
}

