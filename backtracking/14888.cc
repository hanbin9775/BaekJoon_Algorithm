#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> operands;
int n;

int maxNum = -1000000001;
int minNum =  1000000001;

void backtracking(vector<int> operatorCnt, int idx, int curValue){
    
    if(idx==n){
        maxNum = max(curValue, maxNum);
        minNum = min(curValue, minNum);
        return;
    }
    
    if(operatorCnt[0]>0){
        operatorCnt[0]--;
        backtracking(operatorCnt, idx+1, curValue+operands[idx]);
        operatorCnt[0]++;
    }
    if(operatorCnt[1]>0){
        operatorCnt[1]--;
        backtracking(operatorCnt, idx+1, curValue-operands[idx]);
        operatorCnt[1]++;
    }
    if(operatorCnt[2]>0){
        operatorCnt[2]--;
        backtracking(operatorCnt, idx+1, curValue*operands[idx]);
        operatorCnt[2]++;
    }
    if(operatorCnt[3]>0){
        operatorCnt[3]--;
        backtracking(operatorCnt, idx+1, curValue/operands[idx]);
        operatorCnt[3]++;
    }
    
    
}

int main(){
    
    
    cin >> n;
    
    
    operands.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> operands[i];
    }

    vector<int> operatorCnt;
    operatorCnt.resize(4);
    
    for(int i=0; i<4; i++){
        cin >> operatorCnt[i];
    }

    backtracking(operatorCnt, 1, operands[0]);
    
    cout << maxNum << "\n" << minNum;
    
    return 0;
    
}



