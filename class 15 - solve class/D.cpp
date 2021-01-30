#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)2e9 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int dpp[12][1005] , need[12], init[12], dou[12] , pro[12] , m;

int call(int idx , int rem)
{
    if(idx > m) return 0;
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = 0;
    for(int i = 0 ; ; i++){
        if(i*need[idx] > init[idx] || i*dou[idx] > rem) break;
        ans = max(ans , call(idx+1,rem - i*dou[idx]) + i*pro[idx]);
    }
    return dpp[idx][rem] = ans;
}

int main()
{
    fastio;
    int n ;
    cin>>n>>m>>dou[0]>>pro[0];
    for(int i = 1 ; i<=m ; i++) cin>>init[i]>>need[i]>>dou[i]>>pro[i];
    memset(dpp,-1,sizeof dpp);
    cout<<call(0,n)<<endl;
    return 0;
}
