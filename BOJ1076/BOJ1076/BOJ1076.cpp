// BOJ1076.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string arr[3];

int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	long result=0;

	if (arr[0] == "black") {
		result += 10 * 0;
	}
	else if (arr[0] == "brown") {
		result += 10 * 1;
	}
	else if (arr[0] == "red") {
		result += 10 * 2;
	}
	else if (arr[0] == "orange") {
		result += 10 * 3;
	}
	else if (arr[0] == "yellow") {
		result += 10 * 4;
	}
	else if (arr[0] == "green") {
		result += 10 * 5;
	}
	else if (arr[0] == "blue") {
		result += 10 * 6;
	}
	else if (arr[0] == "violet") {
		result += 10 * 7;
	}
	else if (arr[0] == "grey") {
		result += 10 * 8;
	}
	else if (arr[0] == "white") {
		result += 10 * 9;
	}

	if (arr[1] == "black") {
		result +=  0;
	}
	else if (arr[1] == "brown") {
		result += 1;
	}
	else if (arr[1] == "red") {
		result += 2;
	}
	else if (arr[1] == "orange") {
		result +=  3;
	}
	else if (arr[1] == "yellow") {
		result +=  4;
	}
	else if (arr[1] == "green") {
		result += 5;
	}
	else if (arr[1] == "blue") {
		result +=  6;
	}
	else if (arr[1] == "violet") {
		result += 7;
	}
	else if (arr[1] == "grey") {
		result +=  8;
	}
	else if (arr[1] == "white") {
		result +=  9;
	}

	if (arr[2] == "black") {
		result *= 1;
	}
	else if (arr[2] == "brown") {
		result *= 10;
	}
	else if (arr[2] == "red") {
		result *= 100;
	}
	else if (arr[2] == "orange") {
		result *= 1000;
	}
	else if (arr[2] == "yellow") {
		result *= 10000;
	}
	else if (arr[2] == "green") {
		result *= 100000;
	}
	else if (arr[2] == "blue") {
		result *= 1000000;
	}
	else if (arr[2] == "violet") {
		result *= 10000000;
	}
	else if (arr[2] == "grey") {
		result *= 100000000;
	}
	else if (arr[2] == "white") {
		result *= 1000000000;
	}

	cout << result;

    return 0;
}

