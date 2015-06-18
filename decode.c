/*
* ./decode <no_of_files> <name_of_decoding_code> 
*eg,
*./decode 99 viterbi
*/
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
  s[l--]=0;
  

  while(l>=0)
    {
      s[l--]='0'+n%10;
      n/=10;
    }
  
  return i;
}

int main(int argc, char *argv[])
{
  if(argc==3)
   {
     int cnt=2,i=0,n=atoi(argv[1]),j=1;
     char s[1000],word[100];
       s[0]='.';
       s[1]='/';
     while(j<=n)
     {
       cnt=2;
       for(i=0;i<strlen(argv[2]);i++)s[cnt++]=argv[2][i];
       s[cnt++]=' ';s[cnt++]='<';s[cnt++]='f';
       i2s(j,word);
       for(i=0;i<strlen(word);i++)s[cnt++]=word[i];
       s[cnt++]=' ';s[cnt++]='>';s[cnt++]='o';
       i2s(j,word);
       for(i=0;i<strlen(word);i++)s[cnt++]=word[i];
       //printf("%s\n",s);
       j++;
       system(s); 
     }
  }
else printf("Wrong Input Format!!\n");
return 0;
}
