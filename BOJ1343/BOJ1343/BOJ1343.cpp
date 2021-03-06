// BOJ1343.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

string board;
queue <string> ans;

int main()
{
	cin >> board;
	int cnt = 0;

	for (int i = 0; i < board.length(); i++) {
		if (board[i] != '.') {
			cnt += 1;
		}
		if (board[i] == '.' || i==board.length()-1) {
			if (cnt == 0) {
				ans.push(".");
				continue;
			}
			if (cnt % 2 == 0 && cnt >0) {
				if (cnt < 4) {
					ans.push("BB");
				}
				else {
					for (int i = 0; i < cnt / 4; i++) {
						ans.push("AAAA");
					}
					if (cnt % 4) {
						ans.push("BB");
					}
				}
				if (i != board.length() - 1) {
					ans.push(".");
				}
				if (i == board.length() - 1 && board[i]=='.') {
					ans.push(".");
				}
				cnt = 0;
			}
			else {
				cout << -1;
				return 0;
			}
			
		}
	}

	while (!ans.empty()) {
		cout << ans.front();
		ans.pop();
	}

    return 0;
}

