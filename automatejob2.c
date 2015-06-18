/*
* Author : Ramit Das
* ./automatejob2 <name_of_input_file> <max_no_of_output_files>
* input file - the file that contains the original pre-encoded information sequence.
* output files - the files containing the decoded informations thatwent through the awgn channel.
* it is assumed output files are of the form 'o<number>' 
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


int main(int argc,char *argv[])
{
  if(argc==3)
   {
    int i=1,n=atoi(argv[2]),cnt=0,j=0;
    char s[1000],word[100];
    char *w1="./Ber_Snr ";
   //change this filename to store multiple results
    char *w2=">>Results.csv";
    while(i<=n)
    {
      for(j=0;j<strlen(w1);j++)s[cnt++]=w1[j];
      for(j=0;j<strlen(argv[1]);j++)s[cnt++]=argv[1][j];
      s[cnt++]=' ';s[cnt++]='o';
      i2s(i,word);
      for(j=0;j<strlen(word);j++)s[cnt++]=word[j];
      s[cnt++]=' ';
      for(j=0;j<strlen(w2);j++)s[cnt++]=w2[j];
      s[cnt]=0;
      //printf("%s\n",s);
      system(s);
      cnt=0; i++;    
    }   
   }
  else printf("Wrong format of input!\n");
}
