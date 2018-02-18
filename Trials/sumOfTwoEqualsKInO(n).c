#include<stdio.h>

int main()
{
	int n, k, i;
	printf("\Enter the number of elements : ");
	scanf("%d", &n);
	int A[n];
	printf("\nEnter the elements of the array :\n");
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &k);
	int beg=0, end=n-1;
	while(beg<end)
	{
		if(A[beg] + A[end] == k)
		{
			printf("%d and %d sum upto %d.\n", A[beg], A[end], k);
			return 0;
		}
		else if(A[beg] + A[end] > k)
			end--;
		else beg++;
	}
	printf("No two elements sum upto %d.\n", k);
	return 0;
}