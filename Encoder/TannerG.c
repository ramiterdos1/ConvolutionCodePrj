#include <stdio.h>
#include <stdlib.h>
char [][] matmult(char a[][],char b[][],int ra,int ca,int rb,int cb)
{
  int ans[ra][cb]={0};
  int i=0,j=0,k=0;
  for(i=0;i<ra;i++)
    for(j=0;j<rb;j++)
       for(k=0;k<cb;k++)
          ans[i][k]^=(a[i][j]-'0')*(b[j][k]-'0');
  for(i=0;i<ra;i++)
  	for(j=0;j<cb;j++)
        ans[i][j]+='0';
  return ans;         
}
int main()
{
//G-generator matrix,H-parity check matrix,p-message bits
//c-final encoded codeword,y-received codeword, z-syndrome
char chk,G[7][4],p[4][1],c[7][1],y[7][1],H[3][7],z[3][1],i=0;
int iter; 
 
 //inputting the message
 printf("Give the msg:\n");
 scanf("%s[^\n]",p);
 //entering the generator matrix
 printf("Enter the Generator Matrix!\n");
  for(i=0;i<4;i++)
  {
    scanf("%s",s);
    for(j=0;j<7;j++)
       G[i][j]=s[j];
  }
  
  
 //getting the received message
 printf("Give the received msg:\n");
 scanf("%s[^\n]",y);
 chk='n';
 while(chk!='y')
 {
    printf("Run the iterations till?\n");
    scanf("%d\n",&iter);
    while(iter)
    {
      
    }
    
    printf("Do you want check further?");
    chk=getchar();getchar();
  }
}
