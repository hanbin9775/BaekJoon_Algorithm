// BOH2133타일채우기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int d[31];
int n;


int dp(int x) {
	
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];
	/*
	int temp = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			temp += 2 * dp(x - i);
		}
	}
	return d[x] = temp;
	*/
	///*
	int temp = 0;
	for (int i = 3; i <= x; i++) {
		if(i%2==0)
			temp += dp(x-i);
	}
	
	return d[x] = 3 * dp(x - 2) + 2*temp;
	//*/
}

int main()
{
	scanf("%d", &n);
	printf("%d", dp(n));
    return 0;
}

