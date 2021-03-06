// BOJ1026정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

int a[50];
int b[50];

int bs[50];

bool compare(int x, int y) {
	return x > y;
}

int minS(int p[], int q[]) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += p[i] * q[i];
	}
	return result;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, a + n); // 오름차순
	sort(b, b + n, compare); // 내림차순

	for (int i = 0; i < n; i++) {
		bs[i] = b[i];
	}

	printf("%d", minS(a, bs));

    return 0;
}

