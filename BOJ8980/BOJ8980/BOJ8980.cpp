// BOJ8980.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c, m;

int truckC;

vector <int> v[10000];
vector <int> downInfo[10000];


int truck(int start) {
	int currentN = 1;
	int currentC = 0;
	int currentX = start;
	int sum = 0;


	while (currentN <= n) {

		//box out
		while (!downInfo[currentN].empty()) {
			currentC -= downInfo[currentN].back();
			sum += downInfo[currentN].back();
			downInfo[currentN].pop_back();
		}

		//box in
		while (currentX != m && v[currentX][0] == currentN) {
			int loadamount;
			if (currentC + v[currentX][2] > c) {
				if (c - currentC>0)
					loadamount = c - currentC;
				else {
					loadamount = 0;
				}
				//꽉참
				currentC = c;
			}
			else {
				loadamount = v[currentX][2];
				currentC += v[currentX][2];
			}
			downInfo[v[currentX][1]].push_back(loadamount);
			currentX += 1;
		}
		currentN += 1;
	}
	return sum;
}

int main()
{
	cin >> n >> c >>m;

	int tmp1, tmp2, tmp3;

	for (int i = 0; i < m; i++) {

		cin >> tmp1 >> tmp2 >> tmp3;
		v[i].push_back(tmp1);
		v[i].push_back(tmp2);
		v[i].push_back(tmp3);
		
	}

	sort(v, v + m);
	
	cout << truck(0);

    return 0;
}

