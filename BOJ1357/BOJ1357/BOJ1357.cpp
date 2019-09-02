// BOJ1357.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int x, y;


int Rev(int num) {
	
	int result = 0;
	while (num > 0) {
		result *= 10;
		result += num % 10;
		num /= 10;
	}
	return result;
}	



int main()
{
	cin >> x >> y;

	cout << Rev(Rev(x) + Rev(y));
    return 0;
}

