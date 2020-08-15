#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool arr[10000][500];

int dir_y[3] = {1,0,-1};

int r, c;

int dfs(int start){
    stack<pair<int, int>> stk;
    stk.push(make_pair(start,0));
    
    while(!stk.empty()){
        
        int cur_y = stk.top().first;
        int cur_x = stk.top().second;
        arr[cur_y][cur_x] = false;
        stk.pop();
        
        if(cur_x==c-1) {
            return 1;
            break;
        }
        
        for(int i=0; i<3; i++){
            int next_y = cur_y + dir_y[i];
            if(next_y<0 || next_y>=r) continue;
            int next_x = cur_x +1;
            
            if(arr[next_y][next_x]){
                stk.push(make_pair(next_y,next_x));
            }
        }
    }
    return 0;
}

int main () {

    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        string str;
        cin >> str;
        for(int j=0; j<c; j++){
            if(str[j]=='.') arr[i][j] = true;
        }
    }
    int cnt=0;
    for(int i=0; i<r; i++){
        cnt += dfs(i);
    }
    cout << cnt;
    
    return 0;
}

