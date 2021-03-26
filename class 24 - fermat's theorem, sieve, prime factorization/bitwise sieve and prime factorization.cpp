#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e6 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



//fast io
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

vector < int > prime;
int vis[N/32]; /// N = 1e7

void sieve(int n){
    prime.clear();
    for(int i = 1 ; i<=(n>>5); i++) vis[i] = 0;
    for(int i = 3 ; i*i <= n ; i += 2){
        int r = i >> 5 , c = i & 31;
        if(!( vis[r] & (1<<c)) ){
            for(int j = i*i ; j <= n ; j += (i<<1)){
                r = j >> 5 , c = j & 31;
                vis[r] |= (1<<c);
            }
        }
    }
    prime.push_back(2);
    for(int i = 3 ; i<=n ; i += 2){
        int r = i >> 5 , c = i & 31;
        if(!( vis[r] & (1<<c)) ) prime.push_back(i);
    }
}


int main()
{
    ///

    fastio;
    sieve(N-5);
    ll n; /// n = 58
    cin>>n;
    vector < pair < ll,int > > ans;
    for(int p:prime){ /// 2 , 3 , 5 , 7
        if(p * p > n) break;
        if(n % p == 0){
            int cnt = 0;
            while(n % p == 0){
                n /= p; /// n = 29
                cnt++;
            }
            ans.push_back({p,cnt}); /// = {(2,1)}
        }
    }
    if(n > 1){ /// n = 29
        ans.push_back({n,1});
    }
    return 0;
    /// n = 64 -> 2
}
