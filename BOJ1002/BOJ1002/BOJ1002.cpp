// BOJ1002.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		long x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << "\n";
			continue;
		}

		long d = pow(x1 - x2, 2) + pow(y1 - y2, 2);

		if (pow(r1 + r2,2) < d) {
			cout << 0 << "\n";
			continue;
		}

		if (pow(r1 + r2, 2) == d) {
			cout << 1 << "\n";
			continue;
		}
		
		if (pow(r1 + r2, 2) > d) {
			if (d > pow(r1-r2,2)) {
				cout << 2 << "\n";
				continue;
			}
			if (d  == pow(r2-r1,2)) {
				cout << 1 << "\n";
				continue;
			}
			if (d < pow(r2-r1,2)) {
				cout << 0 << "\n";
				continue;
			}

		}


	}

    return 0;
}

