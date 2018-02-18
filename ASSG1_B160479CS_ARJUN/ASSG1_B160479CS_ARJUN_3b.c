#include<stdio.h>

#define MAX 100

void transpose(int array[][100],int i,int r);

int main()
{
  int array[MAX][MAX],n,r,c,i,j,k;
  //printf("Enter the order of the matrix:");
  scanf("%d",&r);
  c=r;
  //printf("Enter the elements:\n");
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      scanf("%d",&array[i][j]);
  printf("\n");
  transpose(array,0,r-1);
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
      printf("%d ",array[i][j]);
    printf("\n");
  }
  printf("\n");

  r-=1;
  c-=1;
  i=0;
  j=0;
  while((i<=r) && (j<=c))
  {
    //First row
    k=j;
    while(k<=c)
    {
        printf("%d ",array[i][k]);
        k++;
    }
    i++;
    //Last column

    k=i;
    while(k<=r)
    {
        printf("%d ",array[k][c]);
        k++;
    }
    c--;

    //Last row
    if(i<r)
    {
        k=c;
        while(k>=j)
        {
                printf("%d ",array[r][k]);
                k--;
        }
        r--;
    }

    //First column
    if(j<c)
    {
        k=r;
        while(k>=i)
        {
                printf("%d ",array[k][j]);
                k--;
        }
        j++;
    }
  }
  printf("\n");
  return 0;
}

void transpose(int array[][100],int i,int r)
{
  if(i<=r)
  {
  		int j;
        for(j=0;j<i;j++)
        {
          int temp=array[i][j];
          array[i][j]=array[j][i];
          array[j][i]=temp;
        }
        transpose(array,i+1,r);
        
  }
}

  