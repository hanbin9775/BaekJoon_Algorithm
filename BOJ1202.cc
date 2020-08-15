#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main () {

    int n, k;
    cin >> n >> k;
    
    vector<pair<int,int>> jewels;
    jewels.resize(n);
    vector<int> backpack;
    backpack.resize(k);
    
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        jewels[i] = make_pair(a,b);
    }
    for(int i=0; i<k; i++){
        cin >> backpack[i];
    }
    
    sort(backpack.begin(), backpack.end());
    sort(jewels.begin(), jewels.end());
    
    long long max_price =0;
    
    priority_queue<int> pq;
    int j=0;
    for(int i=0; i<k; i++){
        while(j<n && backpack[i]>=jewels[j].first){
            pq.push(jewels[j].second);
            j++;
        }
        if(!pq.empty()){
            max_price += pq.top();
            pq.pop();
        }
    }
    cout << max_price;
    
    return 0;
}

