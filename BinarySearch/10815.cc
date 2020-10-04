#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> myCards;
vector<int> yourCards;

bool binartSearch(int card){
    
    int start = 0;
    int end = myCards.size()-1;
   
    
    while(start<=end){
        
        int mid = (start+end)/2;
        
        if(card == myCards[mid]) return true;
        else if(card > myCards[mid]){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main(){

    int n, m;
    cin >> n;
    
    myCards.resize(n);
    for(int i=0; i<n; i++){
        cin >> myCards[i];
    }
    cin >> m;
    vector<int> yourCards;
    yourCards.resize(m);

    for(int j=0; j<m; j++){
        cin >> yourCards[j];
    }
    
    sort(myCards.begin(), myCards.end());
    
    for(int i=0; i<m; i++){
        int card = yourCards[i];
        
        if(binartSearch(card)){
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    
    
    return 0;

}

