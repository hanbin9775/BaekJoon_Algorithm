#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[100000];
int input[100000];

int main () {
   
    int answer = -100000000;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    dp[0] = input[0];
    int sum =dp[0];
    
    for(int i=1; i<n; i++){
        sum += input[i];
        if(input[i]>sum) sum = input[i];
        if(sum >= dp[i-1]) dp[i] = sum;
        else dp[i] = dp[i-1];
    }
    
    cout << dp[n-1];
    return 0;
}
