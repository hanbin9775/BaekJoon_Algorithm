// BOJ4344.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int n;

float arv[1001];
int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		float tempsum = 0;
		float average = 0;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			arr[j] = b;
			tempsum += b;
		}
		average = tempsum / a;

		float cntupper = 0;
		for (int k = 0; k < a; k++) {
			if (arr[k] > average) {
				cntupper += 1;
			}
		}
		arv[i] = cntupper / a * 100;
	}

	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < n; i++) {
		cout << arv[i] <<"%"<< "\n";
	}

    return 0;
}

