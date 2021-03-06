// BOJ2891.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int n, m, r;

vector <pair<bool, bool>> v;
vector <pair<bool, bool>> v2;

int main()
{
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(false, false));
		v2.push_back(make_pair(false, false));
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		v[temp-1].first = true;
		v2[temp - 1].first = true;
	}

	for (int i = 0; i < r; i++) {
		int temp;
		cin >> temp;
		v[temp-1].second = true;
		v2[temp - 1].second = true;
	}
	
	int cant = 0;
	int cant2 = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].first == true) {
			if (v[i].second == true) {
				v[i].first = false;
				v[i].second = false;
				v2[i].first = false;
				v2[i].second = false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		
		if (v[i].first == true) {

			if (i == 0) {
				if (v[i+1].second != true) {
					cant += 1;
				}
				else {
					v[i + 1].second = false;
					v[i].first = false;
				}
			}
			else if (i == n - 1) {
				if (v[i-1].second != true) {
					cant += 1;
				}
				else {
					v[i - 1].second = false;
					v[i].first = false;
				}
			}
			else {
				if (v[i - 1].second != true&& v[i + 1].second != true) {
					cant += 1;
				}
				else {
					if (v[i - 1].second == true) {
						v[i - 1].second = false;
						v[i - 1].first = false;
					}
					if (v[i + 1].second == true) {
						v[i + 1].second = false;
						v[i + 1].first = false;
					}
				}
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {

		if (v2[i].first == true) {

			if (i == 0) {
				if (v2[i + 1].second != true) {
					cant2 += 1;
				}
				else {
					v2[i + 1].second = false;
					v2[i].first = false;
				}
			}
			else if (i == n - 1) {
				if (v2[i - 1].second != true) {
					cant2 += 1;
				}
				else {
					v2[i - 1].second = false;
					v2[i].first = false;
				}
			}
			else {
				if (v2[i - 1].second != true && v2[i + 1].second != true) {
					cant2 += 1;
				}
				else {
					if (v2[i - 1].second == true) {
						v2[i - 1].second = false;
						v2[i - 1].first = false;
					}
					if (v2[i + 1].second == true) {
						v2[i + 1].second = false;
						v2[i + 1].first = false;
					}
				}
			}
		}
	}

	
	if(cant<=cant2)
		cout << cant;
	else {
		cout << cant2;
	}
    return 0;
}

