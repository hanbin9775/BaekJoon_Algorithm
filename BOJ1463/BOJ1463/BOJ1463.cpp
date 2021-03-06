// BOJ1463.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;

int dp[1000001];




int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		int mintemp = 1000000;

		if (i % 3 == 0) {
			mintemp = dp[i / 3];
		}
		if (i % 2 == 0) {
			if(mintemp > dp[i/2])
				mintemp = dp[i / 2];
		}
		if (mintemp > dp[i - 1]) {
			mintemp = dp[i - 1];
		}
		
		dp[i] = mintemp + 1;
	}

	cout << dp[n];

    return 0;
}

