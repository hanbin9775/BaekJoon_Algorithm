// 백준1018.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int n, m;

string board[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	

	int cntA = 64;
	int cntB = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			//두 가지 체스판의 경우를 고려
			int num = 0;
			int tempA = 0;
			int tempB = 0;;


			while (num<=63) {
				int _x = (num / 8) + i;
				int _y = (num % 8) + j;

				if ((_y) % 2 == 0 && (_x)%2 ==0) {
					if (board[_x][_y] != 'W') {
						tempA += 1;
					}
				}
				else if ((_y % 2)== 1 && (_x) % 2 == 1) {
					if (board[_x][_y] != 'W') {
						tempA += 1;
					}
				}
				else {
					if (board[_x][_y] != 'B') {
						tempA += 1;
					}
				}

				if ((_y) % 2 == 0 && (_x) % 2 == 0) {
					if (board[_x][_y] != 'B') {
						tempB += 1;
					}
				}
				else if ((_y) % 2 == 1 && (_x) % 2 == 1) {
					if (board[_x][_y] != 'B') {
						tempB += 1;
					}
				}
				else {
					if (board[_x][_y] != 'W') {
						tempB += 1;
					}
				}
				num += 1;
			}
			if (cntA > tempA) {
				cntA = tempA;
			}
			if (cntB > tempB) {
				cntB = tempB;
			}

		}
	}

	if (cntA > cntB) {
		cout << cntB;
	}
	else {
		cout << cntA;
	}

    return 0;
}

