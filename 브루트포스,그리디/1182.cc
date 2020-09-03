#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int arr[20];
int n,s;

set<vector<int>> ans;

void dfs(int sum, int idx, vector<int> v){
    
    if(sum==s && v.size()>0) {
        ans.insert(v);
    }
    if(idx==n) return;
    
    dfs(sum, idx+1, v);
    v.push_back(arr[idx]);
    dfs(sum+arr[idx], idx+1, v);
}

int main(){
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int> v;
    dfs(0, 0, v);
    
    cout << ans.size();
    
    return 0;
    
}



