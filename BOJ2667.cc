#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool arr[25][25];
bool visited[25][25];
int n;

int dfs(int i, int j){
    int cnt=0;
    
    stack<pair<int,int>> stk;
    stk.push(make_pair(i,j));
    
    int y, x;
    
    while(!stk.empty()){
        y = stk.top().first;
        x = stk.top().second;
        stk.pop();
        
        if(!visited[y][x]){
            visited[y][x] = true;
            cnt+=1;
        }
        
        if(y>0 && !visited[y-1][x] && arr[y-1][x]) stk.push(make_pair(y-1,x));
        if(x>0 && !visited[y][x-1] && arr[y][x-1]) stk.push(make_pair(y,x-1));
        if(y<n-1 && !visited[y+1][x] && arr[y+1][x]) stk.push(make_pair(y+1,x));
        if(x<n-1 && !visited[y][x+1] && arr[y][x+1]) stk.push(make_pair(y,x+1));
        
    }
    
    return cnt;
}

int main () {

    vector<int> v;
    
    cin >> n;
    string input;
    for(int i=0; i<n; i++){
        cin >> input;
        for(int j=0; j<n; j++){
            if(input[j]=='1') arr[i][j]=true;
        }
    }
    
    stack<pair<int,int>> stk;
    stk.push(make_pair(0,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] && !visited[i][j]){
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() <<"\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}

