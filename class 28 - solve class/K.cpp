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
#define N ((int)2e6 + 9)
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

int sum[N] , pre[N] , ten[N];

int main()
{
    fastio;
    string str;
    cin>>str;
    int n = str.size();
    str = "0" + str;
    ten[0] = 1 , sum[0] = 0 , pre[0] = 0;
    for(int i = 1 ; i<=n ; i++){
        ten[i] = ten[i-1]*10LL % MOD;
        sum[i] = sum[i-1] + ten[i];
        if(sum[i] >= MOD) sum[i] -= MOD;
        pre[i] = (pre[i-1]*10LL + (str[i] - '0')) % MOD;
    }
    int ans = 0;
    for(int r = 1 ; r <= n ; r++){
        ans = (ans + 1LL*r*pre[r]) % MOD;
    }
    for(int L = 1 ; L <= n ; L++){
        int last = n - L + 1;
        ans = (ans - 1LL*pre[L-1]*sum[last]) % MOD;
        if(ans < 0) ans += MOD;
    }
    cout<<ans<<endl;
    return 0;
}
