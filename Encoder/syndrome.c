#include<stdio.h>
#include<stdlib.h>
#include "encode.c"
//extern int h[3][7];
int main()
{
encode();
int arr1[7][3],i,j,k;
int rec[1][7],syn[1][3];
char s1[7];
for(i=0;i<3;i++)
{
 for(j=0;j<7;j++)
  {
    arr1[j][i]=h[i][j];
  }
}
 printf("Give the received vector:");
 for(i=0;i<1;i++)
  {
    scanf("%s",s1);
    for(j=0;j<7;j++)
       rec[i][j]=s1[j]-'0';
  }
  for(i=0;i<1;i++)
  {
    for(j=0;j<3;j++)
    {
     syn[i][j]=0;
    }
  }
  for(i=0;i<1;i++)
   {
     for(j=0;j<3;j++)
      {
        for(k=0;k<7;k++)
        {
        syn[i][j]=syn[i][j]+(rec[i][k]*arr1[k][j]);
        }
      }
   }
   for(i=0;i<1;i++)
  {
    for(j=0;j<3;j++)
    {
     if((syn[i][j]>1&&syn[i][j]%2>0)||(syn[i][j]==1))
       {
         //syn[i][j]=syn[i][j]%2;
         printf("error in received vector\n");
         exit(0);
       }
    }
  }
  printf("No error\n");
}