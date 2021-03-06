// BOJ1931그리디정답률29.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <pair<int, int>> v;
int dp[100001];

int temp1, temp2;
int last;

bool compare(pair <int, int> a, pair<int, int> b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first > b.first) {
		return false;
	}
	else {
		if (a.second < b.second) {
			return true;
		}
		else
			return false;
	}
}

int countmax(int index, int count) {
	
	if (index+1 >= n) {
		dp[index] = 1;
		return  count;
	}

	if (v[index].second > last) {
		dp[index] = 1;
		return count;
	}
	
	
	int max = 0;
	int temp;

	for (int i = index + 1; i < n; i++) {
		if(v[index].second<=v[i].first){
			if (dp[i] != 0) {
				if (dp[i]+count > max) {
					max = dp[i]+count;
				}
			}
			else {
				temp = countmax(i, count + 1);
				if (temp > max) {
					max = temp;
				}
			}
		}
	}
	dp[index] = max - count + 1;
	return max;

}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		v.push_back(make_pair(temp1, temp2));
	}

	sort(v.begin(), v.end(), compare);

	last = v[n-1].first;

	int dpmax = 0;

	for (int i = 0; i < n; i++) {
		if (dp[i] != 0) {
			if (dpmax < dp[i]) {
				dpmax = dp[i];
			}
		}
		if ( dpmax < countmax(i, 1)) {
			dpmax = dp[i];
		}
		//cout << dp[i] << " ";
	}
	
	cout << dpmax;

    return 0;
}

