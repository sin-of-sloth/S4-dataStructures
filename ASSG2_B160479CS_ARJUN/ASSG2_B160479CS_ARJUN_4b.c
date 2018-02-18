#include<stdio.h>
#include<stdlib.h>


void leSearcher(int A[], int beg, int end, int k)
{
	int mid = (beg+end)/2;
	if(beg<=end)
	{
		if(A[mid]==k)
		{
			printf("%d", mid);
			exit(0);
		}
		else if (A[mid]>A[beg] && A[mid]<A[end])
		{
			if(k<A[mid])
				leSearcher(A, beg, mid-1, k);
			else
				leSearcher(A, mid+1, end, k);
		}
		else if (A[mid]>A[beg])
		{
			if(k>=A[beg])
				leSearcher(A, beg, mid-1, k);
			else
				leSearcher(A, mid+1, end, k);
		}
		else if (A[mid]<A[end])
		{
			if(k<=A[end])
				leSearcher(A, mid+1, end, k);
			else
		 	 	 leSearcher(A, beg, mid-1, k);
		}
	}
}


int main()
{
	int n, k, i;
	scanf("%d", &n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	scanf("%d", &k);
	leSearcher(A, 0, n-1, k);
	//binarySearch(A, 0, n-1	,k);
	printf("-1");
	return 0;
}