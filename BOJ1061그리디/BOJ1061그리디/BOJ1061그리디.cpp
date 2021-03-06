// BOJ1061그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<int> v;
int sum;
int result;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]-'0');
	}

	sort(v.begin(), v.end(),greater<int>());

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	
	if (v[v.size()-1] != 0 || (sum % 3) != 0) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}
	
    return 0;
}

