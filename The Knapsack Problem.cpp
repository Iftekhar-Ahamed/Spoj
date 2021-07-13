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

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long
#define INF (int)1e9
#define EPS -1e9

#define mXs 2010
const double pi = acos(-1.0);
lld mem[mXs][mXs];
vector<vector<lld>> takeinput(lld n)
{
    lld x, y;
    vector<vector<lld>> data(2);
    while (n--)
    {
        scanf("%lld%lld",&x,&y);
        data[0].push_back(x);
        data[1].push_back(y);
    }
    return data;
}
lld maxprofit(vector<vector<lld>> &data, lld i, lld n, lld weight)
{
    if (weight < 0)
    {
        return -data[1][i - 1];
    }
    else if (i == n)
    {
        return 0;
    }
    // lld ans1=maxprofit(data, i + 1, n, weight - data[0][i])+ data[1][i];
    // lld ans2=maxprofit(data, i + 1, n, weight);
    // lld f=max(ans1,ans2);
    // return f;
    if (mem[i][weight] != -1)
    {
        return mem[i][weight];
    }
    mem[i][weight] = max(maxprofit(data, i + 1, n, weight - data[0][i]) + data[1][i], maxprofit(data, i + 1, n, weight));
    return mem[i][weight];
}
int main()
{
//    freopen("input.txt", "r", stdin);

    lld n, weight;
    while(2==scanf("%lld%lld",&weight,&n))
    {
    	memset(mem, -1, sizeof(mem));
    	vector<vector<lld>> data = takeinput(n);
    	cout << maxprofit(data, 0, n, weight) << endl;
    }
    
    return 0;
}
