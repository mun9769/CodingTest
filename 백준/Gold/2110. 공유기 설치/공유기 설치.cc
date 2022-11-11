#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n ,c;
vector<int> houses;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }
    //1. 주어진 집들의 좌표를 정렬한다.
    sort(houses.begin(), houses.end());
    
    //2. 집들 사이의 거리를 초기화한다.
    //최소 거리 1, 최대 거리 끝집-첫집 으로 초기화.
    //거리를 이용하여 이분 탐색을 진행한다.
    int start = 1;
    int end = houses[n-1] - houses[0];
    int result = 0;
    
    //3. 집들 사이의 거리를 기준으로 이분 탐색을 진행한다.
    while (start <= end) {
        int mid = (start+end) / 2;
        
        int cnt = 1;
        int prev_house = houses[0];
        for (int i = 1; i < n; i++) {
            if (houses[i] - prev_house >= mid) {
                cnt++;
                prev_house = houses[i];
            }
        }
        
        //4. 3을 만족하는 거리 중 최댓값을 갱신한다.
        //공유기를 제한 갯수 이상 사용했을 경우, 공유기를 설치 하는 거리를 늘린 후 다시 설치해 본다.
        if (cnt >= c) {
            result = max (result, mid);
            start = mid+1;
        }
        //공유기를 제한 갯수 미만 사용했을 경우, 공유기를 설치 하는 거리를 좁힌 후 다시 설치해 본다.
        else end = mid-1;
    }
    
    cout << result;
    return 0;
}