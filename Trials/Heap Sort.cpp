//Program to perform heap sort on an array of integers

#include <stdio.h>

int heapSize, LENGTH;

void Heapify(int* A, int i)
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
      Heapify(A, largest);
    }
}

void BuildHeap(int* A)
{
  heapSize = LENGTH - 1;
  int i;
  for(i = (LENGTH - 1) / 2; i >= 0; i--)
    Heapify(A, i);
}

void HeapSort(int* A)
{
  BuildHeap(A);
  int i;
  for(i=0; i< LENGTH; i++)
    {
      int temp = A[heapSize];
      A[heapSize] = A[0];
      A[0] = temp;
      heapSize--;
      Heapify(A, 0);
    }
}

int main()
{
   int i;
  scanf("%d", &LENGTH);
  int tab[LENGTH];
  heapSize=LENGTH-1;
  for(i=0;i<LENGTH;i++)
  	scanf("%d", &tab[i]);
  HeapSort(tab);
  for(i=0;i<LENGTH;i++)
  	printf("%d ", tab[i]);
  return 0;
}