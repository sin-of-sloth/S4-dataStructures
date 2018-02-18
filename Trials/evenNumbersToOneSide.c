#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j=-1;
	printf("\Enter the number of elements : ");
	scanf("%d", &n);
	int A[n];
	printf("\nEnter the elements of the array :\n");
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	for(i=0;i<n;i++)
	{
		if(A[i]%2==0)
		{
			j++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}		
	}
	printf("\nThe array with the even numbers to one side is :\n")
	for(i=0;i<n;i++)
		printf("%d ", A[i]);	
	return 0;
}