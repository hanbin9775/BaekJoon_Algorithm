// BOJ1874.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;

int arr[100001];

stack <int> stk;

vector <char> operation;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	int number = 0;
	

	while (true) {

		if (number != n) {
			if (!stk.empty() && arr[cnt] == stk.top()) {
				operation.push_back('-');
				stk.pop();
				cnt += 1;
			}
			else {
				number += 1;
				stk.push(number);
				operation.push_back('+');
			}
		}
		else {
			if (arr[cnt] != stk.top()) {
				cout << "NO";
				return 0;
			}
			else {
				operation.push_back('-');
				stk.pop();
				cnt += 1;
				if (cnt == n) {
					for(int i=0; i<operation.size(); i++){
						cout << operation[i] << "\n";
					}
					return 0;
				}
			}
		}

	}

    return 0;
}

