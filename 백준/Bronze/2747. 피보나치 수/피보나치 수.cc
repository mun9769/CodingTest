#include <cstdio>
#include <cstdlib>
#include <algorithm>

unsigned long long arr[91] = {0,1,};

int main()
{
    for(int i=2; i<91; i++)
        arr[i] = arr[i-1] + arr[i-2];
    int n;
    scanf("%d", &n);
    printf("%lld", arr[n]);


    

    return 0;
}
