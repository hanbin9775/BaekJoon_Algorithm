#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main () {

    string str;
    getline(cin, str);
    
    while(str!="."){
        stack<char> stk;
        bool is_balanced = true;
        unsigned long length = str.length();
        
        for(int i=0; i<length; i++){
            char tok = str[i];
            if(tok=='(' || tok=='[') stk.push(tok);
            else if(tok==')' || tok==']'){
                if(stk.empty()) {
                    is_balanced = false;
                    break;
                }
                char top = stk.top();
                if(tok==')'){
                    if(top=='(') stk.pop();
                    else if(top=='['){
                        is_balanced = false;
                        break;
                    }
                }
                else{
                    if(top=='[') stk.pop();
                    else if(top=='('){
                        is_balanced = false;
                        break;
                    }
                }
            }
        }
        if(!stk.empty()) is_balanced = false;
        if(is_balanced) cout << "yes" << "\n";
        else cout << "no" << "\n";
        
        
        getline(cin, str);
    }
    
    return 0;
}

