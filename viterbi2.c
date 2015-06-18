#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct state
{
 int arr[2][2];
};
struct state states[8];
int bitXor(char a[],struct state states[],int n,int k)
{
 int i,j,diff=0;
 int check[2];
  //num1 = strlen(s);
  //printf("%d",num1);
   for(i=0;i<2;i++)
   {
    check[i]=a[i]-'0';
   }
  /* for(i=0;i<2;i++)
   {
    printf("%d",check[i]);
   }*/
  //printf("%d\n",n);
 for(i=0;i<2;i++)
 {
  j= check[i] & states[n].arr[k][i];
 // printf("%d ",j);
  if(j==0 && (check[i]!=states[n].arr[k][i]))
    {
     diff=diff+1;
    }
 }
 //printf("\n");
 //printf("%d\n",diff);
 return diff;
}
int main()
{
 
 
 double snr;
 scanf("%lf",&snr);
 printf("%lf\n",snr);
 
 
  int T;
  scanf("%d",&T);
  printf("%d\n",T); 
  while(T--)  
  {
  
 

int mesg[10],t,i,pair,num1,b,c,j,num2=0;;
 char s[2];
 char length[20];
 int check[2];
 static int num=0;
 for(i=0;i<10;i++)
  {
   mesg[i]=0;
  }
 t=0;
 states[0].arr[0][0]= 0;
 states[0].arr[0][1]= 0;
 states[0].arr[1][0]= 1;
 states[0].arr[1][1]= 1;
 states[1].arr[0][0]= 0;
 states[1].arr[0][1]= 1;
 states[1].arr[1][0]= 1;
 states[1].arr[1][1]= 0;
 states[2].arr[0][0]= 1;
 states[2].arr[0][1]= 1;
 states[2].arr[1][0]= 0;
 states[2].arr[1][1]= 0;
 states[3].arr[0][0]= 1;
 states[3].arr[0][1]= 0;
 states[3].arr[1][0]= 0;
 states[3].arr[1][1]= 1;
 states[4].arr[0][0]= 1;
 states[4].arr[0][1]= 1;
 states[4].arr[1][0]= 0;
 states[4].arr[1][1]= 0;
 states[5].arr[0][0]= 1;
 states[5].arr[0][1]= 0;
 states[5].arr[1][0]= 0;
 states[5].arr[1][1]= 0; 
 states[6].arr[0][0]= 0;
 states[6].arr[0][1]= 0;
 states[6].arr[1][0]= 1;
 states[6].arr[1][1]= 1;
 states[7].arr[0][0]= 0;
 states[7].arr[0][1]= 1;
 states[7].arr[1][0]= 1;
 states[7].arr[1][1]= 0;

   scanf("%s",length);
 


  //gets(str);
 //printf("%s",length);
 pair=(strlen(length)/2);
 //printf("%d\n",pair);
 for(i=0,j=0;i<pair;i++,j=j+2)
 {
  s[0]=length[j];
  s[1]=length[j+1];
  //printf("%s\n",s);
  //strncpy(s,length[j],length[j+1]);
  //scanf("%s",s);
   /*num1 = strlen(s);
  //printf("%d",num1);
   for(i=0;i<num1;i++)
   {
    check[i]=s[i]-'0';
   }*/
   //printf("%d\n",pair);
 //int *p = &num;
 num=num2;
 b= bitXor(s,states,num,0); 
 c=bitXor(s,states,num,1);
 //printf("%d\n",num);
   if(b<c)
    {
     mesg[t]=0;
     //printf("%d\n",mesg[t]);
     t=t+1;
      if(num==0)
       {
        num2=num+0;
        
       }
      if(num==1)
       {
        num2=num+1;
        
       }
      if(num==2)
       {
        num2=num+2;
        
       }
      if(num==3)
       {
        num2=num+3;
        
       }
      if(num==4)
       {
        num2=num-4;
        
       }
      if(num==5)
       {
        num2=num-3;
        
       }
      if(num==6)
       {
        num2=num-2;
        
       }
      if(num==7)
       {
        num2=num-1;
        
       }
         
    }
    else
     {
      mesg[t]=1;
      //printf("%d\n",mesg[t]);
      t=t+1;
      if(num==0)
       {
        num2=num+1;
        
       }
      if(num==1)
       {
        num2=num+2;
        
       }
      if(num==2)
       {
        num2=num+3;
        
       }
      if(num==3)
       {
        num2=num+4;
        
       }
      if(num==4)
       {
        num2=num-3;
        
       }
      if(num==5)
       {
        num2=num-2;
        
       }
      if(num==6)
       {
        num2=num-1;
        
       }
      if(num==7)
        {
         num2=num-0;
        
        }
     }
 
 }
 //printf("The message word is - ");
 for(i=0;i<t-3;i++)
 {
  printf("%d",mesg[i]);
 }
  printf("\n");
 
 }
return 0;
}
