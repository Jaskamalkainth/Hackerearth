/*
 *    J1K7_7
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <list>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef long double        ld;
typedef pair<int,int>      pii;
typedef pair<ll,ll>        pll;
typedef vector<int>        vi;
typedef vector<long long>  vll;
#define left(x) 		   (x << 1)
#define right(x) 		   (x << 1) + 1
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z)    {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w<<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))

const int mod=1e9+7;

template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T, typename S> T expo(T b, S e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T> T modinv(T a) { return expo(a, mod-2, mod); }

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  =1000000009;
const long double PI = (long double)(3.1415926535897932384626433832795);


const int maxn = 1e5+7;
vector<int> g[maxn];

int n;
int dist[2][maxn];
inline void bfs(int id,int src ) 
{
	for(int i = 1; i <= n; i++)
		dist[id][i] = mx_int;
	dist[id][src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int top  = q.front();
		q.pop();
		for(auto &v: g[top])
		{
			if(dist[id][v] == mx_int)
			{
				dist[id][v] = dist[id][top]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int  m , k; 
	cin >> n >> m >> k;
	while(m--)
	{
		int u , v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int m1,m2; cin >> m1 >> m2;

	bfs(0,m1);
	bfs(1,m2);
	int ans = 0;
	int q; cin >> q;
	while(q--)
	{
		int n1, n2;
		cin >> n1 >> n2;
		if(dist[0][n1] <= k && dist[1][n2] <= k && dist[0][m2] != mx_int)
			ans++;
	}
	cout << ans << "\n";



    return 0;
}

