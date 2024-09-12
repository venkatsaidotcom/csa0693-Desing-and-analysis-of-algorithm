#include<stdio.h>
int main()
{
	int n,i,min,j,swap;
	printf("enter the no . of elements:");
	scanf("%d",&n);
	int array[n];
	printf("enter the elemts:");
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	for(i=0;i<n-1;i++){
		min=i;
	for(j=i+1;j<n;j++){
		if(array[j]<array[min])
	    min=j;
	}
	if(min!=i){
		swap=array[i];
		array[i]=array[min];
		array[min]=swap;
	}
	}
	printf("sorted elements:");
	for(i=0;i<n;i++)
	printf("%d",array[i]);
	
}
