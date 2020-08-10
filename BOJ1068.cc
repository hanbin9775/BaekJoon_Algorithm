#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> v;
    vector<int> root;
    v.resize(n);
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        if(input!=-1) v[input].push_back(i);
        else root.push_back(i);
    }
    int remove;
    cin >> remove;
    bool check = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j]==remove){
                v[i].erase(v[i].begin()+j);
                check = true;
                break;
            }
        }
        if(check) break;
    }
    
    //bfs
    int leaf_cnt=0;
    queue<int> q;
    
    for(int i=0; i<root.size(); i++){
        if(remove!=root[i]) {
            q.push(root[i]);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(v[cur].size()==0){
            leaf_cnt++;
            continue;
        }
        
        for(int i=0; i<v[cur].size(); i++){
                q.push(v[cur][i]);
        }
    }
    cout << leaf_cnt;
    return 0;
}

