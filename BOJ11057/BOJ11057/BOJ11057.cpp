// BOJ11057.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int dp[1001][10];

int n;




int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		int tempsum = 0;
		for (int j = 0; j < 10; j++) {
			tempsum += dp[i - 1][j];
			tempsum %= 10007;
			dp[i][j] = tempsum;
		}
	}

	cout << dp[n][9];

    return 0;
}

