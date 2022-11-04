#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

static int *buff;

void __mergesort(int *a, int left, int right)
{
	if(left < right)
	{
		int i,j=0,p=0;
		int k=left;
		int center = (left+right)/2;
		__mergesort(a,left,center);
		__mergesort(a,center+1,right);
		for(i=left;i<=center;i++)
			buff[p++] = a[i];
		while(i<=right && j <p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while(j<p)
			a[k++] = buff[j++];
	}
}
int mergesort(int *a, int n)
{

	if((buff = (int*)malloc(sizeof(int) * n)) == NULL){
		return -1;
	}
	__mergesort(a,0,n-1);
	free(buff);
	return 0;
}

void my__mergesort(int *a, int left, int right)
{
	if(left < right)
	{
		int i,j=0,p=0;
		int k=left;
		int center = (left+right)/2;
		my__mergesort(a,left,center);
		my__mergesort(a,center+1,right);
		for(i=left;i<=center;i++)
			buff[p++] = a[i];
		while(i<=right && j <p)
			a[k++] = (buff[j] >= a[i]) ? buff[j++] : a[i++];
		while(j<p)
			a[k++] = buff[j++];

				
	}
}
int mymergesort(int *a, int n)
{

	if((buff = (int*)malloc(sizeof(int) * n)) == NULL){
		return -1;
	}
	my__mergesort(a,0,n-1);
	free(buff);
	return 0;
}
int main()
{
	int N;
	scanf("%d",&N);
	int a[N], b[N];
	for(int i=0; i<N; i++)
		scanf("%d", &a[i]);
	for(int i=0; i<N; i++)
		scanf("%d", &b[i]);
	mergesort(a,N);
	mymergesort(b,N);
	int sum = 0;
	for(int i=0; i<N; i++)
		sum += a[i]*b[i];
	printf("%d",sum);

	return 0;
}
