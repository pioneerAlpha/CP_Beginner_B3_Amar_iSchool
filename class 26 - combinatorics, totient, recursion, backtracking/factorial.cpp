#include<bits/stdc++.h>
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)2e2 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"


typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


int fac[N] , ifac[N];

int main()
{
    fac[0] = 1;
    for(int i = 1 ; i<N ; i++) fac[i] = 1LL*i*fac[i-1] % MOD;
    ifac[N-1] = bigmod(fac[N-1] , MOD-2);
    for(int i = N-2 ; i>=0 ; i--) ifac[i] = 1LL*(1+i)*ifac[i+1] % MOD;
}

