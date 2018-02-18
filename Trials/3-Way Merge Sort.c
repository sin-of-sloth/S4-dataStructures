#include<stdio.h>
#include<limits.h>


void Merge(int A[], int p, int r1, int r2, int q)
{
//	printf("\nMERGE\n");
//	printf("p=%d q=%d r1=%d r2=%d\n",p,q,r1,r2);
	int B[r1-p+1], C[r2-r1], D[q-r2], i, j, k, m;
//	printf("B : ");
	for(i=0; i<r1-p+1; i++)
	{
		B[i]=A[p+i];
//		printf("%d ",B[i]);
	}
//	printf("\nC : ");
	for(i=0;i<r2-r1; i++)
	{	
		C[i]=A[r1+i+1];
//		printf("%d ",C[i]);
	}
//	printf("\nD : ");
	for(i=0;i<q-r2; i++)
	{
		D[i]=A[r2+i+1];
//		printf("%d ",D[i]);
	}
//	printf("\n");
	i=0;
	j=0;
	k=0;
	m=p;
	B[r1-p+1]=INT_MAX;
	C[r2-r1]=INT_MAX;
	D[q-r2]=INT_MAX;
	for(; m<=q; m++)
	{
		if(B[i]<C[j])
		{
			if(B[i]>D[k])
			{
				A[m]=D[k];
				k++;
			}
			else
			{
				A[m]=B[i];
				i++;
			}
		}
		else
		{
			if(C[j]>D[k])
			{
				A[m]=D[k];
				k++;
			}
			else
			{
				A[m]=C[j];
				j++;
			}
		}
//		printf("%d ",A[m]);
	}
//	printf("\n");
}

void Merge_Sort(int A[], int p, int q)
{
	int r1, r2;
	if(p<q)
	{
		r1=p+((q-p)/2);
		r2=q-((q-p)/2);
		Merge_Sort(A, p, r1);
		Merge_Sort(A, r1+1, r2);
		Merge_Sort(A, r2+1, q);
		Merge(A, p, r1, r2, q);
	}
	else
	{
		return;
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	Merge_Sort(A, 0, n-1);
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
	return 0;
}