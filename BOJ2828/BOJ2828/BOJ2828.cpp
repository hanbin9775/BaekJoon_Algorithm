// BOJ2828.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n, m, j;

int arr[21];

int main()
{
	cin >> n >> m >> j;

	for (int i = 1; i <= j; i++) {
		cin >> arr[i];
	}

	int left = 1;
	int right = m;
	int move = 0;

	for (int i = 1; i <= j; i++) {
		if (arr[i] < left) {
			right -= left - arr[i];
			move += left - arr[i];
			left = arr[i];
			
		}
		else if (arr[i] > right) {
			left += arr[i] - right;
			move += arr[i] - right;
			right = arr[i];

		}
	}

	cout << move;

    return 0;
}

