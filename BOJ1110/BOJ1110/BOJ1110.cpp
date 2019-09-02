// BOJ1110.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;
int cnt;

int main()
{
	cin >> n;

	int temp = n;
	int a, b, c;

	do {
		a = temp / 10;
		b = temp % 10;
		cnt += 1;
		c = (a + b) % 10;
		temp = b * 10 + c;
	} while (temp != n);

	cout << cnt;

    return 0;
}

