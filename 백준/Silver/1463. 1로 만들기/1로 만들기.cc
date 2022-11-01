#include <cstdio>
#include <cstdlib>

int a[1000002];

int main()
{
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    int n, i=5;
    scanf("%d", &n);
    while(i<=n)
    {
        int min=2147000000;
        if(i % 3 == 0)
            min = a[i / 3] + 1;
        if(i % 2 == 0)
            if(min > a[i / 2] + 1)
                min = a[i / 2] + 1;
        if(min > a[i-1] + 1)
            min = a[i-1] +1;
        
        a[i++] = min;
    }

    printf("%d\n", a[n]);
    return 0;
}
