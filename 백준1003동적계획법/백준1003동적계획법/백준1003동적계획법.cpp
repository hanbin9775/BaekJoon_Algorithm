// 백준1003동적계획법.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int n;

vector <int> v;

int dp[41];

int fibo(int n) {
	
	if (n <= 1) {
		return dp[n];
	}
	else if (dp[n] != 0) {
		return dp[n];
	}
	else
		return dp[n]=fibo(n - 1) + fibo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		fibo(temp);
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 0)
			cout << 1 << " " << 0 << "\n";
		else if (v[i] == 1)
			cout << 0 << " " << 1 << "\n";
		else {
			cout << dp[v[i] - 1] << " " <<dp[v[i]] << "\n";
		}
	}

    return 0;
}

