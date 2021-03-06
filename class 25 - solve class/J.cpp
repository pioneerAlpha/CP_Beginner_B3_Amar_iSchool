//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)2e9 + 5)
#define MAXP ((int)47e3 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((ll)1e5 + 2)
#define pi acos(-1)
#define M ((int)1e6 + 7)
#define MOD ((int)1e9 + 7)
//#define MOD ((int)998244353 + 0)
//#define MOD ((int)1811939329 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define NN ((int)5e5 + 5)
#define N ((int)1e6 + 9)
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

///sieve of eratosthenes
int status[(N/32)+2];  /// mx = maximum prime
vector < int > prime;
bool Check(int n,int pos){
    return (bool)(n & (1<<pos));
}
int Set(int n,int pos){
    return (n | (1<<pos));
}
void sieve(int n){
     for(int i = 3; i*i <= n; i += 2){
		 if( Check(status[i>>5],i&31)==0){
	 		 for(int j = i*i; j <= n; j += (i<<1) ){
				 status[j>>5]=Set(status[j>>5],j & 31);
	 		 }
		 }
	 }
	 prime.push_back(2);
	 for(int i=3;i<=n;i+=2) if( Check(status[i>>5],i&31)==0) prime.push_back(i);
}


int next(int n)
{
    while((n & (n-1))) n++;
    return n;
}

int main()
{
    sieve(N);
    fastio;
    int n;
    cin>>n;
    int ans = 1 , tmp = 0;
    vector < int > vec;
    for(int p:prime){
        if(n % p == 0){
            ans *= p;
            int cnt = 0;
            while(n % p == 0){
                n /= p;
                cnt++;
            }
            tmp = max(tmp , next(cnt));
            vec.push_back(cnt);
        }
    }
    int opp = 0;
    for(int a:vec){
        if(a < tmp){
            opp = 1;
            break;
        }
    }
    while(tmp > 1){
        opp++;
        tmp /= 2;
    }
    cout<<ans<<" "<<opp<<endl;
    return 0;
}
