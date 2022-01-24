#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 이 문제는 visited 배열이 필요없음
 * 왜냐면 기존에 없던 알파벳이면 그냥 가면되니까
 * 그래서 visit했는지 저장할 필요가 없음
 */
int R, C; //R:세로, C:가로
char alpha[21][21];
bool isIn[26];

int nextX, nextY;
int ans = 0;
int cost[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int cost){
    ans = max(ans, cost);
    int newX, newY;
    for(int i=0;i<4;i++){
        newX = x+dx[i];
        newY = y+dy[i];
        if(newX<0 || newY<0 || newX>=R || newY>=C)
            continue;
        if(!isIn[alpha[newX][newY]-'A']) {
            isIn[alpha[newX][newY]-'A'] = true;
            dfs(newX, newY, cost+1);
            isIn[alpha[newX][newY]-'A'] = false;
        }
    }
}

int main() {
    cin>>R>>C;

    for(int i=0;i<26;i++){
        isIn[i]= false;
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>alpha[i][j];
            cost[i][j] = 0;

        }
    }

    isIn[alpha[0][0]-'A'] = true;
    dfs(0, 0, 1);

    cout<<ans<<endl;


}
