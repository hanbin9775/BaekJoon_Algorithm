// BOJ2178.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool maze[100][100];
bool write[100][100];
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };


int bfsmaze(int x,int y,int n, int m) {
	int sw;
	
	if (x + i > 0 && x + i < n && y + j >0 && y + j < m && !write[x + i][y + j]) { // 사방을 탐색할 때, 

	}



	return sw;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	


    return 0;
}

