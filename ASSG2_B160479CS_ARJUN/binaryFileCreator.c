#include<stdio.h>

int main()
{
	FILE *ptr=fopen("in","wb");
	int i, A[15]={24, 33, 56, 7, 119, 0, -23, -100, 100002, 999, 11119, 78, 23, 109, 19};
	for(i=0;i<15;i++)
		fwrite(&A[i], sizeof(int), 1, ptr );
	fclose(ptr);
	return 0;
}