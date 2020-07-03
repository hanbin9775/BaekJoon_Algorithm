#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string str;
    vector<char> comp;
    cin >> str;
    int len = str.length();
    char prev= str[0];
    comp.push_back(prev);
    char cur;
    //compress
    for(int i=1; i<len; i++){
        cur = str[i];
        if(cur != prev) {
            comp.push_back(cur);
            prev = cur;
        }
    }
    int one_cnt = 0;
    int zero_cnt = 0;
    for(int i=0; i<comp.size(); i++){
        if(comp[i]=='1') one_cnt++;
        if(comp[i]=='0') zero_cnt++;
    }
    cout << min(one_cnt, zero_cnt);
    return 0;
}