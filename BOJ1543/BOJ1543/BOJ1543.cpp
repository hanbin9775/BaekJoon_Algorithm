// BOJ1543.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string doc;
string word;
int ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	getline(cin, doc);
	getline(cin, word);


	while (doc.find(word) != string::npos) {
		
		ans += 1;
		doc = doc.substr(doc.find(word)+word.length());


	}
	cout << ans << "\n";
    return 0;
}

