// BOJ11503.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int maxn;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		int max = 0;

		for (int j = 0; j < i; j++) {
			if (arr[i]>arr[j]&& max<=dp[j]) {
				max = dp[j];
				dp[i] = max + 1;
			}
		}
		
		if (maxn < dp[i]) {
			maxn = dp[i];
		}
	}

	cout << maxn + 1;

    return 0;
}

