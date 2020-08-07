#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int n, m;

int main () {
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int s=0, e=0;
    int sum = v[e];
    int cnt =0;
    
    while(e<n){
        if(sum==m) cnt++;
        
        if(sum<m){
            e++;
            if(e<n) sum += v[e];
        }
        else{
            sum -= v[s];
            s++;
        }
        
    }
    cout << cnt;
    
    return 0;
}

