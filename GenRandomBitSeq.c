#include "coding.h"

int main(int argc, char *argv[])
{
if(argc==3)
{
int l=atoi(argv[1]),n=0;
n=atoi(argv[2]);
if(l>0&&n>0)
  {
   printf("%d\n",l);
   char b[n+1];
   for(int i=0;i<l;i++)
    { for(int j=0;j<n;j++)
        b[j]=((rand()%1000)&1)+'0';
        b[n]=0;
        printf("%s\n",b);
     }
  }
else goto WF;
}
else
WF: printf("Wrong format!\n");
return 0;
}
