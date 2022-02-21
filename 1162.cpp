//
// Created by 최희연 on 2022/02/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432

int N, M, K; //N:도시수, M:도로수, K:포장할도로수(없애서합침)
int a, b, c;

struct Data {
    int node;
    int weight;
    Data() {};
    Data(int node, int weight):node(node), weight(weight) {};
    bool operator<(const Data d) const{
        return node>d.node;
    }
};

bool compare(int i, int j){
    return j<i;
}

priority_queue<Data> pq;
vector<Data> vd[10001];
int tmpCost[50001];
int cost[10001];
bool visited[10001];

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0;i<=N;i++){
        vd[i].clear();
        cost[i] = INF;
        visited[i] = false;
    }
    for(int i=1;i<=M;i++){
        scanf("%d %d %d", &a, &b, &c);
        vd[a].push_back(Data(b, c));
        vd[b].push_back(Data(a, c));
        tmpCost[i-1] = c;
    }

    sort(tmpCost, tmpCost+M, compare);
    bool check = false;
    for(int i=0;i<K;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<vd[j].size();k++){
                if(vd[j].at(k).weight == tmpCost[i]){
                    check=true;
                    vd[j].at(k).weight = 0;
                    for(int s=0;s<vd[vd[j].at(k).node].size();s++) {
                        if(vd[vd[j].at(k).node].at(s).node == j) {
                            vd[vd[j].at(k).node].at(s).weight = 0;
                            break;
                        }
                    }
                    break;
                }
            }
            if(check) break;
        }
        check = false;
    }

    pq.push(Data(1, 0));
    cost[1] = 0;
    while(!pq.empty()) {
        Data now = pq.top();
        pq.pop();
        if(visited[now.node]) continue;
        visited[now.node] = true;
        for(int i=0;i<vd[now.node].size();i++){
            Data next = vd[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight){
                cost[next.node] = cost[now.node]+ next.weight;
                pq.push(Data(next.node, cost[next.node]));
            }
        }
    }

    printf("%d\n", cost[N]);
}

