#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

#define INF 10000000000

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph;
    graph.resize(N+1);
    
    for(int i=0; i<M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    
    int start, end;
    cin >> start >> end;
    
    vector<int> dist;
    dist.resize(N+1, INF);
    dist[start] = 0;
    
    for(int i=0; i<graph[start].size(); i++){
        dist[graph[start][i].first] = graph[start][i].second;
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int curNode = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        
        if(dist[curNode] < distance) continue;
        
        for(int i=0; i<graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int nextDist = graph[curNode][i].second;
            
            if(nextDist + distance <= dist[nextNode]){
                dist[nextNode] = nextDist + distance;
                pq.push(make_pair(-dist[nextNode], nextNode));
            }
        }
    }
    
    cout << dist[end];
    
    return 0;
    
}



