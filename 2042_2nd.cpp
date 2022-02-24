//
// Created by 최희연 on 2022/02/24.
//

#include <iostream>
using namespace std;

int N, M, K;
int startIdx;
int a, b;
long long c;

long long idxTree[4000004];

int retStart(int n){
    int i=1;
    while(i<n){
        i*=2;
    }
    return i;
}

void setTree(){
    for(int i=startIdx-1; i>0; i--){
        idxTree[i] = idxTree[i*2] + idxTree[i*2+1];
    }
}

void update(int b, long long c){
    b += (startIdx-1);
    idxTree[b] = c;
    while(b/=2){
        idxTree[b] = idxTree[b*2] + idxTree[b*2+1];
    }
}

long long retSum(int b, int c){
    b+= (startIdx-1), c+=(startIdx-1);
    long long sum = 0;
    while(b<=c){
        if(b%2==1) sum+=idxTree[b];
        if(c%2==0) sum+=idxTree[c];
        b = (b+1)/2;
        c = (c-1)/2;
    }
    return sum;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    startIdx = retStart(N);
    for(int i=startIdx;i<startIdx+N;i++){
        scanf("%lld", &idxTree[i]);
    }
    setTree();

    for(int i=0;i<M+K;i++){
        scanf("%d %d %lld", &a, &b, &c);
        if(a==1){ //수 변경
            update(b, c);
        }
        else if(a==2){ //구간 합 가져오기
            printf("%lld\n", retSum(b, c));
        }
    }
}