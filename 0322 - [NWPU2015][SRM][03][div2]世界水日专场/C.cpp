// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   C                                                        *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

// #include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 115;
bool dp[46000][MaxN];
int w[MaxN], n;

void solve()
{
	int sum = 0, r = (n + 1) >> 1;
	for (int i = 0; i < n; i++)
	{
		w[i] = nextInt();
		sum += w[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = sum / 2; j >= w[i]; j--)
			for (int k = r; k >= 1; k--)
				if (dp[j - w[i]][k - 1] == 1)
					dp[j][k] = 1;
	int ans = 0;
	for (int i = sum / 2; i > 0; i--)
	{
		if (n % 2 == 0)
		{
			if (dp[i][r] == 1)
			{
				ans = i; break;
			}
		}
		else
		{
			if (dp[i][r] == 1 || dp[i][r - 1] == 1)
			{
				ans = i; break;
			}
		}
	}
	printf("%d %d\n", ans, sum - ans);
}

int main()
{
    while (~scanf("%d", &n)) solve();
	return 0 ;
}
