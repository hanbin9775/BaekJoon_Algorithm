// BOJ1834.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

long long n;

int main()
{
	cin >> n;
	
	long long sum=0;
	
	for (long long i = 1; i < n; i++) {
		sum += i * n + i;
	}

	cout << sum;
	
	return 0;
}

