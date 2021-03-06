// BOJ10826.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int dp[10001];

int n;

int fibo(int num) {
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}

	if (dp[num] != 0) {
		return dp[num];
	}

	return dp[num] = fibo(num - 1) + fibo(num - 2);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	cout << fibo(n) << "\n";

    return 0;
}

