#include<stdio.h>


void merge(int array[], int l, int m, int r)
{
  int i, j, k, left[m-l+1], right[r-m];
  for(i=0;i<m-l+1;i++)
    {
      left[i]=array[l+i];
    }
  for(i=0;i<r-m;i++)
    {
      right[i]=array[m+1+i];
    }
  i=0;
  j=0;
  k=l;
  while(i<m-l+1 && j<r-m)
  {
    if(left[i]<right[j])
    {
      array[k]=left[i];
      i++;
    }
    else
    {
     array[k]=right[j];
     j++;
    }
    k++;
  }
  while(i<m-l+1)
  {
    array[k]=left[i];
    i++;
    k++;
  }
  while(j<r-m)
  {
    array[k]=right[j];
    j++;
    k++;
  }
}


void mergeSort(int array[], int l, int r)
{
  if(l<r)
  {
    int m = (l+r)/2;
    mergeSort(array, l, m);
    mergeSort(array, m+1, r);
    merge(array, l, m, r);
  }
}


int main()
{
  int n,i,array[20];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&array[i]);
  mergeSort(array,0,n-1);
  for(i=0;i<n;i++)
    printf("%d ",array[i]);
  return 0;
}