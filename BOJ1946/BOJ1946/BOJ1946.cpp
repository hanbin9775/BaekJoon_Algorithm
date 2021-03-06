// BOJ1946.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int n;
int ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		
		vector<pair<int, int>> v;

		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		sort(v.begin(), v.end());

		ans = 1;

		int bestscore = v[0].second;

		for (int i = 1; i < n; i++) {
			if (bestscore > v[i].second) {
				bestscore = v[i].second;
				ans += 1;
			}
		}

		
		cout << ans<< "\n";
		
	}

    return 0;
}

