// BOJ10845Queue.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;

queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;


	string inst;

	for (int i = 0; i < n; i++) {
		cin >> inst;
		int tempnum;
		if (inst == "push") {
			cin >> tempnum;
			q.push(tempnum);
		}
		else if (inst == "pop") {
			if (q.empty() == 1) {
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (inst == "size") {
			cout << q.size() << "\n";
		}
		else if (inst == "empty") {
			cout << q.empty() << "\n";
		}
		else if (inst == "front") {
			if (q.empty()==0) {
				cout << q.front() <<"\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (inst == "back") {
			if (q.empty() == 0) {
				cout << q.back() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}

	}

    return 0;
}

