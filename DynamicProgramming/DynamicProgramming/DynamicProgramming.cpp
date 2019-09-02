// DynamicProgramming.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
//다이내믹 프로그래밍은 다음의 가정하에 사용할 수 있다
//1. 큰 문제를 작은 문제로 나눌 수 있다.
//2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

// 크고 어려운 문제가 있으면 그것을 먼저 잘게 나누어서 해결한 뒤에 처리하여 나중에 전체의
// 답을 구하는 것. Memoization

#include "stdafx.h"
#include <stdio.h>

//미리 계산한 값 저장해 놓는 배열
int d[100];

// O(2^n)의 시간 복잡도에서 O(n)으로 개선
int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main()
{
	printf("%d", dp(30));
    return 0;
}

