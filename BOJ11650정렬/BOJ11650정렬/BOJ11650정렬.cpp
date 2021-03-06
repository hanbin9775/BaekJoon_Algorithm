// BOJ11650정렬.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<pair<int, int>> v;

int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}

int main()
{
	scanf_s("%d", &n);
	int x = 0;
	int y = 0;


	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

    return 0;
}

