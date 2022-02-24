//
// Created by 최희연 on 2022/02/24.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int N, M, K, X; //N:도시의 개수, M:도로의 개수, K:거리 정보, X:출발 도시의 번호
//2 ≤ N ≤ 300,000, 1 ≤ M ≤ 1,000,000, 1 ≤ K ≤ 300,000, 1 ≤ X ≤ N
int a, b;
vector<int> v[300001];
int cost[300001];
bool visited[300001];
queue<int> q;

int main(){
    scanf("%d %d %d %d", &N, &M, &K, &X);
    for(int i=0;i<=N;i++){
        cost[i] = INF;
        visited[i] = false;
        v[i].clear();
    }
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }
    cost[X] = 0;
    q.push(X);
    while(!q.empty()) {
        int nowNode = q.front();
        q.pop();
        if(visited[nowNode]) continue;
        visited[nowNode] = true;

        for(int i=0;i<v[nowNode].size();i++){
            int nextNode = v[nowNode].at(i);

            if(cost[nowNode] + 1 < cost[nextNode]){
                cost[nextNode] = cost[nowNode]+1;
                q.push(nextNode);
            }

        }
    }
    bool flag = false;
    for(int i=1;i<=N;i++){
        if(cost[i] == K) {
            printf("%d\n", i);
            flag = true;
        }
    }
    if(!flag) printf("-1\n");


}
