/*Author: Ramit Das
* This code is a simple generic encoder for Convolution codes.
* It needs to be passed inputs of (n,k,m) - parameters of a Convolution Code.
* It also needs the Generator impulse sequences to be entered.
* It follows  SHU LIN’s notation G[i][j]= G<subscript i><superscript j>. 
* Please ensure the input data is correctly formatted as there is no error checking in this program.
* Then it gives the number of input vectors to be entered.
* Finally it takes all input codeword sequences. 
*/
#include "coding.h"
int		n         , k, m;
bit		G          [100][100][100];
//this function does the actual convolution encoding
//u contains the entered bit sequence and v the encoded bit sequence,L-u’s length
void 
Convolution(int L, bit u[], bit v[])
{
	int		a         , b, c, l;
	/*for (int i = 0; i < L; i++)
		printf("%d", u[i].b);
	printf("\n");
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) {
			printf("G[%d][%d]=", i + 1, j + 1);
			for (int k = 0; k <= m; k++)
				printf("%d", G[i][j][k].b);
			printf("\n");
		}
        
	*/
for (int i = 0; i < n * (L / k + m); i++)
       v[i].b=0;
	
        for (a = 0; a < n; a++)
		for (b = 0; b < k; b++)
			for (l = 0; l < L / k + m; l++) {
				//printf("\n-----------\n");
				for (c = 0; c <= m; c++) {
					if (l >= c && ((l - c) * k + b) < L) {
						v[n * l + a].b += u[(l - c) * k + b].b * G[b][a][c].b;
						//printf("v[%d]= u[%d] * G[%d][%d]\n", n * l + a, (l - c) * k + b, b, a);
						//printf("v[%d]=%d=%d*%d\n", n * l + a, v[n * l + a].b, u[(l - c) * k + b].b, G[b][a][c].b);
					}
				}
			}

}



int 
main(int argc, char *argv[])
{
	
		scanf("%d",&n);
                scanf("%d",&k);
		scanf("%d",&m);
		int		L         , l, t;
		
		//printf("(%d,%d,%d) Convolutional Code Encoder!\n", n, k, m);


		
		//generator impulses SHU LIN - Gij(i - subscript, j - superscript)
		for (int i = 0; i < k; i++) {
			//printf("For input %d the Convolution codes generator impulse sequences!\n", i + 1);
			for (int j = 0; j < n; j++) {
				//printf("Enter generator impulse sequence for OUTPUT:%d\n", j + 1);
				char s[1000000]={0};
				scanf("%s",s);
				getchar();
				for (int k = 0; k <= m; k++)
					G[i][j][k].b = s[k] - '0';
			}
		}


             	//entering the no. of input codewords
		scanf("%d",&t);
               	printf("%d\n",t); 
 		while(t--)
		{		

                //information sequence
		
                char s[1000000]={0};
                scanf("%s",s);getchar();
  		l=strlen(s);

		bit		infoseq    [L = (l + ((l % k) ? k - l % k : 0))];
		
		for (int i = 0; i < l; i++)
			infoseq[i].b = s[i] - '0';
	



		int		enc_length = n * (L / k + m);
		bit		encoded    [enc_length];
		Convolution(L, infoseq, encoded);
		//printf("\n");
		for (int i = 0; i < enc_length; i++)
			printf("%d", encoded[i].b);
		printf("\n");
		}
                return 0;	
}
