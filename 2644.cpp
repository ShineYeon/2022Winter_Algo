//
// Created by 최희연 on 2022/01/25.
//

#include <iostream>
using namespace std;

int n, m;
int human1, human2;
int x, y;
int parent[101];

int main(){
    cin>>n;
    cin>>human1>>human2;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        parent[y] = x;
    }
    int origX = x;
    int origY = y;
    int common = -1;
    int cnt = 0;
    while(1){
        if(parent[x]==parent[y]){
            common = parent[x];
            break;
        }
        else{ //parent[x]!=parent[y]
            if(parent[x]==0 && parent[y]==0)
                break;

            else if(parent[x] == 0){
                y=parent[y];
            }
            else if(parent[y]==0){
                x=parent[x];
            }
            else{
                x=parent[x];
                y=parent[y];
            }
        }
    }
    if(common!=-1) {

        cout << cnt << endl;
    }
    else if(common==-1)
        cout<<-1<<endl;

}

