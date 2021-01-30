#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int tim[2005] , prc[2005] , n ;

ll dpp[2005][2005] ;

ll call(int idx , int rem)
{
    if(rem <= 0) return 0;
    if(idx > n){
        return MAXL;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    ll ans = min(call(idx+1,rem) , call(idx+1,rem-1-tim[idx]) + prc[idx]);
    return dpp[idx][rem] = ans;
}

int main()
{
    fastio;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>tim[i]>>prc[i];
    memset(dpp,-1,sizeof dpp);
    cout<<call(1,n)<<endl;
    return 0;
}
