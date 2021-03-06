// BOJ2212.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001][4];

int arr[1001][4];

int rgb(int num,int idx) {

	if (dp[num][idx] != 0 ) {
		return dp[num][idx];
	}

	if (idx == 1)
		return dp[num][1] = min(rgb(num - 1, 2), rgb(num - 1, 3)) + arr[num][1];
	if (idx == 2)
		return dp[num][2] = min(rgb(num - 1, 1), rgb(num - 1, 3)) + arr[num][2];
	if (idx == 3)
		return dp[num][3] = min(rgb(num - 1, 1), rgb(num - 1, 2)) + arr[num][3];
	

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];


	cout << min(rgb(n,1),min(rgb(n,2),rgb(n,3)));


    return 0;
} 

