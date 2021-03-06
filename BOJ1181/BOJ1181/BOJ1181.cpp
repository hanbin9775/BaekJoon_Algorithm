// BOJ1181.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	//길이가 짧으면 우선순위
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		return a < b; // 사전 순
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (i>0&&a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << "\n";
		}
	}

    return 0;
}

