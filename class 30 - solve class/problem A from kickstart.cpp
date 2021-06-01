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
#define N ((int)1e5 + 9)
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

typedef long double ldd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l,r) (rng);
}

int bigmod(int n , int p)
{
    if(p == 0) return 1;
    int ans = bigmod(n , p>>1);
    ans = 1LL*ans*ans % MOD;
    if(p & 1) ans = 1LL*ans*n % MOD;
    return ans;
}


/// ceil (x / y) = (x + y - 1)/y;

int main()
{
    /// problem link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--)
    {
        string giv, pal;
        int n, k;
        cin>>n>>k>>giv;
        int ans = 0;
        for(int i = 0 ; i<(1+n)/2 ; i++)
        {
            char c = giv[i];
            int sml = (c - 'a');
            int rem = (n - 2*(i+1) + 1)/2;
            ans = (ans + 1LL * bigmod(k, rem) * sml) % MOD;
//        if(ans >= MOD) ans -= MOD;
            pal += c;
        }
        string tmp;
        for(int i = 0 ; i<n/2 ; i++)
        {
            tmp += giv[i];
        }
        reverse(tmp.begin(), tmp.end());
        pal = pal + tmp;

        if(pal < giv)
        {
            ans = (ans + 1) % MOD;
        }

        cout<<"Case #"<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
