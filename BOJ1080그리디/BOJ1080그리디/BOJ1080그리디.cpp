// BOJ1080그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int n, m;
int ans;
int A[50][50];
int B[50][50];

bool CheckifABEqual() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void OperateA(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 1)
				A[i][j] = 0;
			else
				A[i][j] = 1;

		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			A[i][j] = s[j]-'0';
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			B[i][j] = s[j] - '0';
		}
	}

	if (n < 3 || m < 3) {
		if (CheckifABEqual()) {
			cout << 0;
			return 0;
		}
		else {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (A[i][j] != B[i][j]) {
				OperateA(i, j);
				ans += 1;
			}
			if (CheckifABEqual()) {
				cout << ans;
				return 0;
			}
		}
	}
	cout << -1;

    return 0;
}

