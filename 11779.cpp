//
// Created by 최희연 on 2022/02/08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define INF 98765432

int n, m; //n:도시 개수, m:버스 개수
int a, b, c;
int start, dest;

struct Data{
    int node;
    int weight;
    Data() {};
    Data(int node, int weight) :node(node), weight(weight) {};
    bool operator<(const Data d) const{
        return weight>d.weight;
    }
};

vector<Data> vd[1001];
priority_queue<Data> pq;
int cost[1001];
bool visited[1001];
int parent[1001];

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0;i<=n;i++){
        vd[i].clear();
        cost[i] = INF;
        visited[i] = false;
        parent[i] = i;
    }
    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &a, &b, &c);
        vd[a].push_back(Data(b, c));
    }
    scanf("%d %d", &start, &dest);

    cost[start] = 0;
    parent[start] = 0;
    pq.push(Data(start, 0));

    while(!pq.empty()){
        Data now = pq.top();
        pq.pop();
        if(visited[now.node]) continue;
        visited[now.node] = true;

        for(int i=0;i<vd[now.node].size();i++){
            Data next = vd[now.node].at(i);
            if(cost[next.node] > cost[now.node] + next.weight) {
                cost[next.node] = cost[now.node] + next.weight;
                parent[next.node] = now.node;
            }
            pq.push(Data(next.node, cost[next.node]));
        }
    }

    cout<<cost[dest]<<endl;
    stack<int> st;
    int cnt = 0;
    while(dest) {
        st.push(dest);
        dest = parent[dest];
        cnt++;
    }
    cout<<cnt<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

