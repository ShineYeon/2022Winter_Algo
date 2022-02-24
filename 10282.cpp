//
// Created by 최희연 on 2022/02/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432

struct Data{
    int node;
    int weight;
    Data() {};
    Data(int node, int weight):node(node), weight(weight) {};
    bool operator< (const Data d) const {
        return weight>d.weight;
    }

};

int T; //테스트케이스
int n, d, c; //컴퓨터개수n, 의존성개수d, 해킹당한컴퓨터번호c
int a, b, s;
vector<Data> vd[10001];
priority_queue<Data> pq;
int cost[10001];
bool visited[10001];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &d, &c);
        for(int i=0;i<=n;i++){
            vd[i].clear();
            visited[i] = false;
            cost[i] = INF;
        }
        for(int i=0;i<d; i++){
            scanf("%d %d %d", &a, &b, &s); //a가 b에 의존한다.
            vd[b].push_back(Data(a, s));
        }

        cost[c] = 0;
        pq.push(Data(c, 0));
        while(!pq.empty()) {
            Data nowNode = pq.top();
            pq.pop();
            if(visited[nowNode.node]) continue;
            visited[nowNode.node] = true;
            for(int i=0;i<vd[nowNode.node].size();i++){
                Data nextNode = vd[nowNode.node].at(i);
                if(cost[nextNode.node] > cost[nowNode.node] + nextNode.weight){
                    cost[nextNode.node] = cost[nowNode.node] + nextNode.weight;
                    pq.push(Data(nextNode.node, cost[nextNode.node]));
                }
            }
        }
        int maxTime = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(cost[i] == INF) continue;
            else{
                maxTime = max(maxTime, cost[i]);
                cnt++;
            }
        }
        printf("%d %d\n", cnt, maxTime);

    }
}
