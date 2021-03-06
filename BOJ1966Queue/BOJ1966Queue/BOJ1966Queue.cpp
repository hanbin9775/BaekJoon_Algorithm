// BOJ1966Queue.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pi;

queue <pi> q;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> ans;

int t;

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> t;

	for (int i = 0; i < t; i++) {
		
		while (!q.empty()) {
			q.pop();
		}
		while (!pq.empty()) {
			pq.pop();
		}

		cin >> n >> m;

		int max = 0;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			pq.push(p);
			q.push(make_pair(p,i));
		}
		int pop_cnt = 1;


		while (!q.empty()) {

			if (q.front().first==pq.top()){
				if (q.front().second == m) {
					ans.push_back(pop_cnt);
					break;
				}
				q.pop();
				pq.pop();
				pop_cnt += 1;
			}
			else {
				//맨뒤에 넣어준다
				q.push(make_pair(q.front().first,q.front().second));
				q.pop();
			}
		}

	}

	for (int i = 0; i < t; i++) {
		cout << ans[i] << "\n";
	}

    return 0;
}

