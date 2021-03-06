// BOJ5545.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int doe_price;
int top_price;
int doe_cal;
vector <int> v_top_cal;
vector <int> v;

bool desc(int a, int b) {
	return a > b;
}

int main()
{
	cin >> n;
	cin >> doe_price >> top_price;
	cin >> doe_cal;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v_top_cal.push_back(temp);
	}

	sort(v_top_cal.begin(), v_top_cal.end(),desc);

	v.push_back(doe_cal / doe_price);
	for (int i = 0; i < n; i++) {
		//칼로리 높은 순으로 더해주기 위한 인덱스 카운터
		int temp = i;

		//도우 칼로리는 디폴트
		int total_cal=doe_cal;

		//토핑의 가장 높은 칼로리 순으로 더해준다. 어쩌피 토핑 가격은 모두 같음
		while (temp >= 0) {
			total_cal += v_top_cal[temp];
			temp--;
		}

		// 1원당 칼로리 계산해서 v에 푸쉬
		v.push_back(total_cal / ((i + 1)*top_price + doe_price));
	}

	sort(v.begin(), v.end(), desc);

	cout << v[0];

    return 0;
}

