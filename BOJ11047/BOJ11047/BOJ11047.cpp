// BOJ11047.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n,k;
int arr[11];

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	while (k > 0) {

		if (k >= arr[n]) {
			cnt += k / arr[n];
			k = k - (k / arr[n])* arr[n];
			
		}
		n -= 1;

	}
	cout << cnt;

    return 0;
}

