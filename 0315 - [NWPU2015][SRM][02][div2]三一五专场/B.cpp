// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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

const char home[] = "http://www.acm.org/";
const char error[] = "Ignored";
string data[105];

int main()
{
	string cmd, url;
	int flag = 0, pos = 0, endpos = 0;
	data[pos] = home;
	while (flag == 0)
	{
		cin >> cmd;
		switch (cmd[0])
		{
			case 'B':
				if (pos == 0) puts(error);
				else
					puts(data[--pos].c_str());
				break;
			case 'F':
				if (pos == endpos) puts(error);
				else
					puts(data[++pos].c_str());
				break;
			case 'V':
				endpos = ++pos;
				cin >> data[pos];
				puts(data[pos].c_str());
				break;
			case 'Q':
				flag = 1; break;
		}
	}
}
