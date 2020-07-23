#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[500][500];

int getDP(int y, int x, const vector<vector<int>>& triangle){
    if(x==0) return dp[y-1][x]+triangle[y][x];
    if(x==y) return dp[y-1][x-1]+triangle[y][x];
    return max(dp[y-1][x-1],dp[y-1][x])+triangle[y][x];
}

int main(){
    int answer =0;
    int N;
    cin >> N;
    vector<vector<int>> triangle;
    vector<int> temp;
    int input;
    for(int i=0; i<N; i++){
        for(int j=0; j<i+1; j++){
            cin >> input;
            temp.push_back(input);
        }
        triangle.push_back(temp);
        temp.clear();
    }
    dp[0][0] = triangle[0][0];
    
    for(int i=1; i<N; i++){
        for(int j=0; j<i+1; j++){
            dp[i][j] = getDP(i,j,triangle);
            if(i==N-1) answer = max(answer, dp[i][j]);
        }
    }
    cout << answer;
    return 0;
}
