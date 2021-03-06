// BOJ2816.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int N;
int c;
string channel[100];

void button(int btn) {
	string temp;
	switch (btn) {
		case 1:
			c += 1;
			cout << 1;
			break;
		case 2:
			c -= 1;
			cout << 2;
			break;
		case 3:
			temp = channel[c];
			channel[c] = channel[c + 1];
			channel[c + 1] = temp;
			c += 1;
			cout << 3;
			break;
		case 4:
			temp = channel[c];
			channel[c] = channel[c - 1];
			channel[c - 1] = temp;
			c -= 1;
			cout << 4;
			break;
		default :
			break;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> channel[i];
	}


	while (channel[0] != "KBS1") {
		
		if (channel[c+1] == "KBS1") {
			if (c == 0)
				button(3);
			else {
				button(1);
				button(4);
			}
		}
		else if (channel[c] == "KBS1") {
			int temp = c;
			for (int i = 0; i < temp; i++) {
				button(4);
			}
		}
		else {
			button(1);
		}
	}

	while (channel[1] != "KBS2") {
		if (channel[c + 1] == "KBS2") {
			if (c == 1)
				button(3);
			else {
				button(1);
				button(4);
			}
		}
		else if (channel[c] == "KBS2") {
			int temp = c-1;
			for (int i = 0; i < temp; i++) {
				button(4);
			}
		}
		else {
			button(1);
		}
	}
    return 0;
}

