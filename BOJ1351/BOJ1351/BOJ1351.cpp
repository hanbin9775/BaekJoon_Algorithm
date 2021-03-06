// BOJ1351.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

long long n, p, q;

map <long long, long long> m;

long long fun(long long num) {
	if (num == 0) {
		return 1;
	}
	if (m.find(num) != m.end()) {
		return m.find(num)->second;
	}
	return m[num] = fun(num / p) + fun(num / q);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> p >> q;

	cout << fun(n);

    return 0;
}

