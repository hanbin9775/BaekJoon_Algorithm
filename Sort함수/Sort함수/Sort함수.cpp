// Sort함수.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<string, pair<string, int>>> v;
	v.push_back(pair<string, pair<string, int>>("E",pair<string,int>("a", 5)));
	v.push_back(pair<string, pair<string, int>>("D", pair<string, int>("b", 4)));
	v.push_back(pair<string, pair<string, int>>("C", pair<string, int>("c", 3)));
	v.push_back(pair<string, pair<string, int>>("B", pair<string, int>("d", 2)));
	v.push_back(pair<string, pair<string, int>>("A", pair<string, int>("e", 1)));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	cout << "\n";
	for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].second << ' ';
	}
	return 0;
}

