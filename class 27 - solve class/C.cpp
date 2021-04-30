#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define N ((int)1e7 + 5)
#define MAX ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define endl "\n"
#define ll long long
using namespace std;
ll fact[N];
ll i_fact[N];
ll bigmod(ll x, ll p)
{
    if(p == 0) return 1;
    ll ans = bigmod(x,p>>1);
    ans = ans * ans % MOD;
    if(p & 1) ans = ans * x % MOD;
    return ans;
}


int main()
{
    fact[0] = 1;
    for(int i=1; i<N; ++i)
        fact[i]= i*fact[i-1] % MOD;

    i_fact[N-1] = bigmod(fact[N-1],MOD-2);

    for(int i=N-2; i>=0; i--)
        i_fact[i] = i_fact[i+1]*(i+1)%MOD;
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll n,m,k;
        cin >> n >> m >>k;
        if (n < k)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans = bigmod(m,k) * fact[n] % MOD;
        ans = ans * i_fact[k] % MOD;
        ans = ans * i_fact[n-k] % MOD;
        //cout << bigmod(m,k) << " " << fact[n] << " " << i_fact[k] << " " << i_fact[n-k] << endl;
        cout << ans << endl;

    }
    return 0;
}
