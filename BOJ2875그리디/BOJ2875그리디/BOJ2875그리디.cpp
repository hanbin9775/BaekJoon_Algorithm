// BOJ2875그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> k;

	int cntn = 0;
	int cntm = 0;

	while (true) {
		
		cntn += 2;
		cntm += 1;

		if (cntm > m || cntn > n) {
			cntn -= 2;
			cntm -= 1;
			break;
		}
	}

	int left = n + m - cntn - cntm;

	if (left >= k) {
		cout << cntm;
		return 0;
	}

	left = k - left;

	if (left % 3 > 0) {
		cout << cntm - (left / 3) - 1;
		return 0;
	}
	cout << cntm - (left / 3);

    return 0;
}

