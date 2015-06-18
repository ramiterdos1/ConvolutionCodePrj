#include "coding.h"

int main(int argc, char *argv[])
{
FILE *f1,*f2;
if(argc==3)
{
  f1=fopen(argv[1],"r");f2=fopen(argv[2],"r");
  if(f1!=NULL && f2!=NULL)
    {
      int n,n1;double snr;
      fscanf(f2,"%lf",&snr);
      fscanf(f2,"%d",&n1);
      fscanf(f1,"%d",&n);
      if(n==n1)
       {
         int err=0,tot=0,l=0;
         double ber=0;
         printf("%lf,",snr);
         while(n--)
          {
            char s1[1000000],s2[1000000];
            fscanf(f1,"%s",s1);fscanf(f2,"%s",s2);
            if(strlen(s1)==strlen(s2))
              {
                 l=strlen(s1);
                 tot+=l;
                 for(int x=0;x<l;x++)
                    err+=(s1[x]^s2[x]);
              }
            else {printf("Wrong Files!!!\n");exit(0);}
            
          }
         ber=err/(tot*1.0);
         printf("%lf\n",ber); 
       }
      else {printf("Wrong Files!!\n");exit(0);} 
    }
  else
   printf("One of the files couldn't be opened or doesn't exist!\n");
}
else printf("Wrong format of input!!\n");
return 0;
}
