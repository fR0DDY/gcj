#include<iostream>
using namespace std;

int main()
{
    
    freopen("input5.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,S,Q,FLAG[11],ctr,C,i,j,k,Counter=0;
    char strS[11][110],strQ[101][101];
    scanf("%d",&N);
    while (N)
    {
          C=0;
          Counter++;
          scanf("%d\n",&S);
          for (i=0;i<S;i++)
          {
              gets(strS[i]);
              scanf("\n");
              //printf("%s\n",strS[i]);
          }
          for (k=0;k<S;k++)
              FLAG[k]=0;
          scanf("%d\n",&Q);
          for (i=0;i<Q;i++)
          {
              gets(strQ[i]);
              scanf("\n");
              //printf("%s\n",strQ[i]);
          }
          ctr=0;
          for (i=0;i<Q;i++)
          {
              //printf("%s\n",strS[i]);
              for (j=0;j<S;j++)
              {
                  //printf("%s\n",strQ[j]);
                  if(strcmp(strS[j],strQ[i])==0 && FLAG[j]==0)
                  {
                                             //printf("%s\n",strS[i]);   
                                             ctr++;
                                             FLAG[j]=1;
                  }
                  if (ctr==S)
                  {
                               ctr=1;
                               C++;
                               for (k=0;k<S;k++)
                                   FLAG[k]=0;
                               FLAG[j]=1;
                  }
              }
          }       
          printf("Case #%d: %d\n",Counter,C==0?0:C);
          N--;  
    }
}
