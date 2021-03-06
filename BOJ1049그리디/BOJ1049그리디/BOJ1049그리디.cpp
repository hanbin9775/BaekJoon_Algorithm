// BOJ1049그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;

vector <int> marr1;
vector <int> marr2;

int minm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		marr1.push_back(a);
		marr2.push_back(b);
	}

	sort(marr1.begin(), marr1.end());
	sort(marr2.begin(), marr2.end());

	minm = 1000000;

	int min1, min2, min3;

	min1 = ((n - 1) / 6 + 1)*marr1[0];
	min2 = n * marr2[0];
	min3 = n / 6 * marr1[0] + (n % 6) * marr2[0];

	if (minm > min1) {
		minm = min1;
	}
	if (minm > min2) {
		minm = min2;
	}
	if (minm > min3) {
		minm = min3;
	}

	cout << minm;

    return 0;
}

