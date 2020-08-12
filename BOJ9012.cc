#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main () {

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        
        stack<char> stk;
        bool is_VPS = true;
        
        for(int j=0; j<str.length(); j++){
            char input = str[j];
            if(input=='(') stk.push(input);
            else if(input==')'){
                if(stk.empty()) {
                    is_VPS = false;
                    break;
                }
                else if(stk.top()=='(') stk.pop();
            }
        }
        if(!stk.empty()) is_VPS = false;
        
        if(is_VPS) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}

