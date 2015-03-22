// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
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

// node  := pair< name, level >
// graph := map< node >
map< string, int > graph;
const string root = "polycarp";

int main()
{
	graph[root] = 1;
	int n = nextInt();
	int res = 2;
	while (n--)
	{
		string ch, cmd, fa;
		cin >> ch >> cmd >> fa;
		transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
		transform(fa.begin(), fa.end(), fa.begin(), ::tolower);
		graph[ch] = graph[fa] + 1;
		updateMax(res, graph[ch]);
	}
	printf("%d\n", res);
}
