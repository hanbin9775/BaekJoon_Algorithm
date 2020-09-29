#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

int l, c;

vector<char> candidateChar;
vector<string> possibleAllKeys;

void dfs(vector<char> candidateKey, int currentIndex){
    
    if(currentIndex == c) return;
    
    dfs(candidateKey, currentIndex+1);
    
    candidateKey.push_back(candidateChar[currentIndex]);
    
    if(candidateKey.size()==l){
        int consonant_cnt = 0;
        int vowel_cnt = 0;
        
        for(int i=0; i<l; i++){
            if(candidateKey[i]=='a' || candidateKey[i]=='e' || candidateKey[i]=='i' || candidateKey[i]=='o' || candidateKey[i]=='u'){
                vowel_cnt++;
            }
            else consonant_cnt++;
        }
        
        if(vowel_cnt>=1 && consonant_cnt >=2){
            string key = "";
            for(int i=0; i<l; i++){
                key += candidateKey[i];
            }
            possibleAllKeys.push_back(key);
        }
        return;
    }
    
    dfs(candidateKey, currentIndex+1);
    
}

int main(){
        
    cin >> l >> c;
    
    candidateChar.resize(c);
    
    for(int i=0; i<c; i++){
        cin >> candidateChar[i];
    }
    
    vector<char> candidateKey;
    
    sort(candidateChar.begin(), candidateChar.end());
    
    dfs(candidateKey, 0);
    
    
    for(int i=possibleAllKeys.size()-1; i>=0; i--){
        cout << possibleAllKeys[i] << "\n";
    }
    
    return 0;
    
}



