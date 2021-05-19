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

bool vis[30];

int n , k;

vector < string > vec;

void backtrack(int rem) /// rem = number of remaining characters
{
    /// pos = n-rem;
    if(k == 0) return;
    if(rem == 0){
        cout<<str<<endl;
        k--;
        return;
    }
    for(int i = 0 ; i<n ; i++){ /// 0 -> 'A' , 1 -> 'B'
        if(vis[i] == 0){
            vis[i] = 1;
            str += 'A' + i;
            backtrack(rem - 1);
            str.pop_back();
            vis[i] = 0;
        }
    }
}


int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cin>>n >> k;
        cout<<"Case "<<caseno++<<":\n";
        backtrack(n);
    }
    return 0;
}
