// BOJ2108.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector <int> v;
int arr[8001];



double avrg;
int mid;
int most;
int rng;


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int temp;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		arr[temp+4000] += 1;
	}
	int max = 0;
	int maxi = 0;
	
	vector <int> mostv;
	for (int i = 0; i < 8001; i++) {
		if (max < arr[i]) {
			max = arr[i];
			maxi = i;
		}
	}
	
	for (int i = 0; i < 8001; i++) {
		if (arr[i] == max) {
			mostv.push_back(i);
		}
	}

	sort(mostv.begin(), mostv.end());

	if (mostv.size() > 1) {
		most = mostv[1] - 4000;
	}
	else {
		most = maxi - 4000;
	}

	sort(v.begin(), v.end());

	avrg = floor(sum / n +0.5);

	mid = v[(n - 1) / 2];

	rng = v[n - 1] - v[0];

	cout << avrg << "\n" << mid << "\n" << most << "\n" << rng << "\n";

    return 0;
}

