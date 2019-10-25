//Question 3 A
#include<stdio.h>
#include<stdlib.h>

void reverse(char string[],int len,int i);

int main()
{
  char *string = (char*) malloc(1000*sizeof(char));
  int i,len=0;
  //printf("Enter the string:");
  gets(string);
  for(i=0;string[i]!='\0';i++)
    len++;
  reverse(string,len-1+(len%2),0);
  for(i=1;i<=len;i++)
    printf("%c",string[i]);
  printf("\n");
  return 0;
}

void reverse(char string[],int len,int i)
{
  if(i>len/2)
    return;
  else
    {
     string[i]+=string[len-i];
     string[len-i]=string[i]-string[len-i];
     string[i]-=string[len-i];
     reverse(string,len,++i);
    }
}
