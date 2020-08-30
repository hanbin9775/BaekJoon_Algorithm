#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

#define dwarf_num 7
#define total_weight 100
#define total_num 9

int dwarfs[total_num];
vector<int> ans;

void dfs(int idx, int sum, int cnt, vector<int> v){
    
    if(cnt == dwarf_num){
        if(sum==total_weight) ans = v;
        return;
    }
    if(idx == total_num || sum > total_weight || cnt+total_num-idx < dwarf_num){
        return;
    }
    
    dfs(idx+1, sum, cnt, v);
    v.push_back(dwarfs[idx]);
    dfs(idx+1, sum + dwarfs[idx], cnt+1, v);
}

int main(){
    
    for(int i=0; i<total_num; i++){
        cin >> dwarfs[i];
    }
    
    vector<int> v;
    dfs(0, 0, 0, v);
    
    sort(ans.begin(), ans.end());
    for(int i=0; i<dwarf_num; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
    
}



