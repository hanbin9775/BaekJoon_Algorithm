// DFS.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int num = 7;
int c[7];
vector<int> a[8];

void dfs(int x) {
	if (c[x]) return;
	c[x] = true; // 처음 방문하는 거면 true
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

int main()
{
	//1과 2를 연결
	a[1].push_back(2);
	a[2].push_back(1);

	//1과 3을 연결
	a[1].push_back(3);
	a[3].push_back(1);

	//2과 3을 연결
	a[2].push_back(3);
	a[3].push_back(2);

	//2과 4을 연결
	a[2].push_back(4);
	a[4].push_back(2);

	//2과 5을 연결
	a[2].push_back(5);
	a[5].push_back(2);

	//3과 6을 연결
	a[3].push_back(6);
	a[6].push_back(3);

	//3과 7을 연결
	a[3].push_back(7);
	a[7].push_back(3);


	dfs(1);

	return 0;
}

