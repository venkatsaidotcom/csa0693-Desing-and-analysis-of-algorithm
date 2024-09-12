#include<stdio.h>
int main()
{
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=2;i<=n/2;i++){
		if(n%i==0)
		sum++;
	}
	if(sum==0 and n>i)
	printf("prime");
	else
	printf("np");
}
