#include<stdio.h>

int main()
{
	int m, n, i, j, k, flag;
	scanf("%d%d", &m, &n);
	int A[m][n];
	for(i=0;i <m; i++)
	{
			for(j=0; j<n; j++)
			scanf("%d", &A[i][j]);
	}
	scanf("%d", &k);
	flag=-1;
	i=m-1;
	j=0;
	while(j<n && i>0)
	{
		if(k==A[i][j])
		{
			flag=1;
			break;
		}
		else if (k<A[i][j])
			i--;
		else
		{
			j++;
		}
	}
	printf("%d", flag);
	return 0;
}