#include<stdio.h>

int main()
{
	FILE *reader=fopen("out","rb");
	long int size;
	fseek(reader, 0, SEEK_END);
	size=ftell(reader);
	fseek(reader, 0, SEEK_SET);
	int k;
	while(ftell(reader)!=size)
	{
		fread(&k, sizeof(int), 1, reader);
		printf("%d ", k);
	}
	fclose(reader);
	return 0;
}