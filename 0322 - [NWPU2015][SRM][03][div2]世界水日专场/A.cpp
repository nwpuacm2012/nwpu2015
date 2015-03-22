// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
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

int sticks[65];
bool used[65];
int n, sum, goal ;

inline bool cmp(const int& a, const int& b) { return a > b; }

bool dfs (int cur, int index, int cnt){
	if (cnt == sum / goal)
		return true;
	for (int i=index;i < n;i++){
		if (i && !used[i - 1] && (sticks[i] == sticks[i - 1])) continue; // opt4
		if (used[i]) continue;
		if (sticks[i] + cur > goal) continue;
		used[i] = true;
		if (sticks[i] + cur == goal)
		{
			if (dfs(0, 0, cnt + 1)) return true;
			used[i] = false;
			return false;
		}
		if (!dfs(cur + sticks[i], i + 1, cnt))
		{
			used[i]=false;
			if (cur == 0) return false;	//opt5
		}
		else return true;
	}
	return false;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		sum = goal = 0; 
		memset(sticks, 0, sizeof (sticks));
		for (int i = 0; i < n; i++)
		{
			sticks[i] = nextInt();
			sum += sticks[i];
		}
		sort(sticks, sticks + n, cmp); // opt1
		for (goal = sticks[0]; goal <= sum; goal++) // opt2
		{ 
			if (sum % goal != 0) continue; // opt3
			memset(used, 0, sizeof (used));
			if (dfs(0, 0, 0)) { printf("%d\n", goal); break; }
		}
	}
	return 0;
}