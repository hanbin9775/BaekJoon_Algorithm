// BOJ1783그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

long n, m;


int main()
{
	cin >> n >> m;

	if (n == 1) {
		cout << 1;
		return 0;
	}
	else if (n == 2) {
		if (m < 3) {
			cout << 1;
			return 0;
		}
		else {
			if ((m - 1) / 2 + 1 >= 4) {
				cout << 4;
				return 0;
			}
			else {
				cout << (m - 1) / 2 + 1;
				return 0;
			}
		}
	}
	else {
		if (m <= 4) {
			cout << m;
			return 0;
		}
		else if (4 < m  && m<=6) {
			cout << 4;
			return 0;
		}
		else {
			cout << m - 2;
			return 0;
		}
	}

    return 0;
}

