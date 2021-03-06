// BOJ1758.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int N;
long arr[100000];

bool compare(const int a,const int b) {
	return a > b;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N, compare);

	long ans = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i]-i >0) {
			ans += arr[i]-i;
		}
	}

	cout << ans;

    return 0;
}

