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

int n , dpp[105][N] , val[105];

/// "minimum/maximum number of coins needed"

int call(int idx , int tot) /// min
{
    if(tot < 0) return MAX; /// -MAX for max
    if(idx > n){
        if(tot == 0) return 0;
        return MAX; /// -MAX for max
    }
    if(dpp[idx][tot] != -1) return dpp[idx][tot];
    int ans = MAX;
    ans = min(ans , call(idx + 1 , tot));
    ans = min(ans , 1 + call(idx + 1 , tot - val[idx])) ;
    return dpp[idx][tot] = ans;
}

int main()
{
    int tot;
    cin>>n>>tot;
    for(int i = 1 ; i<=n ; i++) cin>>val[i];
    memset(dpp,-1,sizeof dpp);
    int ans = call(1,tot);
    if(ans == MAX) ans = -1; /// not possible ( -MAX for maximum number of coins problem )
    cout<<ans<<endl;
    return 0;
}
