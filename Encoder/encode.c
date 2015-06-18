#include<stdio.h>
#include<stdlib.h>
int h[3][7];
 
int encode()
{
 int msg,num[4],rem[4],generator[4][7],r1[4][3],r2[3][3],transpose[3][4];
 int i,div,code[7],j;
 char s[7];
 printf("Give the mesg:\n");
 scanf("%d",&msg);
 for(i=3;i>0;i--)
  {
   rem[i]=msg%10;
   msg=msg/10;
  }
  rem[i]=msg;
  /*for(j=0;j<4;j++)
    {
     printf("%d\n",rem[j]);
    }*/
 /*printf("Give the generator polynomial\n");
 for(i=0;i<4;i++)
  {
    for(j=0;j<7;j++)
      { 
        printf("generator[%d][%d] = ",i,j);
        scanf("%d",&generator[i][j]);
      }
     //printf("\n");
  }*/
  printf("Enter the Generator Matrix!\n");
  for(i=0;i<4;i++)
  {
    scanf("%s",s);
    for(j=0;j<7;j++)
       generator[i][j]=s[j]-'0';
  }
 code[0]=(((generator[0][0]*rem[0])+(generator[1][0]*rem[1])+(generator[2][0]*rem[2])+(generator[3][0]*rem[3]))%2);
 code[1]=(((generator[0][1]*rem[0])+(generator[1][1]*rem[1])+(generator[2][1]*rem[2])+(generator[3][1]*rem[3]))%2);
 code[2]=(((generator[0][2]*rem[1])+(generator[1][2]*rem[1])+(generator[2][2]*rem[2])+(generator[3][2]*rem[3]))%2);
 code[3]=rem[0];
 code[4]=rem[1];
 code[5]=rem[2];
 code[6]=rem[3];
printf("The corresponding code word is:\n-----------------------------\n");
 for(i=0;i<7;i++)
{
   {
     printf("%d",code[i]);
   }
 //printf("\n");
}
for(i=0;i<4;i++)
{
 for(j=0;j<3;j++)
  {
    r1[i][j]=generator[i][j];
  }
}
for(i=0;i<4;i++)
{
 for(j=0;j<3;j++)
  {
    transpose[j][i]=r1[i][j];
  }
}
printf("\n-----------------------------\nTranspose of P matrix is--\n");
for(i=0;i<3;i++)
{
  for(j=0;j<4;j++)
  {
   printf("%d ",transpose[i][j]);
  }
  printf("\n");
}
for(i=0;i<3;i++)
{
 for(j=0;j<3;j++)
  {
   r2[i][j]=0;
  }
}
for(i=0,j=0;j<3;i++,j++)
{
 r2[i][j]=1;
}
for(i=0;i<3;i++)
{
 for(j=0;j<3;j++)
  {
   h[i][j]=r2[i][j];
  }
 for(j=3;j<7;j++)
  {
   h[i][j]=transpose[i][j-3];
  }
}
printf("The parity Check Matrix is--\n");
for(i=0;i<3;i++)
{
 for(j=0;j<7;j++)
  {
    printf("%d ",h[i][j]);
  }
  printf("\n");
}
return 0;
}

