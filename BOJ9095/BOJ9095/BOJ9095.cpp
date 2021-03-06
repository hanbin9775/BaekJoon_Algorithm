// BOJ9095.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int T;
vector <int> v;
int d[12];


int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2) + dp(x - 3);
}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", dp(v[i]));
	}

    return 0;
}

