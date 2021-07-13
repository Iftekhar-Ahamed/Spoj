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

#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const int mXs = 10000000;
const double pi = acos(-1.0);
bool arra[mXs + 10];
lld solve[mXs + 10];
vector<int> prime;
int primefact(int n)
{
    int i, siz = prime.size();

    for (i = 0; i < siz; i++)
    {
        if (n % prime[i] == 0)
            return prime[i];
    }
    return 0;
}
void seive()
{
    int i, j;
    memset(arra, true, sizeof(arra));

    for (i = 4; i <= mXs; i += 2)
    {
        arra[i] = false;
    }
    int siz=sqrt(mXs);
    for (i = 3; i <= siz; i+=2)
    {
        if (arra[i])
        {
            for (j = i * i; j <= mXs; j += (i + i))
            {
                arra[j] = false;
            }
        }
    }
    prime.push_back(2);
    for (i = 3; i <= mXs; i += 2)
    {
        if (arra[i])
        {
            prime.push_back(i);
        }
    }

    solve[0] = solve[1] = 0;
    for (i = 2; i <= mXs; i++)
    {
        if (arra[i])
        {
            solve[i] = solve[i - 1] +i;
        }
        else
        {
            solve[i] = solve[i - 1] + primefact(i);
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
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << solve[x] << endl;
    }
    return 0;
}
