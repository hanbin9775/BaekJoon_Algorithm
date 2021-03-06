// BOJ1929.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n, m;

bool dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 2; i <= m; i++) {
		if (!dp[i]) {
			if (i >= n) {
				cout << i << "\n";
			}
			for (int j = i; j <= m; j+=i) {
				dp[j] = true;
			}
		}
	}



    return 0;
}

