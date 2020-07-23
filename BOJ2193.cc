#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long dp[91];

long long getDP(int n){
    if(dp[n]!=0) return dp[n];
    
    return dp[n] = getDP(n-1)+ getDP(n-2);
}

int main(){
    int N;
    cin >> N;
    dp[1]=1;
    dp[2]=1;
    cout << getDP(N);
    
    return 0;
}
