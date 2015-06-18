#include "coding.h"
//integer to string
int i2s(int n,char s[])
{
  int l=0,i;
  if(n>=0 && n<10) l=1;
  else if(n>=10 && n<100) l=2;
  else if (n>=100&& n<1000)l=3;
  else if(n>=1000 && n<10000)l=4;
  else if(n>=10000 && n<100000)l=5;
  i=l;
  s[l+1]=0;
  s[l--]='.';

  while(l>=0)
    {
      s[l--]='0'+n%10;
      n/=10;
    }
  
  return i;
}
//double to string
void d2s(double d,char s[])
{
  int a=(int)d;
  int i=i2s(a,s);
  i++;
  //we know it has 2 places after the decimal point!
  d-=a*1.0;
  // printf("%.2f--%d..%d,",d,(int)d,a);
  d*=10;
  a=(int)d;
  //printf("%.2f--%d..%d,",d,(int)d,a);
  d-=a*1.0;
  d*=10; 
  s[i]='0'+a;
  a=(int)d;
  s[i+1]='0'+a;
  s[i+2]=0;   
  //printf("%.2f--%d..%d,",d,(int)d,a);
}

int main()
{
char s[1000],*command,*word1,*word2,*temp;
word1=(char *)calloc(100,sizeof(char));
word2=(char *)calloc(100,sizeof(char));
command=(char *)calloc(100,sizeof(char));
word1=" <out.txt";
command="./Channel ";
double count=0.1,d=0.01;
int i=1,f=1;
while(count<=10.1)
{
  
 d2s(count,word2);
 if(i==1)
   {
     temp=(char*)calloc(strlen(word2)+1,sizeof(char));
     temp=strcpy(temp,word2);
   }
 else
   {
     if(strcmp(temp,word2)==0)
         f=0;
     else 
          temp=strcpy(temp,word2);
   }
 
if(f){
 int j=0,cnt=0;
 for(j=0;j<strlen(command);j++)s[cnt++]=command[j];
 for(j=0;j<strlen(word2);j++)s[cnt++]=word2[j];
 for(j=0;j<strlen(word1);j++)s[cnt++]=word1[j];
 s[cnt++]=' ';s[cnt++]='>';s[cnt++]='f';
 i2s(i,word2);
 for(j=0;j<strlen(word2);j++)s[cnt++]=word2[j];
 s[cnt-1]=0;
 //printf("%s\n",s);
 i++;
 system(s);
}
 f=1;
 count+=d;
} 
return 0;
}
