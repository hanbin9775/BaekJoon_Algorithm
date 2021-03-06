// 에라토스테네스.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool v[200000000];


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;

	v[0] = true;
	v[1] = true;
	for (int i = 2; i < 200000000; i++) {
		if (!v[i]) {
			int temp = i;
			while (temp < 200000000) {
				temp += i;
				v[temp] = true;
			}
		}
	}

	while (n-->0) {
		int number;
		cin >> number;

		if (v[number]) {
			cout << "Not prime" << "\n";
		}
		else {
			cout << "Prime" << "\n";
		}

	}

	return 0;
}

