#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)1e9 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int n , dpp[1005][1005];

int call(int idx , int rem)
{
    if(rem < 0) return 0;
    if(idx > n){
        if(rem == 0) return 1;
        return 0;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = (call(idx+1,rem) + call(idx + 2 , rem-1) ) % MOD;
    return dpp[idx][rem] = ans;
}

int main()
{
    int k;
    cin>>n>>k;
    memset(dpp,-1,sizeof dpp);
    int ans = call(2,k);
    n--;
    memset(dpp,-1,sizeof dpp);
    ans = (ans + call(3,k-1)) % MOD; /// class e ekhane ektu vul bolsi
    /// chair 1 obosshoi choose korle call(3,k-1) hobe
    cout<<ans<<endl;
    return 0;
}
