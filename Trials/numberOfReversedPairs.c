#include <stdio.h>
#include<limits.h>


int count = 0;


void merge(int A[], int p, int r, int q)
{
	int B[r-p+1], C[q-r], i, j;
	for(i=0;i<r-p+1;i++)
		B[i]=A[p+i];
	for(i=0;i<q-r;i++)
		C[i]=A[r+1+i];
	int k=p;
	i=0;
	j=0;
	while(( i<r-p+1) && (j<q-r))
	{
		if(B[i]<C[j])
		{
			A[k]=B[i];
			i++;
			k++;
		}
		else
		{
			count=count+r-p+1-i;
			A[k]=C[j];
			j++;
			k++;
		}
	}
	while(i < r-p+1)
	{
		A[k]=B[i];
		i++;
		k++;
	}
	while(j < q-r)
	{
		A[k]=C[j];
		j++;
		k++;
	}	
}



void mergeSort(int A[], int p, int q)
{
	if(p<q)
	{
		int r = p + (q-p)/2;
		mergeSort(A, p, r);
		mergeSort(A, r+1, q);
		merge(A, p, r, q);
	}
}


int main()
{
	int n, i;
	printf("\Enter the number of elements : ");
	scanf("%d", &n);
	int A[n];
	printf("\nEnter the elements of the array :\n");
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	mergeSort(A, 0, n-1);
	printf("\nThe number of reversed pairs is : %d\n", count);
	return 0;
}