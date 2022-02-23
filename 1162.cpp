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


priority_queue<pair<Data, int>> pq;
vector<Data> vd[10001];
long long cost[10001][21]; //dp이용하는 cost, 1번에서 첫번째 인덱스로 가는데 두번째인덱스만큼 포장해서 가는 최소비용
bool visited[10001];

void dijkstra() {
    pq.push(make_pair(Data(1, 0), K));
    cost[1][K] = 0;
    while(!pq.empty()) {
        int nowNode = pq.top().first.node;
        long long nowCost = pq.top().first.weight;
        int cnt = pq.top().second;

        pq.pop();

        for(int i=0;i<vd[nowNode].size();i++){
            int nextNode = vd[nowNode].at(i).node;
            long long nextCost = vd[nowNode].at(i).weight + nowCost;

            if(cnt>0){
                if(cost[nextNode][cnt-1] > nowCost){
                    cost[nextNode][cnt-1] = nowCost;
                    pq.push(make_pair(Data(nextNode, nowCost), cnt-1));
                }
            }
            if(cost[nextNode][cnt] > nextCost){
                cost[nextNode][cnt] = nextCost;
                pq.push(make_pair(Data(nextNode, nextCost), cnt));
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0;i<=N;i++){
        vd[i].clear();
        visited[i] = false;
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            cost[i][j] = INF;
        }
    }
    for(int i=1;i<=M;i++){
        scanf("%d %d %d", &a, &b, &c);
        vd[a].push_back(Data(b, c));
        vd[b].push_back(Data(a, c));
    }
    dijkstra();

    long long ans = 1e15;
    for(int i=0;i<=K;i++){
        ans = min(ans, cost[N][i]);
    }


    printf("%lld\n", ans);

    return 0;
}

