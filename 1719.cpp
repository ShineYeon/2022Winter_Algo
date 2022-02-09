//
// Created by 최희연 on 2022/02/09.
//

#include <iostream>
using namespace std;

#define INF 98765432

int n, m;
int path[1001][1001];
int a, b, c;
int ans[1001][1001];

int main(){

    scanf("%d %d", &n, &m);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) path[i][j] = 0;
            else path[i][j] = INF;

        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        path[a][b] = c;
        path[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }


    for(int k=1; k<=n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i==j) continue;
                if (path[i][j] > path[i][k] + path[k][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                    if(i!=k) ans[i][j] = ans[i][k];
                 }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j] == 0)
                printf("- ");
            else
                printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

}

