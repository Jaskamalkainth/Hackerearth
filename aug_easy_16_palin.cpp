/*
 *    J1K7_7
 *
 *    You can use my contents on a Creative Commons - Attribution 4.0 International - CC BY 4.0 License.  XD 
 *    - JASKAMAL KAINTH
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
#include <cassert>
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
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w << " = " <<w <<"\n";}
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
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);


const int MAXN = 100500;

struct node {
    int next[26];
    int len;
    int sufflink;
    int num, l, r;
};

//int len;
char s[MAXN];
node tree[MAXN]; 
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;
vector<int> adj[ MAXN ];
vector<pair<pair<int,int> , int > > A;
bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])     
            break;  
        cur = tree[cur].sufflink;
    }       
    if (tree[cur].next[let]) {  
        suff = tree[cur].next[let];
        tree[suff].num ++;
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[num].r = pos;
    tree[num].l = pos - tree[num].len + 1; 
    tree[cur].next[let] = num;

    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    tree[num].num ++;
    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }       
    }
    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
    tree[1].num = tree[2].num = 0; 
}

void dfs( int u ) {
    for( auto it: adj[u] ) {
        dfs(it);
        tree[u].num += tree[it].num;
     }
}
 /*
  * cin >> s;
	int len = strlen(s);

    initTree();
    for (int i = 0; i < len; i++) 
        addLetter(i);
    for(int i=2; i<=num; i++) 
        adj[tree[i].sufflink].push_back(i);
    dfs(1);
    for(int i=3; i<=num; i++)
        A.push_back(make_pair(make_pair(tree[i].l, tree[i].r), tree[i].num));
	//
	for(auto &i: A)
	{
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";  
	}
	// A : count of the palindrome [i.ff.ff,i.ff.ss] = i.ss.
	// // tree[i].len = [i.ff.ss - i.ff.ff + 1] it tells the length of the palin substring.
*/

int cnt[27][MAXN];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	ll n , k; cin >> n >> k;
	cin >> s;

	int len = strlen(s);
	
	initTree();
	for (int i = 0; i < len; i++) 
		addLetter(i);

	for(int i=2; i<=num; i++) 
		adj[tree[i].sufflink].push_back(i);

	dfs(1);
	for(char ch = 'a'; ch <= 'z'; ch++)
		for(int i = 0; i < len; i++)
			if(ch == s[i])
				cnt[ch-'a'][i]++;  

	for(char ch = 'a'; ch <= 'z'; ch++)
		for(int i = 1; i < len; i++)
			cnt[ch-'a'][i] += cnt[ch-'a'][i-1];

	for(int i = 3; i <= num ;i++)
	{
		ll len_palin = tree[i].len;
		ll value;
		ll num_nucleo = 0;
		int l  = tree[i].l;
		int r  = tree[i].r;
		for(char ch = 'a'; ch <= 'z'; ch++)
		{
			int t = (cnt[ch-'a'][r] - cnt[ch-'a'][l-1]);
			if(t >= 1)
				num_nucleo++;
		}
		value = len_palin * num_nucleo;
		if(value >= k)
			ans++;
	}
	cout << ans << "\n";

    return 0;
}

