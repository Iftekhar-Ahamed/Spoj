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
typedef unsigned long long int LL;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const int mXs = 1e8;
const double pi = acos(-1.0);
bool arra[mXs + 1];
vector<LL> prime;
int solve[mXs + 1];
LL ans[50][2];
void primefact(LL n, lld &s)
{
    int i, siz = prime.size(), count = 0;
    bool flag = false;

    for (i = 0; i < siz && prime[i]*prime[i]<=n && n!=1; i++)
    {
        if (n % prime[i] == 0)
        {
            ans[s][0] = prime[i];
            ans[s][1] = 0;
            while (n % prime[i] == 0)
                n /= prime[i], ans[s][1]++;
            s++;
        }
    }
    if (n != 1)
    {
        ans[s][0] = n;
        ans[s][1] = 1;
        s++;
    }
}
void seive()
{
    lld i, j;
    memset(arra, true, sizeof(arra));

    for (i = 4; i <= mXs; i += 2)
    {
        arra[i] = false;
    }

    for (i = 3; i * i <= mXs; i++)
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
}

int main()
{
    cin.tie(NULL);
    //read
    //write
    ios_base::sync_with_stdio(false);
    seive();
    //cout<<prime[prime.size()-1]<<endl;
    lld  s, i;
    LL n;
    while (cin >> n && n != 0)
    {
        s = 0;
        primefact(n, s);
        for (i = 0; i < s; i++)
            cout << ans[i][0] << "^" << ans[i][1] << " ";
        cout << endl;
    }

    return 0;
}
