
// program for modified quick sort
#include<stdio.h>

int count=0;

int partition(int *A, int low, int high)
{
	int pivot=A[high], temp;
	int j, i=low-1;
	for(j=low; j<high; j++)
	{
		if(A[j]<=pivot)
		{
			i+=1;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	i+=1;
	temp=A[i];
	A[i]=A[j];
	A[j]=temp;
	return i;
}

int medianFinder(int* A, int low, int high)
{		
	int size=high-low+1, median;
	if(size%2==0)
		median=low+(size/2)-1;
	else
		median=low+((size-1)/2);
	while(1)
	{
		int index = partition(A, low, high);
		if(index == median)
			return A[median];
		else if(median < index)
			high=index-1;
		else
			low=index+1;
	}
}

int partitions(int* A, int low, int high, int median)
{	
	int i=low-1, j;
	for(j=low; j<high; j++)
	{
		if(A[j]<=median)
		{
			i+=1;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	return i;
}


void modifiedQuickSort(int* A, int low, int high)
{
	if(low<high)
	{
		int median=medianFinder(A, low, high);
		if(count<3)
		{
			printf("%d\n", median);
			count++;
		}
		int pi=partitions(A, low, high, median);
		modifiedQuickSort(A, low, pi-1);
		modifiedQuickSort(A, pi+1, high);
	}
}


int main()
{
	int n, i;
	scanf("%d", &n);
	int A[n];
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	if(n%2==0)
		modifiedQuickSort(A, 0, n-1);
	else
		modifiedQuickSort(A, 0, n-1);
	for(i=0; i<n; i++)
		printf("%d ", A[i]);
	return 0;
}
