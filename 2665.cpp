//
// Created by 최희연 on 2022/02/08.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432

int n; //한줄에 들어가는 방의 수
string arr[51];
int cost[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cost[i][j] = INF;
        }
    }
    cost[0][0] = 0;
    int nowX, nowY, newX, newY;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        nowX = q.front().first;
        nowY = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            newX = nowX+dx[i];
            newY = nowY+dy[i];
            if(newX<0 || newY<0 || newX>=n || newY>=n) continue;
            if(arr[newX][newY] == '1'){
                if(cost[newX][newY] > cost[nowX][nowY]) {
                    cost[newX][newY] = cost[nowX][nowY];
                    q.push(make_pair(newX, newY));
                }
            }
            else if(cost[newX][newY] > cost[nowX][nowY]+1){
                cost[newX][newY] = cost[nowX][nowY]+1;
                q.push(make_pair(newX, newY));
            }
        }
    }

    cout<<cost[n-1][n-1]<<endl;

}

