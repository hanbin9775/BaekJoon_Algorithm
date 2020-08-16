#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int n, k;
int inputs[100];

int main () {

    cin >> n >> k;
    
    for(int i=0; i<k; i++){
        cin >> inputs[i];
    }
    
    vector<int> multitab;
    int cnt=0;
    
    for(int i=0; i<k; i++){
        int input = inputs[i];
        if(find(multitab.begin(), multitab.end(), input)!=multitab.end()) continue;
        
        if(multitab.size()<n){
            multitab.push_back(input);
        } else{
            int most_far_dist=0;
            int most_far_idx=0;
            for(int j=0; j<n; j++){
                int distance=k;
                for(int u=i; u<k; u++){
                    if(inputs[u]==multitab[j]){
                        distance = u;
                        break;
                    }
                }
                if(most_far_dist < distance){
                    most_far_dist = distance;
                    most_far_idx = j;
                }
            }
            multitab[most_far_idx] = input;
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}

