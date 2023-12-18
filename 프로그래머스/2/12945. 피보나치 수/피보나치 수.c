#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define mod 1234567

int dp[100005];

int Fibo(int x){
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else if(dp[x]) 
        return dp[x];
    else 
        return dp[x] = Fibo(x-2) % mod + Fibo(x-1) % mod;
}

int solution(int n) {
    int answer = 0;
    
    answer = Fibo(n) % mod;
    return answer;
}