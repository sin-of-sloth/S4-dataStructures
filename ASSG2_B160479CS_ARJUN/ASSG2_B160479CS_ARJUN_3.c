
#include <stdio.h>

int heapSize, n;

void heapify(int* A, int i)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest;

  if(l <= heapSize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if(r <= heapSize && A[r] > A[largest])
    largest = r;
  if(largest != i)
    {
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      heapify(A, largest);
    }
}

void buildMaxHeap(int* A)
{
  heapSize = n - 1;
  int i;
  for(i = (n - 1) / 2; i >= 0; i--)
    heapify(A, i);
}

void heapSort(int* A, int k)
{
  buildMaxHeap(A);
  int i;
  for(i=0; i<k; i++)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      heapify(A, 0);
    }
    printf("%d", A[n-k]);
}

int main()
{
   int i, k;
  scanf("%d", &n);
  int A[n];
  heapSize=n-1;
  for(i=0;i<n;i++)
  	scanf("%d", &A[i]);
  scanf("%d", &k);
  heapSort(A, k);
  return 0;
}