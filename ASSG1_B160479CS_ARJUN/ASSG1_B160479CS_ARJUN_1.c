#include<stdio.h>

int main()
{
        int N,K,i,choice;
        //variables
        //printf("\n1.Encryption\n2.Decryption\n\n\tEnter your choice : ");
        scanf("%d",&choice);
        //printf("\nEnter String Length : ");
        scanf("%d",&N);
        char string[N];
        //printf("\nEnter String : ");
        getchar();
       // scanf("%s",string);
        gets(string);
        //printf("\nEnter Key : ");
        scanf("%d",&K);
        switch(choice)
        {
          case 1:
                for(i=0;i<N;i++)
                {
                        if((string[i]>64) && (string[i]<91))
                        {
                                string[i]+=K;
                                if(string[i]>90)
                                        string[i]=64+(string[i]-90);
                        }
                        else if((string[i]>96) && (string[i]<123))
                        {
                                string[i]+=K;
                                if(string[i]>122)
                                        string[i]=96+(string[i]-122);
                        }
                }
                break;
          case 2:
                for(i=0;i<N;i++)
                {
                        if((string[i]>64) && (string[i]<91))
                        {
                                string[i]-=K;
                                if(string[i]<65)
                                        string[i]=91-(65-string[i]);
                        }
                        else if((string[i]>96) && (string[i]<123))
                        {
                                string[i]-=K;
                                if(string[i]<97)
                                        string[i]=123-(97-string[i]);
                        }
                }
                break;
          default:
                printf("\nERROR!!NO SUCH CHOICE!!EXITING!!");
        }
        for(i=0;i<N;i++)
                printf("%c",string[i]);
        printf("\n");
        return 0;
}
         
