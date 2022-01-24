//
// Created by 최희연 on 2022/01/24.
//

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INF 98765432

int cost[100001];
bool visited[100001];
queue<int> q;

int N, K;
int main(){

    cin>>N>>K;

    for(int i=0;i<=N; i++){
        cost[i] = INF;
        visited[i] = false;
    }

    cost[N] = 0;
    q.push(N);
    int minus, plus;
    while(1) {
        int now = q.front();
        q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == K)
            break;
        minus = now-1;
        plus = now+1;
        if(abs(minus-K) < abs(plus-K)){
            cost[minus] = min(cost[minus], cost[now]+1);
            q.push(minus);
        }
        else if(abs(minus-K)>abs(plus-K)){
            cost[plus] = min(cost[plus], cost[now]+1);
            q.push(plus);
        }
        if(now*2<=100001){
            cost[now*2] = min(cost[now*2], cost[now]);
            q.push(now*2);
        }
    }
    cout<<cost[K]<<endl;

}

