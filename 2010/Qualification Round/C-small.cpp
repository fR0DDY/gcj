#include<iostream>
using namespace std;

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    long long T,R,k,N,g[1000],Euros=0,i,j,s,gn,nor,c;
    scanf("%lld",&T);
    for (i=1;i<=T;i++)
    {
        scanf("%lld%lld%lld",&R,&k,&N);
        for (j=0;j<N;j++)
            scanf("%lld",&g[j]);
         
        Euros=0; 
        gn=0;    
        nor=0;
        do
        {
            nor++;
            s=0;
            c=0;
            while (c<N && s+g[gn%N]<=k)
            {
                  s+=g[gn%N];
                  gn++;   
                  c++;
            }
            Euros+=s;
        }while (nor<R && gn%N!=0);
        if (nor<R)
           Euros=Euros*(R/nor);
        for (j=(R/nor)*nor;j<R;j++)
        {
            c=0;
            s=0;
            while (c<N && s+g[gn%N]<=k)
            {
                  s+=g[gn%N];
                  gn++;   
                  c++;
            }
            Euros+=s;
        }
        printf("Case #%lld: %lld\n",i,Euros);
    }
}
