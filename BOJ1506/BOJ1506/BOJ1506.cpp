// BOJ1506.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define MAX 1000001

int N;
int cost[101];
int road[101][101];
int rvroad[101][101];
int visited[101];
stack<int> stk;

int cjCounter = MAX;


void DFS(int cur) {	
	visited[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (road[cur][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
	stk.push(cur);
}

void rvDFS(int cur) {
	visited[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (rvroad[cur][i] == 1 && visited[i] == false) {
			rvDFS(i);
		}
	}

	if (cjCounter > cost[cur]) {
		cjCounter = cost[cur];
	}

	stk.pop();
}


int main()
{

	int ans = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	string input;

	for (int i = 1; i <= N; i++) {
		cin >> input;

		for (int j = 1; j <= N; j++) {
			road[i][j] = input[j-1]-'0';
			rvroad[j][i] = road[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		if(visited[i]==false)
			DFS(i);
	}

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	while (!stk.empty()) {
		rvDFS(stk.top());
		ans += cjCounter;
		cjCounter = MAX;
	}

	cout << ans;

    return 0;
}
