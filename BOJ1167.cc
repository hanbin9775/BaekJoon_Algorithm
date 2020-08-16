#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

vector<vector<pair<int,int>>> tree;

int diameter =0;
bool visited[100001];
int n;
int farthest;

void dfs(int start){
    
    stack<pair<int,int>> stk;
    stk.push(make_pair(start,0));
    
    while(!stk.empty()){
        
        int cur = stk.top().first;
        int distance = stk.top().second;
        visited[cur] = true;
        stk.pop();
        
        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i].first;
            int next_distance = tree[cur][i].second;
        
            if(!visited[next]){
                stk.push(make_pair(next,distance+next_distance));
            }
        }
        
        if(diameter < distance){
            diameter = distance;
            farthest = cur;
        }
    }
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
}

int main () {

    cin >> n;
    
    tree.resize(n+1);
    
    for(int i=0; i<n; i++){
        int vertex;
        cin >> vertex;
        
        while(true){
            int next, dist;
            cin >> next;
            if(next==-1) break;
            cin >> dist;
            
            tree[vertex].push_back(make_pair(next, dist));
        }
    }
    
    dfs(1);
    dfs(farthest);
    
    cout << diameter;
    
    return 0;
}


