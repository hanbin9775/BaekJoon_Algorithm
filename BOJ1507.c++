#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int origin[20][20];
int arr[20][20];

int main () {

    int n;
    cin >> n;
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<n; j++){
            cin >> origin[i][j];
            arr[i][j] = origin[i][j];
        }
    }
    
    //floyd-warshall
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i==j || j==k || k==i) continue;
                if(origin[j][i]+origin[i][k]==origin[j][k]){
                    arr[j][k]=0;
                }
                else if(origin[j][i]+origin[i][k]<origin[j][k]){
                    cout << -1;
                    return 0;
                }
                
            }
        }
    }
    
    int sum=0;
    for(int i=0; i<n ;i++){
        for(int j=i; j<n; j++){
            sum+=arr[i][j];
        }
    }
    cout << sum;
    return 0;
}

