#include <iostream>
#include <algorithm>

using namespace std;

float applicant_bs[100];

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    int applicant;
    float score;

    for(int i=0; i<M; i++){    
        for(int j=0; j<N; j++){
            cin >> applicant >> score;
            applicant_bs[applicant-1] = max(score, applicant_bs[applicant-1]);
        }
    }

    sort(applicant_bs, applicant_bs+N, greater<float>());
    float answer =0;
    for(int i=0; i<K; i++){
        answer += applicant_bs[i];
    }
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << answer <<"\n";
    return 0;
}