//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)2e9 + 5)
#define MAXP ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((int)2001)
#define MAX_Y ((int)2001)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
//#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)2e5 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 17
#define endl "\n"
#define mpp make_pair
#define BUCK 105
#define LEF (idx<<1)
#define RIG ((idx<<1)|1)
//#define int ll


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l,r) (rng);
}

int fac[N] , ifac[N];

int bigmom(int n  , int p)
{
    if(p == 0) return 1;
    int ans = bigmom(n , p>>1);
    ans = 1LL*ans*ans % MOD;
    if(p & 1) ans = 1LL*ans*n % MOD;
    return ans;
}

int solve(ll n , int k)
{
    if(n < 0 || k <= 0) return 0;
    if(n + k - 1 >= N) assert(0);
    int ans = 1LL*fac[n+k-1]*ifac[n] % MOD * ifac[k-1] % MOD;
    return ans;
}

int main()
{
    fac[0] = 1;
    for(int i = 1 ; i<N ; i++) fac[i] = 1LL*i*fac[i-1] % MOD;
    ifac[N-1] = bigmom(fac[N-1] , MOD-2);
    for(int i = N-2 ; i>=0 ; i--) ifac[i] = 1LL*(i+1)*ifac[i+1] % MOD;
    fastio;
    int n , c , r;
    cin>>n>>c>>r;
    int ans = 0;
    for(int i = 0 ; i <= n ; i++){
        ll tot = n - i - 1LL*c*(r+1) + min(r , i) , var = c;
        ans += solve(tot , var);
        if(ans >= MOD) ans -= MOD;
    }
    ans = 1LL*ans*(n-c) % MOD;
    if(ans == 0) ans = -1;
    cout<<ans<<endl;
    return 0;
}
