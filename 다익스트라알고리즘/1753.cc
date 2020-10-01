#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

#define INF 200001

using namespace std;

int v, e, start;

int main(){
        
    cin >> v >> e >> start;
    
    vector<vector<pair<int,int>>> graph;
    graph.resize(v+1);
    
    for(int i=0; i<e; i++){
        int from, to, value;
        cin >> from >> to >> value;

        graph[from].push_back(make_pair(to,value));
    }
    
    //dijkstra
    
    vector<int> dist;
    dist.resize(v+1, INF);
    vector<bool> visited;
    visited.resize(v+1, false);
    
    for(int i=0; i<graph[start].size(); i++){
        dist[graph[start][i].first] = min(dist[graph[start][i].first], graph[start][i].second);
    }
    
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    visited[start] = true;
    
    while(!pq.empty()){
        int curNode = pq.
        
    }
    
    return 0;
    
}



