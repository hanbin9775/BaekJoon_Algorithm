// BOJ1937.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
/*
int min = a[x][y];

if (x != 1000) {
if (y > 0) {
if (a[x][y-1] > min) {
if (arr[x][y - 1] > 1 && arr[x][y]) {;
//searchmin(1000, 0, temp, initx, inity);
arr[x][y] += arr[x][y-1];
}
else
searchmin(x, y - 1, ++temp, initx, inity);
}
}

if (y < n-1) {
if (a[x][y+1] > min) {
int temp = cnt;
if (arr[x][y + 1] > 1) {
temp += arr[x][y + 1];
searchmin(1000, 0, temp, initx, inity);
}
else
searchmin(x, y + 1, ++temp, initx, inity);

}
}

if (x > 0) {
if (a[x-1][y] > min) {
int temp = cnt;
if (arr[x-1][y] > 1) {
temp += arr[x-1][y];
searchmin(1000, 0, temp, initx, inity);
}
else
searchmin(x-1, y, ++temp, initx, inity);

}
}

if (x < n-1) {
if (a[x+1][y] > min) {
int temp = cnt;
if (arr[x+1][y] > 1) {
temp += arr[x+1][y];
searchmin(1000, 0, temp, initx, inity);
}
else
searchmin(x+1, y, ++temp, initx, inity);

}
}
}

if (cnt > arr[initx][inity]) {
arr[initx][inity] = cnt;
return;
}
else {
return;
}
//////////////////////////////////////////////

if (y > 0) {
if (a[x][y - 1] < a[x][y]) {
searchmax(x, y - 1, cnt + 1);
}
}
if (y < n-1) {
if (a[x][y + 1] < a[x][y]) {
searchmax(x, y + 1, cnt + 1);
}
}
if (x > 0) {
if (a[x-1][y] < a[x][y]) {
searchmax(x-1, y, cnt + 1);
}
}
if (x < n-1) {
if (a[x+1][y] < a[x][y]) {
searchmax(x+1, y, cnt + 1);
}
}

if (cnt > arr[x][y])
arr[x][y] = cnt;
return;

*/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int a[500][500];
int arr[500][500];
int n;
int maxn;



int searchmax(int x,int y) {

	if (arr[x][y] != 0) {
		return arr[x][y];
	}

	int maxtemp=1;

	if (y > 0) {
		if (a[x][y] < a[x][y - 1]) {
			if (arr[x][y - 1] != 0) {
				if (arr[x][y] < 1 + arr[x][y - 1] && maxtemp< 1 + arr[x][y - 1])
					maxtemp = 1 + arr[x][y - 1];
			}
			else if (1 + searchmax(x, y - 1)>maxtemp) {
				maxtemp = 1 + searchmax(x, y - 1);
			}
		}
	}

	if (y < n-1) {
		if (a[x][y] < a[x][y +1]) {
			if (arr[x][y + 1] != 0) {
				if (arr[x][y] < 1 + arr[x][y + 1] && maxtemp< 1+arr[x][y+1])
					maxtemp = 1 + arr[x][y + 1];
			}
			else if (1 + searchmax(x, y+1)>maxtemp) {
				maxtemp = 1 + searchmax(x, y+1);
			}
		}
	}

	if (x > 0) {
		if (a[x][y] < a[x-1][y]) {
			if (arr[x-1][y] != 0) {
				if (arr[x - 1][y] < 1 + arr[x - 1][y] && maxtemp < 1 + arr[x - 1][y])
					maxtemp = 1 + arr[x - 1][y];
			}
			else if (1 + searchmax(x - 1, y )>maxtemp) {
				maxtemp = 1 + searchmax(x - 1, y );
			}
		}
	}

	if (x < n-1) {
		if (a[x][y] < a[x+1][y]) {
			if (arr[x + 1][y] != 0) {
				if (arr[x + 1][y] < 1 + arr[x + 1][y] && maxtemp < 1 + arr[x + 1][y])
					maxtemp = 1+ arr[x + 1][y];
			}
			else if(1+searchmax(x+1,y)>maxtemp) {
				maxtemp = 1 + searchmax(x + 1, y);
			}
		}
	}

	arr[x][y] = maxtemp;
	return maxtemp;
}

void longest() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			 searchmax(i,j);
		}
	}
}

void findmax() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maxn < arr[i][j]) {
				maxn = arr[i][j];
			}
		}
	}
	cout << maxn;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];	
		}
	}

	longest();
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
	*/
	findmax();

    return 0;
}

