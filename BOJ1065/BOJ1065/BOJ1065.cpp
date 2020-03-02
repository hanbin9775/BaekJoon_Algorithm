// BOJ1065.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int X;
int result;
float a, b, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> X;

	if (X < 100) {
		result = X;
		cout << result;
		return 0;
	}
	else {
		result += 99;
	}

	for (int i = 100; i <= X; i++) {
		
		int temp = i;

		a = temp / 100;
		temp -= a * 100;
		b = temp / 10;
		temp -= b * 10;
		c = temp;

		if ((a + c) / 2 == b) {
			result++;
		}

	}

	cout << result;


    return 0;
}

