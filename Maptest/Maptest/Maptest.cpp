// Maptest.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map <string, int> m;

	m.insert(make_pair("a", 1));

	cout << m.find("a")->first;
	cout << m.find("b")->first;


    return 0;
}

