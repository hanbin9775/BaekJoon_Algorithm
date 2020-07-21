#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> v_set;

void able_lotto(int n, int idx, const vector<int> &v, vector<int> container){
    if(container.size()==6) {
        v_set.push_back(container);
        return;
    }
    if(idx==n) return;
    
    
    able_lotto(n, idx+1, v, container);
    container.push_back(v[idx]);
    able_lotto(n, idx+1, v, container);
    
}

int main(){
    int N;
    vector<int> v;
    vector<int> container;
    
    while(1){
        cin >> N;
        if(N==0) break;
        for(int i=0; i<N; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        able_lotto(N, 0, v, container);
        sort(v_set.begin(), v_set.end());
        for(int i=0; i<v_set.size(); i++){
            for(int j=0; j<6; j++){
                cout << v_set[i][j] <<" ";
            }
            cout << "\n";
        }
        cout << "\n";
        
        v_set.clear();
        v.clear();
    }
    return 0;
}
