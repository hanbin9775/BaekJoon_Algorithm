// BOJ10814.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
//20분 

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <pair<int, string>> v;


bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return false;
	}
	else if (a.first < b.first)
		return true;

	return false;
}


int main()
{
	std::ios_base::sync_with_stdio(false);

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}


    return 0;
}

