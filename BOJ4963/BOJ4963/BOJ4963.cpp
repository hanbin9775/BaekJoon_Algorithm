// BOJ4963.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

int w, h;
int arr[50][50];
int visited[50][50];
stack<int> stk;
int islandCnt;

void detectSurroundings(int x, int y) {
	visited[x][y] = true;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + i >= 0 && x + i < h && y + j >= 0 && y + j < w && (visited[x+i][y+j] == false) && arr[x+i][y+j]==1) {	
				detectSurroundings(x + i, y + j);
			}
		}
	}
}


int main()
{
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == false && arr[i][j]==1) {
					detectSurroundings(i, j);
					islandCnt += 1;
				}
			}
		}

		cout << islandCnt << "\n";
		islandCnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				arr[i][j] = 0;
				visited[i][j] = 0;
			}
		}

	}

    return 0;
}

