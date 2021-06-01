
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
#define MOD ((int)1e7 + 7)
//#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)1e6 + 9)
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


int bigmod(int n , int p)
{
    if(p == 0) return 1;
    int ans = bigmod(n , p>>1);
    ans = 1LL*ans*ans % MOD;
    if(p & 1) ans = 1LL*ans*n % MOD;
    return ans;
}

int arr[N];

int prm[2] , cnt[2];

vector < pair < int , int > > Div[N];

ll sum(int n)
{
    return 1LL*n*(n+1)/2;
}

ll dec(ll n)
{
    while(n % prm[0] == 0){
        cnt[0]--;
        n /= prm[0];
    }
    while(n % prm[1] == 0){
        cnt[1]--;
        n /= prm[1];
    }
    return n;
}

ll inc(ll n)
{
    while(n % prm[0] == 0){
        cnt[0]++;
        n /= prm[0];
    }
    while(n % prm[1] == 0){
        cnt[1]++;
        n /= prm[1];
    }
    return n;
}

int main()
{
    /// problem link: https://codeforces.com/gym/102040 (C)
    fastio;
    sieve(N);
    int a = MOD , phi = MOD;

    for(int p:prime){ /// here MOD is not a prime, there are two prime factors of MOD stored in prm[0] and prm[1];
        if(a % p == 0){
            while(a % p == 0) a /= p;
            phi /= p;
            phi *= p-1;
            if(prm[0] != 0) prm[1] = p;
            else prm[0] = p;

        }
    }

    for(int p:prime){
        for(int i = p ; i<N ; i += p){
            int a = i , cnt = 0;
            while(a % p == 0){
                cnt++;
                a /= p;
            }
            Div[i].push_back({p,cnt});
        }
    } /// O (n * ln (n) )
    set < pair < int , int > > vec; /// sum(c1 + 1)*sum(c2 + 1)*sum(c3 + 1)*...
    ll ans = 1;
    for(int i = 1 ; i<N ; i++){
        for(auto p:Div[i]){
            int a = p.first , c = p.second;
            set < pair < int , int > > :: iterator itt = vec.lower_bound({a,0}); /// a = 5 , c = 0 < (a = 5 , c = 1)
            if(itt != vec.end() && (*itt).first == a){
                int precnt = (*itt).second;
                ll tmp = sum(precnt + 1);
                tmp = dec(tmp);
                ans = ans * bigmod( tmp % MOD , phi-1) % MOD;
                c += (*itt).second;
                vec.erase(itt);
            }
            vec.insert({a,c});
            ll tmp = sum(c + 1);
            tmp = inc(tmp);
            ans = ans*tmp % MOD;
        }
        arr[i] = ans*bigmod(prm[0] , cnt[0]) % MOD * bigmod(prm[1] , cnt[1]) % MOD;

    }


    while(1){
        int n;
        cin>>n;
        if(n == 0) return 0;
        cout<<arr[n]<<endl;
    }
}
