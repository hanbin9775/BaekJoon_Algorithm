// BOJ1436.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;

int arr[10000];

bool Check666(int num) {
	int cnt = 0;
	while (num > 0) {

		if (num % 10 == 6) {
			cnt += 1;
		}
		else {
			cnt = 0;
		}
		if (cnt == 3) {
			return true;
		}

		num = num / 10;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	int cnt = 0;
	int num = 666;
	while (cnt < 10000) {
		if (Check666(num)) {
			arr[cnt] = num;
			cnt += 1;
		}
		num += 1;
		if (n == cnt) {
			cout << arr[cnt-1];
			return 0;
		}
	}

    return 0;
}

