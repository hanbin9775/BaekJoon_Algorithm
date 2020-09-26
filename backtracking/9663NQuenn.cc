#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int N;

int arr[15][15];

int completedNqueenCounter;

void backTrackingNQueen(vector<int> usedColRecoder, int currentIndex){
    
    if(N==currentIndex) {
        completedNqueenCounter += 1;
        return;
    }
    
    for(int i=0; i<N; i++){
        bool isPossible = true;
        
        for(int j=0; j<currentIndex; j++){
            if(usedColRecoder[j]==i || abs(j-currentIndex) == abs(i-usedColRecoder[j])){
                isPossible = false;
            }
        }
        
        if(isPossible){
            usedColRecoder[currentIndex] =i;
            backTrackingNQueen(usedColRecoder, currentIndex+1);
        }
    }
               
}

               
int main(){
                
    cin >> N;
        
    vector<int> usedColRecoder;
    usedColRecoder.resize(N);
    
    backTrackingNQueen(usedColRecoder, 0);
    
    cout << completedNqueenCounter;
    

    return 0;
    
}



