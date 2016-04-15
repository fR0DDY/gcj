#include<iostream>
using namespace std;

int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.out","w",stdout);
    int T,i,j,k,x,N,F;
    scanf("%d",&T);
    for (i=1;i<=T;i++)
    {
        scanf("%d",&N);
        x=N;
        int f[10];
        for (k=1;k<10;k++)
                f[k]=0;
        while (x>0)
        {
              f[x%10]++;
              x/=10;
        }
        for (j=N+1;;j++)
        {
            
            //printf("here\n");
            int f1[10];
            for (k=1;k<10;k++)
                f1[k]=0;
            x=j;
            while (x>0)
            {
                  f1[x%10]++;
                  x/=10;
            }
            F=1;
            for (k=1;k<10 && F==1;k++)
            {
                if (f[k]!=f1[k])
                   F=0;
            }
            if (F==1)
            {
                     printf("Case #%d: %d\n",i,j);
                     break;
            }
        }
    }
}
