//
// Created by 최희연 on 2022/02/09.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int N, M;
int a, b, c;
int parent[1001];
bool visited[1001];
int cost[1001];

struct Data{
    int weight;
    int node;
    Data() {};
    Data(int node, int weight):node(node), weight(weight) {};
    bool operator<(const Data d)const{
        return weight>d.weight;
    }
};

vector<Data> vd[1001];
priority_queue<Data> pq;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<=N;i++){
        vd[i].clear();
        visited[i] = false;
        cost[i] = INF;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &a, &b, &c);
        vd[a].push_back(Data(b, c));
        vd[b].push_back(Data(a, c));

    }

    cost[1] = 0;
    parent[1] = 0;
    pq.push(Data(1, 0));

    while(!pq.empty()) {
        Data now = pq.top();
        pq.pop();
        if(visited[now.node]) continue;
        visited[now.node] = true;
        for(int i=0;i<vd[now.node].size();i++){
            Data next = vd[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight){
                parent[next.node] = now.node;
                cost[next.node] = cost[now.node] + next.weight;
                pq.push(Data(next.node, cost[next.node]));
            }
        }
    }

    int  cnt = 0;
    for(int i=1;i<=N;i++){
        if(parent[i] != 0) cnt++;
    }
    printf("%d\n", cnt);
    for(int i=1;i<=N;i++){
        if(parent[i] != 0){
            printf("%d %d\n", i, parent[i]);
        }
    }

}

