// BOJ9461파도반.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

long long dp[101];
vector<long long> v;

long long padovan(int num) {
	if (dp[num] != 0) {
		return dp[num];
	}

	return dp[num] = padovan(num - 1) + padovan(num - 5);
}

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
    
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(padovan(num));
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}

