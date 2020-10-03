#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int main(){

    int buttonTime[3] = {300, 60, 10};
    
    int T;
    cin >> T;
    
    int curButtonIndex = 0;
    
    vector<int> pushedNumber;
    
    while(curButtonIndex<3){
        
        int share =  T / buttonTime[curButtonIndex];
        T = T % buttonTime[curButtonIndex];
        
        curButtonIndex++;
        pushedNumber.push_back(share);
    }

    if(T==0){
        for(int i=0; i<3; i++){
            cout << pushedNumber[i] << " ";
        }
    } else {
        cout << -1;
    }
    
    return 0;

}

