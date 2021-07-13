/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <stdio.h>
int gcd(int x,int y)
{

    if(x==0)
        return y;
    return gcd(y%x,x);
}
int solve()
{
    int x,y,cnt=0;
    scanf("%d%d",&x,&y);
    int n = gcd(x,y);
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                cnt+=1;
            else
                cnt+=2;
        }
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        printf("%d\n",solve());
    }
    return 0;
}
