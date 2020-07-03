#include <queue>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

int N;
int K;
int L;
queue<pair<int, char> > q;

int arr[100][100];

int main(){
    cin >> N >> K;
    int x=0, y=0;
    for(int i=0; i<K; i++){
        cin >> y >> x;
        arr[y][x] = 2;
    }
    cin >> L;
    int sec;
    char dir;
    for(int i=0; i<L; i++){
        cin >> sec >> dir;
        q.push(make_pair(sec, dir));
    }

    bool dead = false;
    int timer=0;
    int len = 1;
    char cur_dir = 'E';
    deque<pair<int, int> > snake;
    pair<int, int> cur_loc = make_pair(0,0);
    snake.push_back(cur_loc);
    while(!dead){
        timer++;
        
        //이동
        switch(cur_dir){
            case 'E':
                cur_loc.second++;
                break;
            case 'W':
                cur_loc.second--;
                break;
            case 'S':
                cur_loc.first++;
                break;
            case 'N':
                cur_loc.first--;
                break;
        }
        snake.push_back(cur_loc);

        //사과먹음
        if(arr[cur_loc.first][cur_loc.second]== 2){
            len++;
        }

        //꼬리 이동
        if(snake.size() > len){
            snake.pop_front();
        }

        //벽에 부딪혀 사망
        if(cur_loc.first<0 || cur_loc.first >=N || cur_loc.second < 0 || cur_loc.second >= N ){
            dead = true;
        }
        //자기 꼬리에 부딪혀 사망
        for(int i=0; i<snake.size(); i++){
            if(cur_loc == snake[i]) dead= true;
        }

        //방향 전환
        if(timer == q.front().first){
            switch(q.front().second){
                case 'L':
                    if(cur_dir == 'E') cur_dir = 'N';
                    if(cur_dir == 'N') cur_dir = 'W';
                    if(cur_dir == 'W') cur_dir = 'S';
                    if(cur_dir == 'S') cur_dir = 'E';
                    break;
                case 'D':
                    if(cur_dir == 'E') cur_dir = 'S';
                    if(cur_dir == 'N') cur_dir = 'E';
                    if(cur_dir == 'W') cur_dir = 'N';
                    if(cur_dir == 'S') cur_dir = 'W';
                    break;
            }
        }
        q.pop();
    }
    cout << timer << '\n';
}