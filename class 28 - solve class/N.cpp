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
#define M ((int)1e6 + 7)
#define MOD ((int)1e9 + 7)
//#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define NN ((int)5e5 + 5)
#define N ((int)25e2 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 17
#define endl "\n"
#define mp make_pair
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

string str;

int cnt[10] , arr[20];


vector < string > vec;

ll backtrack(int rem , ll num , int cmp) /// rem = number of remaining digits
{
    if(cmp == 2) return -1;
    if(rem == 0){
        return num;
    }
    int pos = rem-1;
//    int too;
//    if(num == 0) too = 1;
//    else too = 0;
    for(int i = 9 ; i>=0 ; i--){
        if(cnt[i] > 0){
            cnt[i]--;
            int newcmp = cmp;
            if(cmp == 1){
                if(i < arr[pos]) newcmp = 0;
                else if(i == arr[pos]) newcmp = 1;
                else newcmp = 2;
            }
            ll ans = backtrack(rem - 1 , num*10 + i , newcmp);
            cnt[i]++;
            if(ans != -1) return ans;
        }
    }
    return -1;
}
/// O (18 * 9)

int main()
{
    ll a , b;
    cin>>a>>b;
    int tot = 0;
    while(b > 0){
        int d = b % 10;
        arr[tot++] = d;
        b /= 10;
    }
//    for(int i = tot - 1 ; i>=0 ; i--) cout<<arr[i];
//    cout<<endl;
    int dig = tot;
    tot = 0;
    while(a > 0){
        int d = a % 10;
        cnt[d]++;
        a /= 10;
        tot++;
    }

    ll ans ;

    if(tot == dig) ans = backtrack(tot,0,1); /// 0 = small , 1 = equal , 2 = large
    else ans = backtrack(tot , 0 , 0);
    cout<<ans<<endl;
    return 0;
}
