#include<stdio.h>

int main()
{
        int N,K,i,choice;
        //variables
        //printf("\n1.Encryption\n2.Decryption\n\n\tEnter your choice : ");
        scanf("%d",&choice);
        //printf("\nEnter string1 Length : ");
        scanf("%d",&N);
        char string1[N];
        //printf("\nEnter string1 : ");
        getchar();
       // scanf("%s",string1);
        gets(string1);
        //printf("\nEnter Key : ");
        scanf("%d",&K);
        switch(choice)
        {
          case 1:
                for(i=0;i<N;i++)
                {
                        if((string1[i]>64) && (string1[i]<91))
                        {
                                string1[i]+=K;
                                if(string1[i]>90)
                                        string1[i]=64+(string1[i]-90);
                        }
                        else if((string1[i]>96) && (string1[i]<123))
                        {
                                string1[i]+=K;
                                if(string1[i]>122)
                                        string1[i]=96+(string1[i]-122);
                        }
                }
                break;
          case 2:
                for(i=0;i<N;i++)
                {
                        if((string1[i]>64) && (string1[i]<91))
                        {
                                string1[i]-=K;
                                if(string1[i]<65)
                                        string1[i]=91-(65-string1[i]);
                        }
                        else if((string1[i]>96) && (string1[i]<123))
                        {
                                string1[i]-=K;
                                if(string1[i]<97)
                                        string1[i]=123-(97-string1[i]);
                        }
                }
                break;
          default:
                printf("\nERROR!!NO SUCH CHOICE!!EXITING!!");
        }
        for(i=0;i<N;i++)
                printf("%c",string1[i]);
        printf("\n");
        return 0;
}
         
