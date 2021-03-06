// BOJ1978소수.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;
int temp;
int cnt;

bool IsSosu(int num) {

	if (num == 1) {
		return false;
	}

	for (int i = 2; i < num/2+1; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (IsSosu(temp)) {
			cnt += 1;
		}
	}

	cout << cnt << "\n";

    return 0;
}

