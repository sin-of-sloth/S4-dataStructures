#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
// program for merge sort

void Merge(long int A[], int p, int r1, int r2, int q)
{
	long int B[r1-p+1], C[r2-r1], D[q-r2], i, j, k, m;
	for(i=0; i<r1-p+1; i++)
	{
		B[i]=A[p+i];
	}
	for(i=0;i<r2-r1; i++)
	{	
		C[i]=A[r1+i+1];
	}
	for(i=0;i<q-r2; i++)
	{
		D[i]=A[r2+i+1];
	}
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
	}	
}

void Merge_Sort(long int A[], int p, int q)
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
	
	FILE *read_ptr=fopen("in","rb"),*write_ptr=fopen("out","wb");
	long int i=0, n, k;
	long int *A=malloc(sizeof(long int));
	long int size;
	fseek(read_ptr, 0, SEEK_END);
	size=ftell(read_ptr);
	fseek(read_ptr, 0, SEEK_SET);
	while(ftell(read_ptr)!=size)
	{
		fread(&k, sizeof(long int), 1, read_ptr);
		A=realloc(A, (i+1)*sizeof(long int));
		A[i]=k;
		i++;
	}
	n=i;
	Merge_Sort(A, 0, n-1);
	for(i=0;i<n;i++)
		fwrite(&A[i], sizeof(long int), 1, write_ptr);
	fclose(read_ptr);
	fclose(write_ptr);
	free(A);
	return 0;
}
