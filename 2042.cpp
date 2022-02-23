//
// Created by 최희연 on 2022/02/21.
//

#include <iostream>
using namespace std;

int N, M, K;
int a, b;
long long c;

long long idxtree[2222222];
int startIdx;

void setIdxtree() {
    for(int i=startIdx-1; i>0; i--){
        idxtree[i] = idxtree[i*2] +  idxtree[i*2+1];
    }
}

void update(int b, long long c){
    b+=(startIdx-1);
    idxtree[b] = c;
    //인덱스트리 수정해야해
    while(b/=2){
        idxtree[b] = idxtree[b*2] + idxtree[b*2+1];
    }
}

long long retSum(int b, int c){
    b+=(startIdx-1), c+=(startIdx-1);
    long long sum = 0;
    while(b<=c){
        if(b%2==1){
            sum+=idxtree[b];
        }
        if(c%2 == 0){
            sum+=idxtree[c];
        }
        b = (b+1)/2;
        c = (c-1)/2;
    }
    return sum;
}

int retStart(int n){
    int i = 1;
    while(i<n) {
        i*=2;
    }
    return i;
}

int main(){
    scanf("%d %d %d", &N, &M, &K); //N개의 수, M번 수 변경, K번 구간합구하기
    startIdx = retStart(N);

    for(int i=startIdx;i<startIdx+N;i++){
        scanf("%lld", &idxtree[i]);
    }
    setIdxtree();

    for(int i=0;i<M+K;i++){
        scanf("%d %d %lld", &a, &b, &c);
        if(a==1){
            update(b, c);

        }
        else if(a==2){
            printf("%lld\n", retSum(b, c));
        }
    }

}
