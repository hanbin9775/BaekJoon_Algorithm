// BOJ14852타일채우기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int d[1000000];

int n;
 
int dp(int x) {

	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (d[x] != 0) return d[x];
	int temp = 2 * dp(x - 1) + 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		temp += (2 * d[x - i])% 1000000007;
	}
	return d[x] = temp%1000000007;
}

int main()
{
	d[0] = 1;
	d[1] = 2;
	d[2] = 7;
	scanf_s("%d", &n);
	printf("%d", dp(n));
    return 0;
}

