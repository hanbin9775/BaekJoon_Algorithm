// BOJ10828.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;

stack<int> stk;
string str;
int num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			stk.push(num);
		}
		else if(str == "pop") {
			if (stk.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << stk.top()<<"\n";
				stk.pop();
			}
		}
		else if (str == "size") {
			cout << stk.size() << "\n";
		}
		else if (str == "empty") {
			if (stk.empty() == 1) {
				cout << 1 << "\n";
			}
			else if (stk.empty() == 0) {
				cout << 0 << "\n";
			}
		}
		else if (str == "top") {
			if (stk.empty() == 1) {
				cout << -1 << "\n";
			}
			else if (stk.empty() == 0) {
				cout << stk.top() << "\n";
			}
		}


	}
    return 0;
}

