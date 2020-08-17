#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main () {

    int n, k;
    string num;
    
    cin >> n >> k >> num;
    
    deque<int> dq;
    
    for(int i=0; i<n; i++){
        int cur = num[i]-'0';
        while(k>0 && !dq.empty() && dq.back() < cur){
            dq.pop_back();
            k--;
        }
        dq.push_back(cur);
    }
    
    for(int i=0; i<dq.size()-k; i++){
        cout << dq[i];
    }
    
    return 0;
}



