#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

#define INF 5100

int arr[101][101];

int main(){
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) arr[i][j]=0;
            else arr[i][j] = INF;
            
        }
    }
    
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        
        arr[from][to] = 1;
        arr[to][from] = 1;
    }
    
    //floyd-warshall
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][i] + arr[i][k] < arr[j][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }
    
    int lowest_person = 1;
    int lowest_kb = INF;
    
    for(int i=1; i<=n; i++){
        int kb_cnt=0;
        for(int j=1; j<=n; j++){
            kb_cnt += arr[i][j];
        }
        if(lowest_kb> kb_cnt){
            lowest_kb = kb_cnt;
            lowest_person = i;
        }
    }
    
    cout << lowest_person << "\n";
    
    return 0;
    
}



