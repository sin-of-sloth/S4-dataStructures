#include<stdio.h>
#include<stdlib.h>
struct Ratio
{
  int x;
  int y;
};

void print(struct Ratio rat);
struct Ratio simplify(struct Ratio rat);
void sort(struct Ratio rats[], int size);

int main()
{
  int choice;
  printf("\n1. Print a/b form\n2. Sum of Rational numbers\n3. Product of Rational numbers\n4. Sort in ascending order\n5. Print in Simplest form\n\nChoose your option : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
     {
      struct Ratio rat1;
      //printf("\nEnter a and b : ");
      scanf("%d %d", &rat1.x, &rat1.y);
      print(rat1);
      printf("\n");
      break;
     }
    case 2:
      {
       struct Ratio num1,num2,sum;
       //printf("\nEnter number 1 (a and b) : ");
       scanf("%d %d", &num1.x, &num1.y);
       //printf("\nEnter number 2 (a and b) : ");
       scanf("%d %d", &num2.x, &num2.y);
       sum.x=(num1.x*num2.y)+(num2.x*num1.y);
       sum.y=num1.y*num2.y;
       print(simplify(sum));
       printf("\n");
       break;
      }
    case 3:
     {
      struct Ratio num1,num2,prod;
      //printf("\nEnter number 1 (a and b) : ");
      scanf("%d %d", &num1.x, &num1.y);
      //printf("\nEnter number 2 (a and b) : ");
      scanf("%d %d", &num2.x, &num2.y);
      prod.x=num1.x*num2.x;
      prod.y=num1.y*num2.y;
      print(simplify(prod));
      printf("\n");
      break;
     }
    case 4:
     {
      int n,i;
      //printf("\nEnter the number of rational numbers to be sorted : ");
      scanf("%d",&n);
      struct Ratio *rats = (struct Ratio*) malloc(100 * sizeof(struct Ratio));
      //struct Ratio rats[n];
      //printf("\nEnter the rational numbers :");
      for(i=0;i<n;i++)
      {
        //printf("\nEnter in the form a b:");
        scanf("%d %d", &rats[i].x, &rats[i].y);
      }
      sort(rats,n);
      printf("\n");
      break;
     }
    case 5:
     {
      struct Ratio rat;
      //printf("\nEnter a and b : ");
      scanf("%d %d", &rat.x, &rat.y);
      print(simplify(rat));
      printf("\n");
      break;
     }
    default:
      printf("\nNO SUCH CHOICE!!ABORTING!!!\n");
      break;
  }
  return 0;
}

void print(struct Ratio rat)
{
	int mul=1;
	if(rat.y<0)
		mul=mul*(-1);
  printf("%d/%d ", (rat.x*mul), (rat.y*mul));
}

struct Ratio simplify(struct Ratio rat)
{
  int i=1,hcf;
  while((i<=rat.x) || (i<=rat.y))
  {
    if((rat.x%i==0) && (rat.y%i==0))
      hcf=i;
    i++;
  }
  rat.x/=hcf;
  rat.y/=hcf;
  return rat;
}

void sort(struct Ratio rats[], int n)
{
  int i,j;
  struct Ratio temp;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if((rats[i].x*rats[j].y)>(rats[j].x*rats[i].y))
      {
        temp=rats[i];
        rats[i]=rats[j];
        rats[j]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
        print(rats[i]);
}