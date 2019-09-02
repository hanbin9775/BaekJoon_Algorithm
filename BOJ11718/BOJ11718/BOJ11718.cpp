// BOJ11718.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += str[i] - '0';
	}
	cout << sum;
    return 0;
}

