// BOJ1021Queue.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <deque>
#include <iostream>

using namespace std;

deque<int> dq;

int n,m;

int arr[50];


void MoveLeft() {
	dq.push_back(dq.front());
	dq.pop_front();
}

void MoveRight() {
	dq.push_front(dq.back());
	dq.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	cin >> m;

	int temp;
	int tempindex;

	for (int i = 0; i < m; i++) {
		cin >> temp;

		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == temp) {
				tempindex = j;
			}
		}

		if (tempindex==0) {
			arr[i] = 0;
			dq.pop_front();
		}
		else if (tempindex<dq.size()-tempindex) {
			arr[i] = tempindex;
			for (int i = 0; i < tempindex; i++) {
				MoveLeft();
			}
			dq.pop_front();
		}
		else {
			arr[i] = dq.size() - tempindex;
			for (int i = 0; i < dq.size() -tempindex; i++) {
				MoveRight();
			}
			dq.pop_front();
		}

	}
	int sum = 0;

	for (int i = 0; i < m; i++) {
		sum += arr[i];
	}
	cout << sum;
    return 0;
}

