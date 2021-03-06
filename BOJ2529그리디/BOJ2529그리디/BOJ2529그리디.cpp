// BOJ2529그리디.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int n;
char arr[9];
int maxarr[10];
int minarr[10];
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	char temp;
	int index = 0;
	int maxnum = 9;
	int cntsame = 0;

	for (int i = 0; i < n; i++) {
		temp = arr[i];
		if (temp == '>') {
			if (cntsame != 0) {
				for (int i = 0; i <= cntsame; i++) {
					maxarr[index + cntsame - i] = maxnum;
					maxnum -= 1;
				}
				index = index + cntsame + 1;
				cntsame = 0;
				if (i + 1 == n) {
					maxarr[index] = maxnum;
				}
			}
			else {
				maxarr[index] = maxnum;
				index += 1; maxnum -= 1;
				if (i + 1 == n) {
					maxarr[index] = maxnum;
				}
			}
		}
		else if(temp == '<') 
		{
			cntsame += 1;
			if (i + 1 == n) {
				for (int i = 0; i <= cntsame; i++) {
					maxarr[index + cntsame - i] = maxnum;
					maxnum -= 1;
				}
			}
		}
	}

	index = 0;
	int minnum = 0;
	cntsame = 0;

	for (int i = 0; i < n; i++) {
		temp = arr[i];
		if (temp == '<') {
			if (cntsame != 0) {
				for (int i = 0; i <= cntsame; i++) {
					minarr[index + cntsame - i] = minnum;
					minnum += 1;
				}
				index = index + cntsame + 1;
				cntsame = 0;
				if (i + 1 == n) {
					minarr[index] = minnum;
				}
			}
			else {
				minarr[index] = minnum;
				index += 1; minnum += 1;
				if (i + 1 == n) {
					minarr[index] = minnum;
				}
			}
		}
		else if (temp == '>')
		{
			cntsame += 1;
			if (i + 1 == n) {
				for (int i = 0; i <= cntsame; i++) {
					minarr[index + cntsame - i] = minnum;
					minnum += 1;
				}
			}
		}
	}


	for (int i = 0; i <= n; i++) {
		cout << maxarr[i];
	}
	cout << "\n";
	for (int i = 0; i <= n; i++) {
		cout << minarr[i];
	}
	cout << "\n";

    return 0;
}

