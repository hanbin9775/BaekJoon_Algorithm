// BOJ11726DP.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

long d[1001];
int n;

long dpTwobyN(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (d[x] != 0)	return d[x];
	return d[x] = (dpTwobyN(x - 2) + dpTwobyN(x - 1))%10007;
}

int main()
{
	scanf("%d", &n);
	printf("%d", dpTwobyN(n));

    return 0;
}

