// BOJ12790.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;
int arr[1000];

int a, b, c, d;
int _a, _b, _c, _d;



int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		
		cin >> a >> b >> c >> d >> _a >> _b >> _c >> _d;

		if (a + _a <= 1) {
			arr[i] += 1;
		}
		else
		{
			arr[i] += a + _a;
		
		}
		if (b + _b <= 1) {
			arr[i] += 5;
		}
		else
		{
			arr[i] += 5*(b + _b);

		}
		if (c + _c > 0) {
			arr[i] += 2 * (c + _c);
		}
		arr[i] += 2 * (d + _d);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

    return 0;
}

