#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<int> getK(int n, int k){
    vector<int> v;
    while(n >= k){
        v.push_back(n % k);
        n /= k;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    
    return v;
}


bool isPrime(long long n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n == 3) return true;
    
    bool possible = true;
    
    for(long long i=2; i*i <= n; i++){
        if(n % i == 0) {
            possible = false; 
            break;
        }
    }
    return possible;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> v = getK(n, k);
    
    for(int i=0; i<v.size(); i++){
        long long num = 0;
        
        while(i < v.size() && v[i] != 0){
            num *= 10;
            num += v[i];
            i++;
        }
        
        if(isPrime(num)) { answer++; }
    }
    return answer;
}