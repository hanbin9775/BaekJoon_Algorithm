// 에라토스테네스의체.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
//소수를 대량으로 빠르고 정확하게 구하는 방법

#include "stdafx.h"
#include <stdio.h>

int num = 100000;
int a[100001];

void primeNumberSieve() {
	for (int i = 2; i <= num; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= num; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= num; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i <= num; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
}

int main()
{
	primeNumberSieve();
    return 0;
}

