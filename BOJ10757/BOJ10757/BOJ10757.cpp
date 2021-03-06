// BOJ10757.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string A;
string B;


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> A >> B;

	int ia=0;
	int ib=0;
		
	vector <int> ans;
	int carry = 0;
	int temp;
	while(true){
		if (A.size() - 1 >= ia && B.size() - 1 >= ib) {
			temp = (A[A.size() - ia - 1] - '0') + (B[B.size() - ib - 1] - '0') + carry;
			carry = 0;
			if (temp >= 10) {
				temp -= 10;
				carry = 1;
			}
		}
		else if (A.size() > B.size()) {
			temp = carry + A[A.size() - ia - 1] - '0';
			carry = 0;
			if (temp >= 10) {
				temp -= 10;
				carry = 1;
			}
		}
		else if (A.size() < B.size()) {
			temp = carry + B[B.size() - ib - 1] - '0';
			carry = 0;
			if (temp >= 10) {
				temp -= 10;
				carry = 1;
			}
		}

		ans.push_back(temp);
		ia += 1;
		ib += 1;

		if ((A.size() - 1  < ia) && (B.size() - 1 < ib)) {
			if (carry == 1) {
				ans.push_back(1);
			}
			break;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[ans.size() - i - 1];
	}

    return 0;
}

