#include"coding.h"
#define MAX (UINT_MAX-17)
int codelen;
double snr,sigma;
void computeSigma(double d)
{
  sigma=sqrt(pow(10,-snr/10));
  //printf("%f\n",sigma);
}
void convertS2F(double *d,char *s)
{
  int i=1,l=strlen(s),val=s[0]-'0';
  double v=0,p=0.1; 
  while(s[i]!='.')
   {
    val=(val*10)+(s[i]-'0');
    i++; 
   }
  i++;
  while(i<l)
   {
     v+=(s[i]-'0')*p;
     p/=10.0;
     i++;
   }
  *d=val*1.0+v;
}

void BFSK(char s[],double d[])
{
  for(int i=0;i<codelen;i++)
    {
     if(s[i]=='1')d[i]=1.0;
     if(s[i]=='0')d[i]=-1.0;
    }
}
double wNoise()
{ 
   //Marsaglia polar method

   double x,y,s,noise;
   do{
   	x=((rand()/(double)MAX)*2.0)-1;
   	y=((rand()/(double)MAX)*2.0)-1;
   	s=x*x+y*y;
      }while(s>=1);
   
   noise=x*sqrt(-2*log(s)/s);
   return noise; 
}
void rcvCode(double d[])
{
  int i=0;
  
  for(;i<codelen;i++)
     {
       d[i]+=sigma*wNoise();
       printf("%c",d[i]>0?'1':'0');
     }
   printf("\n");
}

int main(int argc,char* argv[])
{
if(argc==2)
{
snr=0;
convertS2F(&snr,argv[1]);
printf("%f\n",snr);
computeSigma(snr);

int t;
char code[100000];
double modulatedcode[100000];
scanf("%d",&t);
printf("%d\n",t);
while(t--)
   {
    
    scanf("%s",code);
    codelen=strlen(code);
    BFSK(code,modulatedcode);
    rcvCode(modulatedcode);
   }

}
else printf("Wrong Input Format!!\n");
return 0;
}
