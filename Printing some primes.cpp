/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const int mXs=1e8;
const double pi = acos(-1.0);
bool arra[mXs+1];

void seive()
{
    lld i,j;
    memset(arra,true,sizeof(arra));

    for(i=4; i<mXs; i+=2)
    {
        arra[i]=false;
    }

    for(i=3; i*i<=mXs; i++)
    {
        if(arra[i])
        {
            for(j=i*i; j<=mXs; j+=(i+i))
            {
                arra[j]=false;
            }
        }
    }
    cout<<2<<"\n";
    lld n=1;
    for(i=3; i<=mXs; i+=2)
    {
        if(arra[i])
        {
            n++;
            if(n%100==1)
            {
                cout<<i<<"\n";
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    //read;
    //write;
    ios_base::sync_with_stdio(false);
    seive();
    return 0;
}
