/*
 * lets use sparse table , dp[i][j] is the index of the first uncovered tile if we put 2^j tiles starting from the tile i 
*/ 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
#include "tile.h"
int n , k , q , m ;
vpi v ;
int dp [300009][35] ;
void init(int N, int K, int Q, int M, std::vector<int> A) {
	n = N , k = K , q = Q , m = M ;
	for ( int i = 0 ; i < m ; i ++ ) {
		v.pb ( { A[i] , i } ) ;
	}
	v.pb ( { n+k+1 , m } ) ;
	dp [m][0] = m ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int idx = ub ( v.begin() , v.end() , mp( A[i] + k  , -1 ) ) - v.begin () ;
		dp [i][0] = v[idx].se ;
	}
	for ( int j = 1 ; j < 35 ; j ++ ) {
		for ( int i = 0 ; i <= m ; i ++ ) {
			dp [i][j] = dp [ dp[i][j-1] ][ j-1 ] ;
		}
	}
}
int getNumberOfSpecialTiles(int L, int R) {
	int l = ub ( v.begin() , v.end() , mp( L , -1 ) ) - v.begin() ;
	int r = ub ( v.begin() , v.end() , mp( R+1 , -1 ) ) - v.begin() ;
	if ( l == r ) return 0 ;
	int ans = 0 ;
	for ( int i = 34 ; i >= 0 ; i -- ) {
		if ( dp [l][i] < r ) {
			l = dp[l][i] ;
			ans += ( 1<<i ) ;
		}
	}
	return ans +1 ;
}
