//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)1e9 + 5)
#define MAXP ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((ll)1e5 + 2)
#define pi acos(-1)
#define M ((int)1e6 + 7)
//#define MOD ((int)1e9 + 7)
#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define NN ((int)5e5 + 5)
#define N ((int)1e5 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 18
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

ll tab[N][22], arr[N];
int aux[N];

void sparse(int n , bool flag)
{

    for(int i = 1 ; i<=n ; i++) tab[i][0] = arr[i];
    for(int j = 1 ; j<20 ; j++)
    {
        for(int i = 1 ; i<=n ; i++)
        {
            tab[i][j] = tab[i][j-1];
            int too = i + (1<<(j-1));
            if(too <= n){
                if(flag) tab[i][j] = max(tab[i][j], tab[too][j-1]);
                else tab[i][j] = min(tab[i][j], tab[too][j-1]);
            }
        }
    } /// O (n * logn)

    aux[1] = 0;
    for(int i = 2 ; i<=n ; i++) aux[i] = aux[i/2] + 1;
}

ll query(int l, int r, bool flag)
{
    int len = r - l + 1;
    int i = aux[len]; /// 2^i <= len
    ll ans = tab[l][i];
    int too = r - (1<<i) + 1;
    if(flag) ans = max(ans, tab[too][i]);
    else ans = min(ans, tab[too][i]);
    return ans;
}



int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        sparse(n,0);
        for(int i = 1 ; i<=n ; i++){
            arr[i] = query(i,min(n,i+k-1),0);
        }
        sparse(n,1);
        int q;
        cin>>q;
        cout<<"Case "<<caseno++<<":\n";
        while(q--){
            int L , R;
            cin>>L>>R;
            R -= k - 1;
            if(R < L) cout<<"Impossible\n";
            else cout<<query(L,R,1)<<endl;
        }
    }
    return 0;
}

