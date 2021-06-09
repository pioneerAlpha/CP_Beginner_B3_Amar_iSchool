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
#define N ((int)2e3 + 9)
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


int arr[N] , brr[N] , crr[N];

bool match(int Main[] ,int n , int aux[] , int m)
{
    int j = 1;
    for(int i = 1 ; i<=n ; i++){
        while(j <= m && Main[i] != aux[j]) j++;
        if(j > m) return 0;
    }
    return 1;
}


int main()
{
    int t , caseno = 1;
    t = 1;
    while(t--){
        int k , n;
        cin>>k>>n;
        for(int i = 1 ; i<=k ; i++) cin>>arr[i] , arr[i] += arr[i-1]; /// now arr[i] = sum of points of jury 1 to i;
        for(int i = 1 ; i<=n ; i++) cin>>brr[i];
        sort(arr+1 , arr+k+1);
        sort(brr+1 , brr+n+1);
        int ans = 0;
        arr[0] = -MAX;
        for(int i = 1 ; i <= k ; i++){
            if(arr[i] == arr[i-1]) continue;
            int x = brr[1] - arr[i];
            for(int j = 1 ; j<=k ; j++) crr[j] = arr[j] + x;
            if(match(brr , n ,  crr , k)) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
