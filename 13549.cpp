//
// Created by 최희연 on 2022/01/24.
//

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

#define INF 98765432

int cost[100001];
queue<int> q;

int N, K;
int main(){

    cin>>N>>K;

    for(int i=0;i<100001; i++){
        cost[i] = INF;
    }

    cost[N] = 0;
    q.push(N);
    int minus, plus;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == K)
            break;

        minus = now-1;
        plus = now+1;
        if(minus>=0 && cost[minus]>cost[now]+1){
            cost[minus] = cost[now]+1;
            q.push(minus);
        }
        if(plus<100001 && cost[plus]>cost[now]+1){
            cost[plus] = cost[now]+1;
            q.push(plus);
        }
        if(now*2<100001 && cost[now*2]>cost[now]){
            cost[now*2] = cost[now];
            q.push(now*2);
        }
    }
    cout<<cost[K]<<endl;

}

