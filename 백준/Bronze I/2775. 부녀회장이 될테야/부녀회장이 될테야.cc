#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int arr[15][15];

int search(int (*a)[15], int n, int k)
{
    if(a[n][k] == 0)
    {
        for(int j=1; j<=k; j++){
            a[n][k] += search(a,n-1,j);
        }
    }
    else return a[n][k];
    return a[n][k];
}
int main()
{
    int N, n, k;
    scanf("%d", &N);
    for(int j=1; j<=14; j++)
        arr[0][j] = j;
    for(int j=1; j<=14; j++)
        arr[1][j] = j * (j+1) / 2;
    for(int j=1; j<=14; j++)
        arr[2][j] = j*(j+1)*(j+2) / 6;
            
    while(N-->0)
    {
        scanf("%d %d", &n, &k);
        printf("%d\n", search(arr,n,k));
    }
        
        
    return 0;
}
