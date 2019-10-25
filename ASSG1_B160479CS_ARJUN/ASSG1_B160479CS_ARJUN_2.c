
#include<stdio.h>

//the main function of a c program
int main()
{
        FILE *iptr,*optr;
        iptr=fopen("in.txt","r");
        if(iptr==NULL)
                return 0;
        optr=fopen("out.txt","w");
        if(optr==NULL)
                return 0;
        char ch;
        int flag=0;
        while((ch=getc(iptr))!=EOF)
        {
                if(ch==' ')
                {
                        if(flag==0)
                        {
                                putc(ch,optr);
                                flag=1;
                        }
                }
                else if(ch=='\t')
				{
					if(flag==0)
					{
						putc(' ',optr);
						flag=1;
					}
				}
                else
                {
                        flag=0;
                        putc(ch,optr);
                }
        }
        fclose(iptr);
        fclose(optr);
        return 0;
}