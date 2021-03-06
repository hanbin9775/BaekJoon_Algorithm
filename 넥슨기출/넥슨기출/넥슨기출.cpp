// 넥슨기출.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int dp[10000];

int self_sum;

int d(int n) {
	int temp = n;
	int sum = 0;

	sum += temp / 1000;
	temp = temp % 1000;
	sum += temp / 100;
	temp = temp % 100;
	sum += temp / 10;
	temp = temp % 10;
	sum += temp + n;
	
	return sum;
}

int main()
{
	for (int i = 1; i < 10000; i++) {
		dp[d(i)] = 1;
	}
	
	self_sum = 0;
	
	for (int i = 1; i < 5000; i++) {
		if (dp[i] == 0) {
			cout << i << " ";
			self_sum += i;
		}
	}

	cout << self_sum;

    return 0;
}

