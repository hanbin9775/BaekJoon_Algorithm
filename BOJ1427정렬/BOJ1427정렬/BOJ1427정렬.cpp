// BOJ1427정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int n;

bool compare(int a, int b) {
	return a > b;
}

void func(int x) {
	while (x > 10) {
		int a = x % 10;
		v.push_back(a);
		x /= 10;
	}
	v.push_back(x);
	sort(v.begin(), v.end(),compare);
}

int main()
{
	scanf_s("%d", &n);
	func(n);

	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}

    return 0;
}

