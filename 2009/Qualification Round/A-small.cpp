#include<iostream>
using namespace std;

int main()
{
    freopen("A1.in","r",stdin);
    freopen("output1.txt","w",stdout);
    char dic[100][100],str[1000];
    int l,d,n;
    scanf("%d%d%d\n",&l,&d,&n);
    int i,j,k,m,ctr,F;
    
    for (i=0;i<d;i++)
    {
        gets(dic[i]);
    }
    for (i=0;i<n;i++)
    {
        gets(str);
        ctr=0;
        for (j=0;j<d;j++)
        {
            F=1;
            for (k=0,m=0;k<l && F==1;k++,m++)
            {
                F=0;
                //printf("Checking %c\n",dic[j][k]);
                if (str[m]=='(')
                {
                   m++;
                   while (str[m]!=')')
                   {
                        if (str[m]==dic[j][k])
                           F=1; 
                        m++;
                   }
                }
                else if (str[m]==dic[j][k])
                     F=1;
            }
            if (F==1)
               ctr++;
            //cout<<str<<"  "<<dic[j]<<"  "<<F<<"  "<<ctr<<endl;
        }
        printf("Case #%d: %d\n",i+1,ctr);
    }
}
