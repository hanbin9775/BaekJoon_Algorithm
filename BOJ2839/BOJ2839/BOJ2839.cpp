// BOJ2839.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int minn;

int main()
{
	ios_base::sync_with_stdio(false);

	//3가지 경우로 나누어 푼다.

	cin >> n;

	//첫번 째 경우
	if (n % 3 == 0) {
		minn = n / 3;
	}

	//두번 째 경우
	if (n % 5 == 0) {
		minn = n / 5;
		cout << minn << "\n";
		return 0;
	}

	//세번 째 경우
	int leftover = n;
	int cnt5 = 0;
	int cnt3 = 0;
	while (leftover >= 0) {
		leftover -= 3;
		cnt3 += 1;
		if (leftover % 5 == 0) {
			cnt5 = leftover / 5;
			minn = cnt3 + cnt5;
			break;
		}
	}

	if (minn == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << minn << "\n";
	}

    return 0;
}

