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
#define N ((int)2e2 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 17
//#define endl "\n"
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
int n;

int vis[30];

string str;

vector < string > vec;

void backtrack(int rem)
{
    if(rem == 0){
        vec.push_back(str); /// n!
        return ;
    }
    for(int i = 0 ; i<n ; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            str += ('a' + i);
            backtrack(rem-1); /// pos = n - rem;
            vis[i] = 0;
            str.pop_back();
        }
    }
} /// n! * n

int main()
{
    /// given n , print all the permutations of the 1st n characters
    cin>>n;
    backtrack(n);
    for(auto a:vec) cout<<a<<endl;
    return 0;
}
