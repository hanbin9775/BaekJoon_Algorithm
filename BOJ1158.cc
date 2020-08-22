#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool used[5001];

int main(){
    int n, k;
    cin >> n>> k;
    
    vector<int> answer;
    
    int idx=1;
    int cnt=1;
    
    while(answer.size()!=n){
        
        if(idx>n) idx=1;
        if(cnt==k+1) cnt=1;
        
        if(used[idx]){
            cnt--;
        }
        
        if(cnt==k){
            if(!used[idx]){
                used[idx]=true;
                answer.push_back(idx);
            }
        }
        
        idx++;
        cnt++;
        
    }
    
    
    cout << "<";
    for(int i=0; i<n; i++){
        if(i==n-1){
            cout << answer[i];
            break;
        }
        cout << answer[i] << ", ";
    }
    cout << ">";
    
    return 0;
    
}



